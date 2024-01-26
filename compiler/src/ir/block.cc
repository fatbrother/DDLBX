#include "ir/block.hpp"

#include "ir/expression.hpp"

namespace ddlbx {
namespace ir {

llvm::BasicBlock* Block::create(const std::unique_ptr<pegtl::parse_tree::node>& root, llvm::LLVMContext& context, llvm::Module& module, llvm::Function* parent = nullptr) {
    assert(root->type == "ddlbx::parser::Block");

    // create block
    llvm::BasicBlock* block = llvm::BasicBlock::Create(context, "block", parent);

    // create builder
    llvm::IRBuilder<> builder(context);
    builder.SetInsertPoint(block);

    std::vector<llvm::Value*> expressions;
    for (const auto& statement : root->children) {
        if (statement->type == "ddlbx::parser::Expression") {
            // create statement
            llvm::Value* val = Expression::create(statement, context, module);
            expressions.push_back(val);
        }
    }

    if (!parent)
        builder.CreateRet(expressions.back());
    else if (parent->getReturnType()->isVoidTy())
        builder.CreateRetVoid();
    else
        builder.CreateRet(expressions.back());

    return block;
}

}  // namespace ir
}  // namespace ddlbx