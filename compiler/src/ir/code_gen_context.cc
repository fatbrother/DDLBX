#include "ir/code_gen_context.hpp"

#include <iostream>

#include "ir/node.hpp"

using namespace ddlbx::ir;

llvm::Module &CodeGenContext::getModule() { return module; }

llvm::LLVMContext &CodeGenContext::getContext() { return context; }

llvm::IRBuilder<> &CodeGenContext::getBuilder() { return builder; }

llvm::Type *CodeGenContext::getType(const std::string &name) {
    return types[name].type;
}

void CodeGenContext::addType(const std::string &name, llvm::Type *type, const std::unordered_map<std::string, llvm::Type *> &nameTypeMap) {
    types[name] = {name, type, nameTypeMap};
}

std::string CodeGenContext::getTypeName(llvm::Type *type) {
    for (auto &[name, t] : types) {
        if (t.type == type) return t.name;
    }
    return "";
}

Variable &CodeGenContext::getVariable(const std::string &name) {
    return variables[name];
}

void CodeGenContext::setVariable(const std::string &name, Variable variable) {
    variables[name] = variable;
}

int CodeGenContext::getTypeMemberIndex(const std::string &typeName, const std::string &memberName) {
    int i = std::distance(types[typeName].nameTypeMap.begin(),
                          types[typeName].nameTypeMap.find(memberName));
    return i == types[typeName].nameTypeMap.size() ? -1 : i;
}

void CodeGenContext::registerTemplateObject(std::shared_ptr<NTemplateObjectDeclaration> templateObject) {
    templateObjects[templateObject->name] = templateObject;
}

void CodeGenContext::registerTemplateFunction(std::shared_ptr<NTemplateFunctionDeclaration> templateFunction) {
    templateFunctions[templateFunction->definition->name] = templateFunction;
}

void CodeGenContext::registerTraitMethod(std::shared_ptr<NTraitMethodDeclaration> traitMethod) {
    traitMethods[traitMethod->declaration->definition->name] = traitMethod;
}

std::shared_ptr<NTemplateObjectDeclaration> CodeGenContext::getTemplateObject(const std::string &name) {
    return templateObjects[name];
}

std::shared_ptr<NTemplateFunctionDeclaration> CodeGenContext::getTemplateFunction(const std::string &name) {
    return templateFunctions[name];
}

std::shared_ptr<NTraitMethodDeclaration> CodeGenContext::getTraitMethod(const std::string &name) {
    return traitMethods[name];
}