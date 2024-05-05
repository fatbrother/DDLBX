#pragma once

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

#include <map>
#include <memory>
#include <string>
#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>
#include <vector>

namespace pegtl = tao::pegtl;

namespace ddlbx {
namespace ir {

class FunctionHandler {
public:
    FunctionHandler() = delete;

    FunctionHandler(const std::unique_ptr<pegtl::parse_tree::node>& node);

    /**
     * @brief Create a new LLVM Function.
     *
     * @param funcType The type of the function.
     */
    llvm::Function* createFunction(llvm::Module& module, std::map<std::string, llvm::Type*>& typeMap);

    /**
     * @brief Insert Parameter into the function.
     *
     * @param paramName The name of the parameter.
     * @param typeName The type of the parameter.
     */
    void insertParam(std::string paramName, std::string typeName) {
        paramNamesAndTypeNames.push_back({paramName, typeName});
    }

    /**
     * @brief Remove a parameter from the function.
     */
    void popParam() { paramNamesAndTypeNames.pop_back(); }

    /**
     * @brief Get the function name.
     *
     * @return std::string The name of the function.
     */
    std::string getName() { return name; }

    /**
     * @brief Get the parent type name.
     *
     * @return std::string The name of the parent type.
     */
    std::string getParentTypeName() { return parentTypeName; }

    /**
     * @brief Get the LLVM Function.
     *
     * @return llvm::Function& The LLVM Function.
     */
    llvm::Function* getFunction() { return function; }

    /**
     * @brief Get the body of the function.
     *
     * @return std::shared_ptr<tao::pegtl::parse_tree::node>& The body of the function.
     */
    std::unique_ptr<pegtl::parse_tree::node>& getBody() { return body; }

    /**
     * @brief Insert a new variable alloca into the variable alloca map.
     *
     * @param variableName The name of the variable.
     * @param alloca The alloca of the variable.
    */
    void insertVariable(std::string , llvm::AllocaInst*);

    /**
     * @brief Get the alloca of a variable.
     *
     * @param variableName The name of the variable.
     *
     * @return llvm::Value* The alloca of the variable.
    */
    llvm::AllocaInst* getVariableAlloca(std::string);

    /**
     * @brief Get the llvm::Value of a variable in llvm::function
     *
     * @param variableName The name of the variable.
     *
     * @return llvm::Value* The llvm::Value of the variable.
    */
    llvm::Value* getVariableValue(std::string);

    /**
     * @brief Delete a alloca from the variable map.
     *
     * @param variableName The name of the variable.
     *
     * @return bool True if the variable was deleted, false otherwise.
    */
    bool deleteVariable(std::string);

private:
    std::string name;
    std::string parentTypeName;
    std::string retTypeName;
    std::vector<std::pair<std::string, std::string>> paramNamesAndTypeNames;
    std::unique_ptr<pegtl::parse_tree::node>& body;
    llvm::Function* function;
    std::map<std::string, llvm::AllocaInst*> variableMap;
};

}  // namespace ir
}  // namespace ddlbx