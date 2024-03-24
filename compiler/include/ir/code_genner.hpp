#pragma once

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
    std::map<std::string, llvm::Function *> functionMap;

    enum class ExpressionType {
        VariableDeclaration,
        FunctionCall,
        Return,
        Statement,
    };
    static std::map<std::string, std::function<llvm::Type *(llvm::LLVMContext &)>> typeMap;
    static std::map<std::string, int> opPropertyMap;
    static std::map<std::string, llvm::Instruction::BinaryOps> opMap;
    static std::map<std::string, ExpressionType> expressionTypeMap;

    /**
     * @brief Generate LLVM IR code for a block.
     *
     * @param node The node representing the block.
     */
    void generateBlock(const std::unique_ptr<pegtl::parse_tree::node> &, llvm::Function *);

    /**
     * @brief Generate LLVM IR code for a function declaration.
     *
     * @param node The node representing the function declaration.
     */
    void generateFunctionDeclaration(const std::unique_ptr<pegtl::parse_tree::node> &);

    /**
     * @brief Generate LLVM IR code for a external function declaration.
     * 
     * @param node The node representing the external function declaration.
     */
    void generateExternalFunctionDeclaration(const std::unique_ptr<pegtl::parse_tree::node> &);

    /**
     * @brief Generate LLVM IR code for a expression.
     *
     * @param node The node representing the function declaration.
     */
    void generateExpression(const std::unique_ptr<pegtl::parse_tree::node> &, llvm::Function *);

    /**
     * @brief Generate LLVM IR code for a statement.
     *
     * @param node The node representing the statement.
     *
     * @return llvm::Value* The LLVM value.
     */
    llvm::Value *generateStatement(const std::unique_ptr<pegtl::parse_tree::node> &, llvm::Function *);

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
    llvm::Value *generateFunctionCall(const std::unique_ptr<pegtl::parse_tree::node> &, llvm::Function *);

    /**
     * @brief Generate LLVM IR code for a variable declaration.
     *
     * @param node The node representing the variable declaration.
     */
    void generateVariableDeclaration(const std::unique_ptr<pegtl::parse_tree::node> &, llvm::Function *);

    /**
     * @brief Generate LLVM IR code for a object declaration.
     * 
     * @param node The node representing the object declaration.
     */
    void generateObjectDeclaration(const std::unique_ptr<pegtl::parse_tree::node> &);
};

}  // namespace ir
}  // namespace ddlbx