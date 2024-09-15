#include "ir/object.hpp"

#include "ir/code_gen_context.hpp"
#include "utils/logger.hpp"
#include "utils/scope_guard.hpp"

using namespace ddlbx::ir;

llvm::Value* NObjectDeclaration::codeGen(CodeGenContext& context) {
    llvm::StructType* structType = llvm::StructType::create(context.getContext(), name);
    std::unordered_map<std::string, llvm::Type*> nameTypeMap;
    std::vector<llvm::Type*> memberTypes;

    for (const auto& member : members) {
        memberTypes.push_back(member->type->codeGen(context));
        nameTypeMap[member->name] = memberTypes.back();
    }

    structType->setBody(memberTypes);

    context.addType(name, structType, nameTypeMap);

    // create constructor
    genConstructor(context, memberTypes);

    return nullptr;
}

void NObjectDeclaration::genConstructor(CodeGenContext& context, std::vector<llvm::Type*>& argTypes) {
    llvm::StructType* structType = static_cast<llvm::StructType*>(context.getType(name));
    llvm::FunctionType* constructorType = llvm::FunctionType::get(structType, argTypes, false);
    llvm::Function* constructor = llvm::Function::Create(constructorType, llvm::Function::ExternalLinkage, name, context.getModule());
    llvm::BasicBlock* block = llvm::BasicBlock::Create(context.getContext(), "entry", constructor, 0);
    llvm::BasicBlock* currentBlock = context.getBuilder().GetInsertBlock();
    auto scopeGuard = makeGuard([&]() {
        context.getBuilder().SetInsertPoint(currentBlock);
    });

    context.getBuilder().SetInsertPoint(block);
    llvm::Value* structValue = context.getBuilder().CreateAlloca(structType, nullptr, name);

    auto argIt = constructor->arg_begin();
    for (auto it = argTypes.begin(); it != argTypes.end(); it++) {
        llvm::Value* value = &*argIt;
        llvm::Value* ptr = context.getBuilder().CreateStructGEP(structType, structValue, std::distance(argTypes.begin(), it));
        context.getBuilder().CreateStore(value, ptr);
        argIt++;
    }
    context.getBuilder().CreateRet(structValue);
}

llvm::Type* NTemplateObjectDeclaration::codeGen(CodeGenContext& context, std::vector<std::shared_ptr<NType>> templateTypes) {
    std::string originalName = name;

    name += "<";
    for (const auto& type : templateTypes) {
        name += type->name + ",";
    }
    name.pop_back();
    name += ">";

    auto resetNameGuard = makeGuard([&]() {
        name = originalName;
    });

    std::unordered_map<std::string, llvm::Type*> nameTypeMap;
    std::unordered_map<std::string, llvm::Type*> templateNameTypeMap;
    for (int i = 0; i < templates.size(); i++) {
        templateNameTypeMap[templates[i]] = templateTypes[i]->codeGen(context);
    }

    std::vector<llvm::Type*> memberTypes;
    for (const auto& member : members) {
        if (templateNameTypeMap.find(member->type->name) != templateNameTypeMap.end()) {
            memberTypes.push_back(templateNameTypeMap[member->type->name]);
        } else {
            memberTypes.push_back(member->type->codeGen(context));
        }
        nameTypeMap[member->name] = memberTypes.back();
    }

    llvm::StructType* structType = llvm::StructType::create(context.getContext(), name);
    structType->setBody(memberTypes);

    context.addType(name, structType, nameTypeMap);

    // create constructor
    genConstructor(context, memberTypes);

    return structType;
}

llvm::Value* NObjectCreation::codeGen(CodeGenContext& context) {
    std::string fullName = name;
    if (!templateArgs.empty()) {
        fullName += "<";
        for (const auto& arg : templateArgs) {
            fullName += arg + ",";
        }
        fullName.pop_back();
        fullName += ">";
    }

    llvm::BasicBlock* currentBlock = context.getBuilder().GetInsertBlock();
    auto scopeGuard = makeGuard([&]() {
        context.getBuilder().SetInsertPoint(currentBlock);
    });

    llvm::Type* type = context.getType(fullName);
    if (nullptr == type) {
        LOG_INFO("Type \"" + fullName + "\" is not defined, trying to find template object");
        std::shared_ptr<NTemplateObjectDeclaration> templateObject = context.getTemplateObject(name);
        if (nullptr == templateObject) {
            LOG_ERROR("Template object \"" + name + "\" is not defined");
            return nullptr;
        }

        std::vector<std::shared_ptr<NType>> templateArgTypes;
        for (const auto& arg : templateArgs) {
            templateArgTypes.push_back(std::make_shared<NType>(arg));
        }

        type = templateObject->codeGen(context, templateArgTypes);
    }

    context.getBuilder().SetInsertPoint(currentBlock);
    scopeGuard.dismiss();

    std::vector<llvm::Value*> argValues;
    for (const auto& arg : arguments) {
        argValues.push_back(arg->codeGen(context));
        if (argValues.back() == nullptr) {
            LOG_ERROR("Object creation argument error");
            return nullptr;
        }
    }

    llvm::Function* constructor = context.getModule().getFunction(fullName);
    if (nullptr == constructor) {
        LOG_ERROR("Constructor for type \"" + fullName + "\" is not defined");
        return nullptr;
    }

    return context.getBuilder().CreateCall(constructor, argValues);
}
