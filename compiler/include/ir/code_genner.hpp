#pragma once

#include "ir/function_handler.hpp"

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

#include <map>
#include <memory>
#include <string>
#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>

namespace pegtl = tao::pegtl;

namespace ddlbx {
namespace ir {

/**
 * @brief Class for generating LLVM IR code from the parse tree.
 *
 * @details
 * For each block, we should create a new CodeGenner object.
 * The CodeGenner object can maintain the state of the code generation.
 */
class CodeGenner {
public:
    /**
     * @brief Constructor for CodeGenner class.
     *
     * @param context The LLVM context.
     * @param module The LLVM module.
     * @param variableMap The map from variable name to LLVM alloca instruction.
     */
    CodeGenner(llvm::LLVMContext &context, llvm::Module &module)
        : context(context), module(module), builder(context) {}

    /**
     * @brief Generate LLVM IR code from the parse tree.
     *
     * @param root The root node of the parse tree.
     *
     * @details The root node must be of type ddlbx::parser::Block.
     */
    void generate(const std::unique_ptr<pegtl::parse_tree::node> &);

    /**
     * @brief Get the LLVM IR module.
     *
     * @return llvm::Module& The LLVM module.
     */
    llvm::Module &getModule() { return module; }

private:
    llvm::LLVMContext &context;
    llvm::Module &module;
    llvm::IRBuilder<> builder;

    std::map<std::string, llvm::AllocaInst *> variableMap;
    std::map<std::string, llvm::FunctionCallee> functionMap;

    enum class ExpressionType {
        VariableDeclaration,
        Return,
        Statement,
        Conditional,
        Loop,
    };
    static std::map<std::string, std::function<llvm::Type *(llvm::LLVMContext &)>> typeMap;
    static std::map<std::string, int> opPropertyMap;
    static std::map<std::string, llvm::Instruction::BinaryOps> binaryOpMap;
    static std::map<std::string, ExpressionType> expressionTypeMap;

    struct Object {
        std::string name;
        std::vector<std::string> members;
    };
    std::map<std::string, Object> objectMap;

    /**
     * @brief Generate LLVM IR code for a block.
     *
     * @param node The node representing the block.
     */
    llvm::BasicBlock* generateBlock(const std::unique_ptr<pegtl::parse_tree::node> &, FunctionHandler *);

    /**
     * @brief Generate LLVM IR code for a function declaration.
     *
     * @param node The node representing the function declaration.
     */
    void generateFunctionDeclaration(std::string &, std::string &, std::vector<std::pair<std::string, std::string>> &, std::string &, const std::unique_ptr<pegtl::parse_tree::node> &);

    /**
     * @brief Generate LLVM IR code for a external function declaration.
     *
     * @param node The node representing the external function declaration.
     */
    void generateExternalFunctionDeclaration(std::string &, std::vector<std::string> &, std::string &);

    /**
     * @brief Generate LLVM IR code for a expression.
     *
     * @param node The node representing the function declaration.
     */
    void generateExpression(const std::unique_ptr<pegtl::parse_tree::node> &, FunctionHandler *);

    /**
     * @brief Generate LLVM IR code for a identifier.
     *
     * @param name The name of the identifier.
     */
    llvm::Value *generateIdentifier(const std::string &, FunctionHandler *);

    /**
     * @brief Generate LLVM IR code for a member access.
     *
     * @param parent The parent of the member access.
     * @param member The member of the member access.
     */
    llvm::Value *generateMemberAccess(std::vector<std::string> &, FunctionHandler *);

    /**
     * @brief Generate LLVM IR code for a statement.
     *
     * @param node The node representing the statement.
     *
     * @return llvm::Value* The LLVM value.
     */
    llvm::Value *generateStatement(const std::unique_ptr<pegtl::parse_tree::node> &, FunctionHandler *);

    /**
     * @brief Handle the operation of the statement.
     *
     * @param node The node representing the statement.
     */
    llvm::Value *handleOperation(llvm::Value *, llvm::Value *, const std::string &);

    /**
     * @brief Generate LLVM IR code for a value.
     *
     * @param node The node representing the value.
     *
     * @return llvm::Value* The LLVM value.
     */
    llvm::Value *generateValue(const std::unique_ptr<pegtl::parse_tree::node> &);

    /**
     * @brief Generate LLVM IR code for a function call.
     *
     * @param node The node representing the variable function call.
     *
     * @return llvm::Value* The LLVM value.
     */
    llvm::Value *generateFunctionCall(const std::unique_ptr<pegtl::parse_tree::node> &, FunctionHandler *);

    /**
     * @brief Generate LLVM IR code for a variable declaration.
     *
     * @param node The node representing the variable declaration.
     */
    void generateVariableDeclaration(const std::unique_ptr<pegtl::parse_tree::node> &, FunctionHandler *);

    /**
     * @brief Generate LLVM IR code for a object declaration.
     *
     * @param node The node representing the object declaration.
     */
    void generateObjectDeclaration(std::string &, std::vector<std::string> &, std::vector<std::string> &);

    /**
     * @brief Generate LLVM IR code for conditional statement.
     *
     * @param node The node representing the conditional statement.
    */
    void generateConditional(const std::unique_ptr<pegtl::parse_tree::node> &, FunctionHandler *);

    /**
     * @brief Generate LLVM IR code for loop statement.
     *
     * @param node The node representing the loop statement.
     */
    void generateLoop(const std::unique_ptr<pegtl::parse_tree::node> &, FunctionHandler *);
};

}  // namespace ir
}  // namespace ddlbx