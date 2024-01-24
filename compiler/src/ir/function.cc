#include "ir/function.hpp"

#include "ir/type.hpp"

namespace ddlbx {
namespace ir {

Function::Function(const std::unique_ptr<pegtl::parse_tree::node>& root, llvm::LLVMContext& context, llvm::Module& module)
    : context(context), module(module), builder(context) {
    assert(root->type == "ddlbx::parser::Function");

    name = root->children[0]->string();
    const auto& params = root->children[1];
    const auto& ret = root->children[2];
    const auto& body = root->children[3];
    int param_count = params->children.size();

    Type typeManager(context);

    // Get parameter types
    for (const auto& param : params->children) {
        std::string type = param->children[1]->string();
        paramTypes.push_back(typeManager.get(type));
    }

    // Get return type
    retType = typeManager.get(ret->string());

    // Create function
    llvm::FunctionType* funcType = llvm::FunctionType::get(retType, paramTypes, false);
    func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name, &module);

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

llvm::Function* Function::get() const {
    return func;
}

std::string Function::getName() const {
    return name;
}

}  // namespace ir
}  // namespace ddlbx