#include "ir/code_genner.hpp"

#include <llvm/IR/Verifier.h>

#include <iostream>
#include <stack>

namespace ddlbx {
namespace ir {

std::map<std::string, int> CodeGenner::opPropertyMap = {
    {"and", 1},
    {"or", 1},
    {"==", 2},
    {"!=", 2},
    {"<", 2},
    {"<=", 2},
    {">", 2},
    {">=", 2},
    {"+", 3},
    {"-", 3},
    {"*", 4},
    {"/", 4},
    {"%", 4},
    {"!", 5},
};

std::map<std::string, llvm::Instruction::BinaryOps> CodeGenner::binaryOpMap = {
    {"+", llvm::Instruction::BinaryOps::Add},
    {"-", llvm::Instruction::BinaryOps::Sub},
    {"*", llvm::Instruction::BinaryOps::Mul},
    {"/", llvm::Instruction::BinaryOps::SDiv},
    {"%", llvm::Instruction::BinaryOps::SRem},
};

std::map<std::string, CodeGenner::ExpressionType> CodeGenner::expressionTypeMap = {
    {"ddlbx::parser::VariableDeclaration", CodeGenner::ExpressionType::VariableDeclaration},
    {"ddlbx::parser::Return", CodeGenner::ExpressionType::Return},
    {"ddlbx::parser::Statement", CodeGenner::ExpressionType::Statement},
    {"ddlbx::parser::Conditional", CodeGenner::ExpressionType::Conditional},
    {"ddlbx::parser::Loop", CodeGenner::ExpressionType::Loop},
    {"ddlbx::parser::Assignment", CodeGenner::ExpressionType::Assignment},
};

CodeGenner::CodeGenner(llvm::LLVMContext& context, llvm::Module& module)
    : context(context), module(module), builder(context) {
    objectMap["Int"] = std::make_shared<ObjectHandler>("Int", std::map<std::string, std::string>(), llvm::Type::getInt32Ty(context));
    objectMap["Flt"] = std::make_shared<ObjectHandler>("Flt", std::map<std::string, std::string>(), llvm::Type::getFloatTy(context));
    objectMap["Str"] = std::make_shared<ObjectHandler>("Str", std::map<std::string, std::string>(), llvm::Type::getInt8PtrTy(context));
    objectMap["Ptr"] = std::make_shared<ObjectHandler>("Ptr", std::map<std::string, std::string>(), llvm::Type::getInt8PtrTy(context));
    objectMap["Boo"] = std::make_shared<ObjectHandler>("Boo", std::map<std::string, std::string>(), llvm::Type::getInt1Ty(context));
    objectMap["Non"] = std::make_shared<ObjectHandler>("Non", std::map<std::string, std::string>(), llvm::Type::getVoidTy(context));

    generateExternalFunctionDeclaration("print", {"Str"}, "Non");
    generateExternalFunctionDeclaration("println", {"Str"}, "Non");
    generateExternalFunctionDeclaration("read", {}, "Str");
    generateExternalFunctionDeclaration("readln", {}, "Str");
    generateExternalFunctionDeclaration("Int_toString", {"Int"}, "Str");
    generateExternalFunctionDeclaration("Flt_toString", {"Flt"}, "Str");
    generateExternalFunctionDeclaration("Str_toInt", {"Str"}, "Int");
    generateExternalFunctionDeclaration("Str_toFlt", {"Str"}, "Flt");
    generateExternalFunctionDeclaration("Str_substring", {"Str", "Int", "Int"}, "Str");
}

void CodeGenner::generate(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Program") return;
    if (node->children.empty()) return;

    for (auto& child : node->children) {
        if (child->type == "ddlbx::parser::Function") {
            std::shared_ptr<FunctionHandler> funcHandler = std::make_shared<FunctionHandler>(child);
            if (funcHandler->getParentTypeName() != "") {
                std::string parentType = funcHandler->getParentTypeName();
                objectMap[parentType]->insertMethod(funcHandler);
            } else {
                generateFunctionDeclaration(*funcHandler);
            }
        }
        if (child->type == "ddlbx::parser::ExternalFunction") {
            int idx = 0;
            std::string parentType = "";
            if (child->children[idx]->type == "ddlbx::parser::Type") {
                parentType = child->children[idx++]->string();
            }
            std::string name = (parentType != "" ? parentType + "_" : "") + child->children[idx++]->string();
            const auto& params = child->children[idx++];
            std::string retTypeName = child->children[idx++]->string();

            std::vector<std::string> paramTypeNames;
            if (parentType != "") paramTypeNames.push_back(parentType);
            for (const auto& param : params->children) {
                std::string typeName = param->children[1]->string();
                paramTypeNames.push_back(typeName);
            }

            generateExternalFunctionDeclaration(name, paramTypeNames, retTypeName);
        }
        if (child->type == "ddlbx::parser::Object") {
            std::shared_ptr<ObjectHandler> objectHandler = std::make_shared<ObjectHandler>(child);
            objectMap[objectHandler->getName()] = objectHandler;
        }
    }
}

llvm::BasicBlock* CodeGenner::generateBlock(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler& funcHandler) {
    if (!node) return nullptr;
    if (node->type != "ddlbx::parser::Block") return nullptr;

    llvm::Function* func = funcHandler.getFunction();
    
    llvm::BasicBlock* block = llvm::BasicBlock::Create(context, "entry", func);
    builder.SetInsertPoint(block);

    for (const auto& child : node->children) {
        generateExpression(child, funcHandler);
    }

    return block;
}

void CodeGenner::generateFunctionDeclaration(FunctionHandler& funcHandler) {
    llvm::Function* func = funcHandler.createFunction(module, objectMap);

    auto& body = funcHandler.getBody();

    generateBlock(body, funcHandler);

    auto lastBlock = builder.GetInsertBlock();
    if (!lastBlock->getTerminator()) {
        if (func->getReturnType()->isVoidTy()) {
            builder.CreateRetVoid();
        }
        else {
            int line = body->begin().line;
            throw std::runtime_error(std::to_string(line) + ": Function must return a value");
        }
    }

    // Verify function
    std::string error;
    llvm::raw_string_ostream errorStream = llvm::raw_string_ostream(error);
    if (llvm::verifyFunction(*func, &errorStream)) {
        throw std::runtime_error(errorStream.str());
    }
}

void CodeGenner::generateExternalFunctionDeclaration(const std::string& name, const std::vector<std::string>& paramTypeNames, const std::string& retTypeName) {
    // Get parameter types
    std::vector<llvm::Type*> paramTypes;
    for (const auto& paramTypeName : paramTypeNames)
        paramTypes.push_back(objectMap[paramTypeName]->getType());

    // Get return type
    auto retType = objectMap[retTypeName]->getType();

    // Create function type
    llvm::FunctionType* funcType = llvm::FunctionType::get(retType, paramTypes, false);
    auto func = module.getOrInsertFunction(name, funcType);
}

void CodeGenner::generateExpression(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler &funcHandler) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Expression") return;

    const auto& child = node->children[0];
    switch (expressionTypeMap[std::string{child->type}]) {
        case ExpressionType::VariableDeclaration:
            generateVariableDeclaration(child, funcHandler);
            break;
        case ExpressionType::Return:
            builder.CreateRet(generateStatement(child->children[0], funcHandler));
            break;
        case ExpressionType::Statement:
            generateStatement(child, funcHandler);
            break;
        case ExpressionType::Conditional:
            generateConditional(child, funcHandler);
            break;
        case ExpressionType::Loop:
            generateLoop(child, funcHandler);
            break;
        case ExpressionType::Assignment:
            generateAssignment(child, funcHandler);
            break;
    }
}

llvm::Value* CodeGenner::generateStatement(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler &funcHandler) {
    if (!node) return nullptr;
    if (node->type != "ddlbx::parser::Statement") return nullptr;

    std::stack<llvm::Value*> valueStack;
    std::stack<std::string> opStack;

    for (const auto& child : node->children) {
        if (child->type == "ddlbx::parser::Bracket")
            valueStack.push(generateStatement(child->children[0], funcHandler));
        if (child->type == "ddlbx::parser::Value")
            valueStack.push(generateValue(child));
        if (child->type == "ddlbx::parser::FunctionCall") {
            auto name = child->children[0]->string();
            int idx = 1;
            std::vector<std::string> templateNames;
            if (child->children.size() > 1 && child->children[1]->type == "ddlbx::parser::Template") {
                for (const auto& templateNode : child->children[1]->children)
                    templateNames.push_back(templateNode->string());
                idx++;
            }

            if (objectMap.find(name) != objectMap.end()) {
                std::string constructorName = name;
                for (auto templateName : templateNames)
                    name += "_" + templateName;
                name += "_factory";

                if (!module.getFunction(constructorName + "_factory")) {
                    std::map<std::string, std::string> templateMap;
                    for (int i = 0; i < objectMap[constructorName]->getTemplateList().size(); i++) {
                        templateMap[objectMap[constructorName]->getTemplateList()[i]] = templateNames[i];
                    }
                    objectMap[constructorName]->createObject(context, module, objectMap, templateMap);
                }
            }

            valueStack.push(generateFunctionCall(name, templateNames, child->children[idx]->children, funcHandler));
        }
        if (child->type == "ddlbx::parser::MemberAccess")
            valueStack.push(generateMemberAccess(child, funcHandler));
        if (child->type == "ddlbx::parser::Identifier") {
            std::string name = child->string();
            try {
                auto var = funcHandler.getVariableValue(name);
                if (!var) {
                    auto alloca = funcHandler.getVariableAlloca(name);
                    if (!alloca) throw std::runtime_error(name + " is not defined");
                    var = builder.CreateLoad(alloca->getAllocatedType(), alloca);
                }
                valueStack.push(var);
            } catch (std::exception& e) {
                int line = child->begin().line;
                throw std::runtime_error(std::to_string(line) + ": " + e.what());
            }
        }
        if (child->type == "ddlbx::parser::BinaryOperator" ||
            child->type == "ddlbx::parser::ComparisonOperator" ||
            child->type == "ddlbx::parser::LogicalOperator") {
            std::string comingOp = child->string();
            while (!opStack.empty() && opPropertyMap[opStack.top()] >= opPropertyMap[comingOp]) {
                llvm::Value* rhs = valueStack.top();
                valueStack.pop();
                llvm::Value* lhs = valueStack.top();
                valueStack.pop();
                std::string op = opStack.top();
                opStack.pop();

                try {
                    llvm::Value* result = handleOperation(lhs, rhs, op);
                    valueStack.push(result);
                }
                catch (std::exception& e) {
                    int line = child->begin().line;
                    throw std::runtime_error(std::to_string(line) + ": " + e.what());
                }
            }
            opStack.push(comingOp);
        }
    }

    while (!opStack.empty()) {
        llvm::Value* rhs = valueStack.top();
        valueStack.pop();
        llvm::Value* lhs = valueStack.top();
        valueStack.pop();
        std::string op = opStack.top();
        opStack.pop();

        try {
            llvm::Value* result = handleOperation(lhs, rhs, op);
            valueStack.push(result);
        }
        catch (std::exception& e) {
            int line = node->begin().line;
            throw std::runtime_error(std::to_string(line) + ": " + e.what());
        }
    }

    if (!valueStack.empty()) {
        return valueStack.top();
    }
    return nullptr;
}

llvm::Value* CodeGenner::generateAssignment(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler& funcHandler) {
    if (!node) return nullptr;
    if (node->type != "ddlbx::parser::Assignment") return nullptr;

    const auto& lhs = node->children[0];
    const auto& rhs = node->children[1];

    llvm::Value* lhsValue = nullptr;
    if (lhs->type == "ddlbx::parser::Identifier") {
        std::string name = lhs->string();
        lhsValue = funcHandler.getVariableValue(name);
        if (!lhsValue) {
            lhsValue = funcHandler.getVariableAlloca(name);
        }
    }

    llvm::Value* rhsValue = generateStatement(rhs, funcHandler);

    return builder.CreateStore(rhsValue, lhsValue);
}

llvm::Value* CodeGenner::generateMemberAccess(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler& function) {
    llvm::Value* parentValue = nullptr;

    for (auto &child : node->children) {
        if (child->type == "ddlbx::parser::Value") {
            if (!parentValue) {
                parentValue = generateValue(child);
            } else {
                int line = child->begin().line;
                throw std::runtime_error(std::to_string(line) + ": Value is not a member of " + parentValue->getType()->getStructName().str());
            }
        }
        if (child->type == "ddlbx::parser::Identifier") {
            std::string name = child->string();
            if (!parentValue) {
                parentValue = function.getVariableValue(name);
                if (!parentValue) {
                    llvm::AllocaInst* alloca = function.getVariableAlloca(name);
                    if (!alloca) {
                        int line = child->begin().line;
                        throw std::runtime_error(std::to_string(line) + ": " + name + " is not defined");
                    }
                    parentValue = builder.CreateLoad(alloca->getAllocatedType(), alloca);
                }
            } else {
                llvm::StructType* structType = llvm::cast<llvm::StructType>(parentValue->getType());
                auto object = objectMap[structType->getName().str()];
                int memberIndex = object->getMemberIndex(name);
                if (memberIndex == -1) {
                    throw std::runtime_error(name + " is not a member of " + structType->getName().str());
                }
                parentValue = builder.CreateExtractValue(parentValue, memberIndex);
            }
        }
        if (child->type == "ddlbx::parser::FunctionCall") {
            std::string parrntObjectName = "";
            if (parentValue) {
                for (const auto& [typeName, object] : objectMap) {
                    if (object->getType() == parentValue->getType()) {
                        parrntObjectName = typeName;
                        break;
                    }
                }
            }
            std::string name = parrntObjectName == "" ? 
                child->children[0]->string() : 
                parrntObjectName + "_" + child->children[0]->string();

            if (name == "sizeof") {
                if (child->children[1]->children.size() != 1) {
                    int line = child->begin().line;
                    throw std::runtime_error(std::to_string(line) + ": sizeof function must have one argument");
                }
                llvm::Type* type = objectMap[child->children[1]->children[0]->string()]->getType();
                parentValue = llvm::ConstantInt::get(objectMap["Int"]->getType(), type->getPrimitiveSizeInBits().getFixedValue() / 8);
                continue;
            }

            std::vector<llvm::Value*> argValues;
            for (const auto& arg : child->children[1]->children) {
                llvm::Value* val = generateStatement(arg, function);
                argValues.push_back(val);
            }

            if (parentValue != nullptr) {
                argValues.push_back(parentValue);
            }
            llvm::Function* targetFunction = module.getFunction(name);
            if (!targetFunction) {
                int line = child->begin().line;
                throw std::runtime_error(std::to_string(line) + ": " + name + " is not defined");
            }

            if (targetFunction->arg_size() != argValues.size()) {
                int line = child->begin().line;
                throw std::runtime_error(std::to_string(line) + ": " + name + " parameter size is not matching");
            }
            parentValue = builder.CreateCall(targetFunction, argValues);
        }
    }

    return parentValue;
}

llvm::Value* CodeGenner::handleOperation(llvm::Value* lhs, llvm::Value* rhs, const std::string& op) {
    llvm::Value* result = nullptr;
    if (op == "==")
        result = builder.CreateICmpEQ(lhs, rhs);
    else if (op == "!=")
        result = builder.CreateICmpNE(lhs, rhs);
    else if (op == "<")
        result = builder.CreateICmpSLT(lhs, rhs);
    else if (op == "<=")
        result = builder.CreateICmpSLE(lhs, rhs);
    else if (op == ">")
        result = builder.CreateICmpSGT(lhs, rhs);
    else if (op == ">=")
        result = builder.CreateICmpSGE(lhs, rhs);
    else if (op == "and")
        result = builder.CreateAnd(lhs, rhs);
    else if (op == "or")
        result = builder.CreateOr(lhs, rhs);
    else if (op == "=")
        result = builder.CreateStore(rhs, lhs); 
    else {
        llvm::Instruction::BinaryOps binaryOp = binaryOpMap[op];
        result = builder.CreateBinOp(binaryOp, lhs, rhs);
    }
    return result;
}

llvm::Value* CodeGenner::generateValue(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return nullptr;
    if (node->type != "ddlbx::parser::Value") return nullptr;

    llvm::IRBuilder<> builder(context);

    llvm::Value* result = nullptr;

    const auto& value = node->children[0];
    if (value->type == "ddlbx::parser::Integer") {
        result = llvm::ConstantInt::get(objectMap["Int"]->getType(), std::stoi(value->string()));
    }
    else if (value->type == "ddlbx::parser::Float") {
        result = llvm::ConstantFP::get(objectMap["Flt"]->getType(), std::stof(value->string()));
    }
    else if (value->type == "ddlbx::parser::String") {
        std::string str = value->string();
        str = str.substr(1, str.size() - 2);
        llvm::Constant *strConstant = llvm::ConstantDataArray::getString(context, str);
        llvm::GlobalVariable *strGlobal = new llvm::GlobalVariable(module, strConstant->getType(), true, llvm::GlobalValue::PrivateLinkage, strConstant);
        result = builder.CreatePointerCast(strGlobal, objectMap["Str"]->getType());
    }
    else if (value->type == "ddlbx::parser::Boolean") {
        if (value->string() == "true") {
            result = llvm::ConstantInt::getTrue(context);
        }
        else if (value->string() == "false") {
            result = llvm::ConstantInt::getFalse(context);
        }
        else if (value->string() == "maybe") {
            bool random = rand() % 2;
            result = llvm::ConstantInt::get(context, llvm::APInt(1, random));
        }
    }

    return result;
}

llvm::Value* CodeGenner::generateFunctionCall(std::string &name, std::vector<std::string> &templateNames, std::vector<std::unique_ptr<pegtl::parse_tree::node>> &args, FunctionHandler& funcHandler) {        
    if (name == "sizeof") {
        if (args.size() != 1) {
            int line = funcHandler.getBody()->begin().line;
            throw std::runtime_error(std::to_string(line) + ": sizeof function must have one argument");
        }
        llvm::Type* type = objectMap[args[0]->string()]->getType();
        return llvm::ConstantInt::get(objectMap["Int"]->getType(), type->getPrimitiveSizeInBits().getFixedValue() / 8);
    }

    std::vector<llvm::Value*> argValues;
    for (const auto& arg : args) {
        llvm::Value* val = generateStatement(arg, funcHandler);
        argValues.push_back(val);
    }

    llvm::Function* targetFunction = module.getFunction(name);
    if (!targetFunction) {
        throw std::runtime_error(name + " function is not defined");
    }

    if (targetFunction->arg_size() != argValues.size()) {
        throw std::runtime_error(name + " function parameter size is not matching");
    }

    return builder.CreateCall(targetFunction, argValues);
}

void CodeGenner::generateVariableDeclaration(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler& funcHandler) {
    if (!node) return;
    if (node->type != "ddlbx::parser::VariableDeclaration") return;

    const auto& name = node->children[0]->string();
    const auto& value = node->children[1];

    llvm::Value* val = generateStatement(value, funcHandler);

    llvm::AllocaInst* alloca = builder.CreateAlloca(val->getType(), nullptr, name);
    builder.CreateStore(val, alloca);
    funcHandler.insertVariable(name, alloca);
}

void CodeGenner::generateConditional(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler& funcHandler) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Conditional") return;

    const auto& condition = node->children[0];
    const auto& child = node->children[1];

    llvm::Value* cond = generateStatement(condition, funcHandler);
    if (!cond->getType()->isIntegerTy(1)) {
        cond = builder.CreateICmpNE(cond, llvm::ConstantInt::get(cond->getType(), 0));
    }

    llvm::Function* func = funcHandler.getFunction();

    llvm::BasicBlock* currentBlock = builder.GetInsertBlock();

    llvm::BasicBlock* thenBlock = nullptr;
    llvm::BasicBlock* elseBlock = llvm::BasicBlock::Create(context, "else", func);
    llvm::BasicBlock* continueBlock = llvm::BasicBlock::Create(context, "continue", func);

    if (child->type == "ddlbx::parser::Block") {
        thenBlock = generateBlock(child, funcHandler);
    }
    else if (child->type == "ddlbx::parser::Expression") {
        thenBlock = llvm::BasicBlock::Create(context, "then", func);
        builder.SetInsertPoint(thenBlock);
        generateExpression(child, funcHandler);
    }

    // check if current block has terminator
    if (!builder.GetInsertBlock()->getTerminator()) {
        builder.CreateBr(continueBlock);
    }

    builder.SetInsertPoint(currentBlock);
    builder.CreateCondBr(cond, thenBlock, elseBlock);

    builder.SetInsertPoint(elseBlock);
    // TODO: support else if
    // builder.CreateRet(llvm::UndefValue::get(function->getReturnType()));

    builder.CreateBr(continueBlock);
    builder.SetInsertPoint(continueBlock);
}

void CodeGenner::generateLoop(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler& funcHandler) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Loop") return;

    const auto& condition = node->children[0];
    const auto& child = node->children[1];

    llvm::Function* func = funcHandler.getFunction();

    llvm::BasicBlock* currentBlock = builder.GetInsertBlock();
    llvm::BasicBlock* loopBlock = nullptr;
    llvm::BasicBlock* conditionBlock = llvm::BasicBlock::Create(context, "condition", func);
    llvm::BasicBlock* continueBlock = llvm::BasicBlock::Create(context, "continue", func);
    if (condition->type == "ddlbx::parser::LoopRange") {
        std::string idxName = condition->children[0]->string();
        llvm::Value* start = llvm::ConstantInt::get(objectMap["Int"]->getType(), 0);
        llvm::Value* end = llvm::ConstantInt::get(objectMap["Int"]->getType(), 0);
        llvm::Value* increment = llvm::ConstantInt::get(objectMap["Int"]->getType(), 1);

        for (const auto& child : condition->children) {
            if (child->type == "ddlbx::parser::RangeStart")
                start = generateStatement(child->children[0], funcHandler);
            if (child->type == "ddlbx::parser::RangeEnd")
                end = generateStatement(child->children[0], funcHandler);
            if (child->type == "ddlbx::parser::RangeStep")
                increment = generateStatement(child->children[0], funcHandler);
        }

        llvm::AllocaInst* idx = builder.CreateAlloca(objectMap["Int"]->getType(), nullptr, idxName);
        builder.CreateStore(start, idx);

        if (child->type == "ddlbx::parser::Block")
            loopBlock = generateBlock(child, funcHandler);
        else if (child->type == "ddlbx::parser::Expression") {
            loopBlock = llvm::BasicBlock::Create(context, "loop", funcHandler.getFunction());
            builder.SetInsertPoint(loopBlock);
            generateExpression(child, funcHandler);
        }
        llvm::Value* currentIdx = builder.CreateLoad(objectMap["Int"]->getType(), idx);
        llvm::Value* nextIdx = builder.CreateAdd(currentIdx, increment);
        builder.CreateStore(nextIdx, idx);
        builder.CreateBr(conditionBlock);

        builder.SetInsertPoint(currentBlock);
        builder.CreateBr(conditionBlock);
        builder.SetInsertPoint(conditionBlock);
        llvm::Value* cond = builder.CreateICmpSLT(builder.CreateLoad(objectMap["Int"]->getType(), idx), end);
        builder.CreateCondBr(cond, loopBlock, continueBlock);
    }
    if (condition->type == "ddlbx::parser::Statement") {
        builder.CreateBr(conditionBlock);
        builder.SetInsertPoint(conditionBlock);

        llvm::Value* cond = generateStatement(condition, funcHandler);
        if (!cond->getType()->isIntegerTy(1)) {
            cond = builder.CreateICmpNE(cond, llvm::ConstantInt::get(cond->getType(), 0));
        }

        loopBlock = generateBlock(child, funcHandler);
        builder.CreateCondBr(cond, loopBlock, continueBlock);

        builder.SetInsertPoint(continueBlock);

        builder.CreateBr(conditionBlock);
    }

    builder.SetInsertPoint(continueBlock);
}

}  // namespace ir
}  // namespace ddlbx
