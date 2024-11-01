#include "ir/code_gen_context.hpp"

#include <iostream>

#include "ir/node.hpp"
#include "ir/object.hpp"
#include "ir/function.hpp"

using namespace ddlbx::ir;

llvm::Module &CodeGenContext::getModule() { return module; }

llvm::LLVMContext &CodeGenContext::getContext() { return context; }

llvm::IRBuilder<> &CodeGenContext::getBuilder() { return builder; }

Type& CodeGenContext::getType(const std::string &name) {
    if (types.find(name) != types.end()) {
        return types[name];
    } else if ((false == templateTypeStack.empty()) && (templateTypeStack.top().find(name) != templateTypeStack.top().end())) {
        return templateTypeStack.top()[name];
    } else {
        LOG_DEBUG("Type not found: " + name);
        return types[DDLBX_TYPE_ERR];
    }
}

void CodeGenContext::addType(const std::string &name, llvm::Type *type, const std::unordered_map<std::string, std::string> &memberNameTypeMap) {
    types[name] = {
        .name = name,
        .type = type,
        .memberNameTypeMap = memberNameTypeMap
    };
}

Variable &CodeGenContext::getVariable(const std::string &name) {
    return variables[name];
}

void CodeGenContext::setVariable(const std::string &name, Variable variable) {
    variables[name] = variable;
}

int CodeGenContext::getTypeMemberIndex(const std::string &typeName, const std::string &memberName) {
    int i = std::distance(types[typeName].memberNameTypeMap.begin(),
                          types[typeName].memberNameTypeMap.find(memberName));
    return i == types[typeName].memberNameTypeMap.size() ? -1 : i;
}

void CodeGenContext::registerTemplateObject(std::shared_ptr<NTemplateObjectDeclaration> templateObject) {
    templateObjects[templateObject->name] = templateObject;
}

void CodeGenContext::registerTemplateFunction(std::shared_ptr<NTemplateFunctionDeclaration> templateFunction) {
    templateFunctions[templateFunction->definition->name] = templateFunction;
}

void CodeGenContext::registerTraitMethod(std::shared_ptr<NTraitMethodDeclaration> traitMethod) {
    traitMethods[traitMethod->definition->name] = traitMethod;
}

void CodeGenContext::registerFunction(const std::string &name, const std::string &returnType) {
    functions[name] = {name, returnType};
}

void CodeGenContext::pushTemplateTypeStack() {
    templateTypeStack.push({});
}

void CodeGenContext::registerTemplateType(const std::string &templateName, const std::string &type) {
    templateTypeStack.top()[templateName] = types[type];
}

void CodeGenContext::popTemplateTypeStack() {
    templateTypeStack.pop();
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

Function &CodeGenContext::getFunction(const std::string &name) {
    return functions[name];
}