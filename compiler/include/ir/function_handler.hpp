#pragma once

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

class Function{
public:

    Function()
        : function(nullptr) {}

    /**
     * @brief Create a new LLVM Function.
     * 
     * @param funcType The type of the function.
    */
    void createFunction(llvm::FunctionType* funcType, std::string name, llvm::Module &module){
        function = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name, &module);
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
     * @param varibleName The name of the variable.
     * @param alloca The alloca of the variable.
    */
    void insertVaribleAlloca(std::string varibleName, llvm::AllocaInst* alloca){
        VaribleAlloca[varibleName] = alloca;
    }

    /**
     * @brief Get the alloca of a variable.
     * 
     * @param varibleName The name of the variable.
     * 
     * @return llvm::AllocaInst* The alloca of the variable.
    */
    llvm::AllocaInst* getVaribleAlloca(std::string varibleName){
        return VaribleAlloca[varibleName];
    }

    /**
     * @brief Delete a alloca from the variable map.
     * 
     * @param varibleName The name of the variable.
     * 
     * @return bool True if the variable was deleted, false otherwise.
    */
    bool deleteVaribleAlloca(std::string varibleName){
        if(VaribleAlloca.find(varibleName) != VaribleAlloca.end()){
            VaribleAlloca.erase(varibleName);
            return true;
        }
        return false;
    }

private:
    llvm::Function *function;

    std::map<std::string, llvm::AllocaInst*> VaribleAlloca;

    //not sure if this is the way to store the varibles
    std::map<std::string, int> intVarible;
    std::map<std::string, float> floatVarible;
    std::map<std::string, std::string> stringVarible;
    std::map<std::string, bool> boolVarible;
    
    


};
}
}