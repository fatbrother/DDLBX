#include "ir/function.hpp"

#include "utils/logger.hpp"
#include "utils/scope_guard.hpp"

using namespace ddlbx::ir;

llvm::Value* NFunctionDefinition::codeGen(CodeGenContext& context) {
    std::vector<llvm::Type*> argTypes;

    for (auto arg : arguments) {
        argTypes.push_back(arg->type->codeGen(context));
        if (argTypes.back() == nullptr) {
            LOG_ERROR("Function argument type generation failed");
            return nullptr;
        }
    }

    llvm::FunctionType* functionType = llvm::FunctionType::get(retType->codeGen(context), argTypes, false);
    llvm::Function* function = llvm::Function::Create(functionType, llvm::Function::ExternalLinkage, name.c_str(), context.getModule());

    return function;
}

llvm::Value* NFunctionDeclaration::codeGen(CodeGenContext& context) {
    llvm::Function* function = context.getModule().getFunction(this->definition->name.c_str());

    if (!function) {
        function = static_cast<llvm::Function*>(this->definition->codeGen(context));

        if (!function) {
            LOG_ERROR("Function " + this->definition->name + " not found");
            return nullptr;
        }
    }

    llvm::BasicBlock* block = llvm::BasicBlock::Create(context.getContext(), "entry", function, 0);
    llvm::BasicBlock* currentBlock = context.getBuilder().GetInsertBlock();
    context.getBuilder().SetInsertPoint(block);
    auto scopeGuard = makeGuard([&]() {
        context.getBuilder().SetInsertPoint(currentBlock);
    });

    auto argIt = this->definition->arguments.begin();
    for (auto it = function->arg_begin(); it != function->arg_end(); it++) {
        it->setName((*argIt)->name.c_str());

        llvm::Type* type = (*argIt)->type->codeGen(context);
        if (it->getType() != type) {
            LOG_ERROR("Function argument type error");
            return nullptr;
        }

        llvm::AllocaInst* inst = context.getBuilder().CreateAlloca(type, nullptr, (*argIt)->name.c_str());
        context.getBuilder().CreateStore(&*it, inst);
        context.setVariable((*argIt)->name, {type, inst});
        argIt++;
    }

    this->block->codeGen(context);

    if (block->getTerminator() == nullptr) {
        if (function->getReturnType()->isVoidTy()) {
            context.getBuilder().CreateRetVoid();
        } else {
            LOG_ERROR("Function must return a value");
            return nullptr;
        }
    }

    return function;
}

llvm::Value* NTemplateFunctionDeclaration::codeGen(CodeGenContext& context, std::vector<std::string> templateArgs) {
    std::shared_ptr<NTemplateFunctionDefinition> definition = std::dynamic_pointer_cast<NTemplateFunctionDefinition>(this->definition);

    context.pushTemplateTypeStack();
    auto popStackGuard = makeGuard([&]() {
        context.popTemplateTypeStack();
    });

    for (int i = 0; i < templateArgs.size(); i++) {
        LOG_DEBUG("Registering template type " + definition->templates[i] + " as " + templateArgs[i]);
        context.registerTemplateType(definition->templates[i], templateArgs[i]);
    }

    std::string originalName = definition->name;

    definition->name += "<";
    for (const auto& arg : templateArgs) {
        definition->name += arg + ",";
    }
    definition->name.pop_back();
    definition->name += ">";
    auto resetNameGuard = makeGuard([&]() {
        definition->name = originalName;
    });

    auto func = NFunctionDeclaration::codeGen(context);

    return func;
}

llvm::Value* NFunctionCall::codeGen(CodeGenContext& context) {
    if (name == "sizeof" && !parent) {
        if (arguments.size() != 1) {
            LOG_ERROR("Function \"sizeof\" expects 1 argument, but " + std::to_string(arguments.size()) + " were provided");
            return nullptr;
        }
        llvm::Value* value = arguments[0]->codeGen(context);
        llvm::Type* type = value->getType();
        return llvm::ConstantInt::get(type, type->getPrimitiveSizeInBits() / 8);
    }

    std::vector<llvm::Value*> argValues;
    for (const auto& arg : arguments) {
        argValues.push_back(arg->codeGen(context));
        if (argValues.back() == nullptr) {
            LOG_ERROR("Function argument error");
            return nullptr;
        }
    }

    std::string fullName = name;
    llvm::Value* parentValue = nullptr;
    if (parent) {
        parentValue = parent->codeGen(context);
        if (!parentValue) {
            LOG_ERROR("Parent value error");
            return nullptr;
        }
        llvm::Type* parentType = parentValue->getType();
        std::string parentTypeName = context.getTypeName(parentType);

        fullName = parentTypeName + "." + name;
    }

    if (false == templateArgs.empty()) {
        fullName += "<";
        for (const auto& arg : templateArgs) {
            fullName += arg + ",";
        }
        fullName.pop_back();
        fullName += ">";
    }

    llvm::Function* targetFunction = context.getModule().getFunction(fullName);
    if (!targetFunction) {
        LOG_DEBUG("Function " + fullName + " not found");

        if (false == templateArgs.empty()) {
            LOG_DEBUG("Trying to find template function " + name);
            std::shared_ptr<NTemplateFunctionDeclaration> templateFunction = context.getTemplateFunction(name);
            if (nullptr == templateFunction) {
                LOG_ERROR("Template function " + name + " not found");
                return nullptr;
            }

            targetFunction = static_cast<llvm::Function*>(templateFunction->codeGen(context, templateArgs));
        } else {
            LOG_DEBUG("Trying to find trait method " + name);
            std::shared_ptr<NTraitMethodDeclaration> traitMethod = context.getTraitMethod(name);
            if (nullptr == traitMethod) {
                LOG_ERROR("Trait method " + name + " not found");
                return nullptr;
            }

            llvm::Type* parentType = parentValue->getType();
            std::string parentTypeName = context.getTypeName(parentType);

            targetFunction = static_cast<llvm::Function*>(traitMethod->codeGen(context, parentTypeName));
        }

        if (!targetFunction) {
            LOG_ERROR("Trait method " + name + " creation failed");
            return nullptr;
        }
    }

    if (parentValue) {
        argValues.push_back(parentValue);
    }

    if (targetFunction->arg_size() != argValues.size()) {
        LOG_ERROR("Function " + fullName + " expects " + std::to_string(targetFunction->arg_size()) + " arguments, but " + std::to_string(argValues.size()) + " were provided");
        return nullptr;
    }

    return context.getBuilder().CreateCall(targetFunction, argValues);
}

llvm::Value* NMethodDeclaration::codeGen(CodeGenContext& context) {
    if (nullptr == context.getType(name)) {
        LOG_ERROR("Type \"" + name + "\" is not defined");
        return nullptr;
    }

    llvm::StructType* structType = llvm::cast<llvm::StructType>(context.getType(name));
    declaration->definition->arguments.push_back(std::make_shared<NArgument>(std::make_shared<NType>(name), "this"));
    declaration->definition->name = name + "." + declaration->definition->name;

    return declaration->codeGen(context);
}

llvm::Value* NTraitMethodDeclaration::codeGen(CodeGenContext& context, std::string parentName) {
    name = parentName;

    return NMethodDeclaration::codeGen(context);
}