#include "ir/code_genner.hpp"

namespace ddlbx {
namespace ir {

std::map<std::string, std::function<llvm::Type*(llvm::LLVMContext &)>> CodeGenner::typeMap = {
    {"Int", [](llvm::LLVMContext &context) { return llvm::Type::getInt32Ty(context); }},
    {"Flo", [](llvm::LLVMContext &context) { return llvm::Type::getFloatTy(context); }},
    {"Str", [](llvm::LLVMContext &context) { return llvm::Type::getInt8PtrTy(context); }},
    {"Boo", [](llvm::LLVMContext &context) { return llvm::Type::getInt1Ty(context); }},
    {"Non", [](llvm::LLVMContext &context) { return llvm::Type::getVoidTy(context); }},
};

void CodeGenner::generate(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Block" && node->type != "ddlbx::parser::Program") return;
    if (node->children.empty()) return;

    if (node->type == "ddlbx::parser::Block")
        generateBlock();

    for (const auto& child : node->children) {
        if (child->type == "ddlbx::parser::Function") {
            generateFunctionDeclaration(child);
        }
        if (child->type == "ddlbx::parser::Expression") {
            generateExpression(child);
        }
    }
}

void CodeGenner::generateBlock() {
    llvm::BasicBlock* block = llvm::BasicBlock::Create(context, "entry", parentFunction);
    builder.SetInsertPoint(block);
}

void CodeGenner::generateFunctionDeclaration(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Function") return;

    const auto name = node->children[0]->string();
    const auto& params = node->children[1];
    const auto& ret = node->children[2];
    const auto& body = node->children[3];
    int param_count = params->children.size();

    // Get parameter types
    std::vector<llvm::Type*> paramTypes;
    for (const auto& param : params->children) {
        std::string type = param->children[1]->string();
        paramTypes.push_back(typeMap[type](context));
    }

    // Get return type
    auto retType = typeMap[ret->string()](context);

    // Create function
    llvm::FunctionType* funcType = llvm::FunctionType::get(retType, paramTypes, false);
    auto func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name, module);

    // Set parameter names
    for (int i = 0; i < param_count; i++) {
        func->getArg(i)->setName(params->children[i]->children[0]->string());
    }

    CodeGenner codeGenner(context, module, func);
    codeGenner.generate(body);
}

void CodeGenner::generateExpression(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Expression") return;
}

}  // namespace ir
}  // namespace ddlbx