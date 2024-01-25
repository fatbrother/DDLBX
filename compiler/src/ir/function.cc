#include "ir/function.hpp"

#include "ir/type.hpp"

namespace ddlbx {
namespace ir {

void Function::create(const std::unique_ptr<pegtl::parse_tree::node>& root, llvm::LLVMContext& context, llvm::Module& module) {
    assert(root->type == "ddlbx::parser::Function");

    llvm::IRBuilder<> builder(context);

    const auto name = root->children[0]->string();
    const auto& params = root->children[1];
    const auto& ret = root->children[2];
    const auto& body = root->children[3];
    int param_count = params->children.size();

    // Get parameter types
    std::vector<llvm::Type*> paramTypes;
    for (const auto& param : params->children) {
        std::string type = param->children[1]->string();
        paramTypes.push_back(Type::get(type, context));
    }

    // Get return type
    const auto retType = Type::get(ret->string(), context);

    // Create function
    llvm::FunctionType* funcType = llvm::FunctionType::get(retType, paramTypes, false);
    auto func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name, &module);

    // Set parameter names
    for (int i = 0; i < param_count; i++) {
        func->getArg(i)->setName(params->children[i]->children[0]->string());
    }

    // Create entry block
    llvm::BasicBlock* entry = llvm::BasicBlock::Create(context, "entry", func);
    builder.SetInsertPoint(entry);

    // Create return instruction
    if (retType->isVoidTy())
        builder.CreateRetVoid();
    else
        builder.CreateRet(llvm::ConstantInt::get(retType, 0));
}

}  // namespace ir
}  // namespace ddlbx