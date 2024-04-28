

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

#include <map>
#include <vector>
#include <memory>
#include <string>
#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>

namespace pegtl = tao::pegtl;

namespace ddlbx{
namespace ir{

class FunctionHandler{
public:

    FunctionHandler() : exp(""), function(nullptr) {}

    /**
     * @brief Create a new LLVM Function.
     * 
     * @param funcType The type of the function.
    */
    llvm::Function* createFunction(llvm::FunctionType* funcType, std::string name, llvm::Module &module){
        function = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name, &module);
        return function;
    }
    
    /**
     * @brief Get the LLVM Function.
     * 
     * @return llvm::Function& The LLVM Function.
     */
    llvm::Function *getFunction() { return function; }


    /**
     * @brief Insert a new variable alloca into the variable alloca map.
     * 
     * @param variableName The name of the variable.
     * @param alloca The alloca of the variable.
    */
    void insertVariable(std::string variableName, llvm::AllocaInst* alloca){
        variableMap[variableName] = alloca;
    }

    /**
     * @brief Get the alloca of a variable.
     * 
     * @param variableName The name of the variable.
     * 
     * @return llvm::Value* The alloca of the variable.
    */
    llvm::AllocaInst* getVariableAlloca(std::string variableName){
        llvm::AllocaInst* alloca = nullptr;
        if(variableMap.find(variableName) != variableMap.end()){
            alloca = variableMap[variableName];
        }
        return alloca;
    }

    /**
     * @brief Get the llvm::Value of a variable in llvm::function
     * 
     * @param variableName The name of the variable.
     * 
     * @return llvm::Value* The llvm::Value of the variable.
    */
    llvm::Value* getVariableValue(std::string variableName){
        llvm::Value* var = nullptr;
        if(function){
            for(auto& arg : function->args()){
                if(arg.getName() == variableName){
                    var = &arg;
                    return var;
                }
            }
        }
        return var;
    }

    /**
     * @brief Delete a alloca from the variable map.
     * 
     * @param variableName The name of the variable.
     * 
     * @return bool True if the variable was deleted, false otherwise.
    */
    bool deleteVariable(std::string variableName){
        if(variableMap.find(variableName) != variableMap.end()){
            variableMap.erase(variableName);
            return true;
        }
        return false;
    }

    /**
     * @brief Insert a new function into the function map.
     * 
     * @param functionName The name of the function.
     * @param function The function.
     * 
    */
    void insertFunction(std::string functionName, FunctionHandler function){
        childfuncMap[functionName] = function;
    }

    /**
     * @brief Get the function from the function map.
     * 
     * @param functionName The name of the function.
     * 
     * @return Function The function.
    */
    FunctionHandler getChlidFunc(std::string functionName){
        return childfuncMap[functionName];
    }

    /**
     * @brief Delete a function from the function map.
     * 
     * @param functionName The name of the function.
     * 
     * @return bool True if the function was deleted, false otherwise.
    */
    bool deleteChildFunc(std::string functionName){
        if(childfuncMap.find(functionName) != childfuncMap.end()){
            childfuncMap.erase(functionName);
            return true;
        }
        return false;
    }

private:
    llvm::Function *function;
    std::string exp;


    std::map<std::string, llvm::AllocaInst*> variableMap;
    std::map<std::string, FunctionHandler> childfuncMap;
};
}
}