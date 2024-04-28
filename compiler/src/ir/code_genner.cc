#include "ir/code_genner.hpp"

#include <llvm/IR/Verifier.h>

#include <iostream>
#include <stack>

namespace ddlbx {
namespace ir {

std::map<std::string, std::function<llvm::Type*(llvm::LLVMContext&)>> CodeGenner::typeMap = {
    {"Int", [](llvm::LLVMContext& context) { return llvm::Type::getInt32Ty(context); }},
    {"Flo", [](llvm::LLVMContext& context) { return llvm::Type::getFloatTy(context); }},
    {"Str", [](llvm::LLVMContext& context) { return llvm::Type::getInt8PtrTy(context); }},
    {"Boo", [](llvm::LLVMContext& context) { return llvm::Type::getInt1Ty(context); }},
    {"Ptr", [](llvm::LLVMContext& context) { return llvm::Type::getInt8PtrTy(context); }},
    {"Non", [](llvm::LLVMContext& context) { return llvm::Type::getVoidTy(context); }},
};

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

void CodeGenner::generate(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Program") return;
    if (node->children.empty()) return;

    for (const auto& child : node->children) {
        if (child->type == "ddlbx::parser::Function") {
            int idx = 0;
            std::string parentTypeName = "";
            if (child->children[idx]->type == "ddlbx::parser::Type") {
                parentTypeName = child->children[idx++]->string();
            }
            std::string name = (parentTypeName != "" ? parentTypeName + "_" : "") + child->children[idx++]->string();
            const auto& params = child->children[idx++];
            std::string retTypeName = child->children[idx++]->string();
            const auto& body = child->children[idx++];

            std::vector<std::pair<std::string, std::string>> paramNamesAndTypeNames;
            if (parentTypeName != "") {
                paramNamesAndTypeNames.push_back({"this", parentTypeName});
            }
            for (const auto& param : params->children) {
                std::string paramName = param->children[0]->string();
                std::string typeName = param->children[1]->string();
                paramNamesAndTypeNames.push_back({paramName, typeName});
            }

            generateFunctionDeclaration(name, parentTypeName, paramNamesAndTypeNames, retTypeName, body);
        }
        if (child->type == "ddlbx::parser::ExternalFunction") {
            auto name = child->children[0]->string();
            const auto& params = child->children[1];
            std::string retTypeName = child->children[2]->string();

            std::vector<std::string> paramTypeNames;
            for (const auto& param : params->children) {
                std::string typeName = param->children[1]->string();
                paramTypeNames.push_back(typeName);
            }

            generateExternalFunctionDeclaration(name, paramTypeNames, retTypeName);
        }
        if (child->type == "ddlbx::parser::Object") {
            std::string name = child->children[0]->string();
            const auto& members = child->children.back();
            std::vector<std::string> memberTypeNames;
            std::vector<std::string> memberNames;

            for (const auto& member : members->children) {
                std::string typeName = member->children[1]->string();
                std::string memberName = member->children[0]->string();
                memberNames.push_back(memberName);
                memberTypeNames.push_back(typeName);
            }

            generateObjectDeclaration(name, memberTypeNames, memberNames);
        }
    }
}

llvm::BasicBlock* CodeGenner::generateBlock(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler& funcHandler) {
    if (!node) return nullptr;
    if (node->type != "ddlbx::parser::Block") return nullptr;
    
    llvm::Function* func = nullptr;    //for new class
    func = funcHandler.getFunction();    //for new class
    
    llvm::BasicBlock* block = llvm::BasicBlock::Create(context, "entry", func);
    builder.SetInsertPoint(block);

    for (const auto& child : node->children) {
        generateExpression(child, funcHandler);        //for new class
    }

    return block;
}

void CodeGenner::generateFunctionDeclaration(std::string& name, std::string& parentType, std::vector<std::pair<std::string, std::string>>& paramNamesAndTypeNames, std::string& retTypeName, const std::unique_ptr<pegtl::parse_tree::node>& body) {
    llvm::Type* structType = nullptr;
    if (parentType != "") {
        structType = typeMap[parentType](context);
    }

    // Get parameter types
    std::vector<llvm::Type*> paramTypes;
    for (const auto& paramName : paramNamesAndTypeNames)
        paramTypes.push_back(typeMap[paramName.second](context));

    // Get return type
    auto retType = typeMap[retTypeName](context);

    // Create function type
    llvm::FunctionType* funcType = llvm::FunctionType::get(retType, paramTypes, false);
    FunctionHandler funcHandler;
    llvm::Function* func = funcHandler.createFunction(funcType, name, module);     //for new class
    //llvm::Function* func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name, &module);

    // Set parameter names
    for (int i = 0; i < func->arg_size(); i++) {
        func->getArg(i)->setName(paramNamesAndTypeNames[i].first);
    }

    // Generate function body
    generateBlock(body, funcHandler);

    // Check if last block has terminator
    llvm::BasicBlock* lastBlock = builder.GetInsertBlock();
    if (!lastBlock->getTerminator() && retType->isVoidTy()) {
        builder.CreateRetVoid();
    }

    // Verify function
    std::string error;
    llvm::raw_string_ostream errorStream = llvm::raw_string_ostream(error);
    if (llvm::verifyFunction(*func, &errorStream)) {
        throw std::runtime_error(errorStream.str());
    }
}

void CodeGenner::generateExternalFunctionDeclaration(std::string& name, std::vector<std::string>& paramTypeNames, std::string& retTypeName) {
    // Get parameter types
    std::vector<llvm::Type*> paramTypes;
    for (const auto& paramTypeName : paramTypeNames)
        paramTypes.push_back(typeMap[paramTypeName](context));

    // Get return type
    auto retType = typeMap[retTypeName](context);

    // Create function type
    llvm::FunctionType* funcType = llvm::FunctionType::get(retType, paramTypes, false);
    auto func = module.getOrInsertFunction(name, funcType);
    functionMap[name] = func;
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
        if (child->type == "ddlbx::parser::FunctionCall")
            valueStack.push(generateFunctionCall(child, funcHandler));
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
                int memberIndex = -1;
                Object object = objectMap[structType->getName().str()];
                for (int i = 0; i < object.members.size(); i++) {
                    if (object.members[i] == name) {
                        memberIndex = i;
                        break;
                    }
                }
                if (memberIndex == -1) {
                    throw std::runtime_error(name + " is not a member of " + structType->getName().str());
                }
                parentValue = builder.CreateExtractValue(parentValue, memberIndex);
            }
        }
        if (child->type == "ddlbx::parser::FunctionCall") {
            std::string name = parentValue == nullptr ? 
                child->children[0]->string() : 
                parentValue->getType()->getStructName().str() + "_" + child->children[0]->string();
            std::vector<llvm::Value*> argValues;
            argValues.push_back(parentValue);
            for (size_t i = 1; i < child->children.size(); i++) {
                const auto& value = child->children[i];
                llvm::Value* val = generateStatement(value, function);
                argValues.push_back(val);
            }
            llvm::Function* targetFunction = module.getFunction(name);
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
        result = llvm::ConstantInt::get(typeMap["Int"](context), std::stoi(value->string()));
    }
    else if (value->type == "ddlbx::parser::Float") {
        result = llvm::ConstantFP::get(typeMap["Flo"](context), std::stof(value->string()));
    }
    else if (value->type == "ddlbx::parser::String") {
        result = builder.CreateGlobalString(value->string());
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

llvm::Value* CodeGenner::generateFunctionCall(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler& funcHandler) {
    if (!node) return nullptr;
    if (node->type != "ddlbx::parser::FunctionCall") return nullptr;

    auto name = node->children[0]->string();

    bool isConstructor = false;
    if (typeMap.find(name) != typeMap.end())
        isConstructor = true;

    std::vector<llvm::Value*> argValues;
    for (size_t i = 1; i < node->children.size(); i++) {
        const auto& value = node->children[i];
        llvm::Value* val = generateStatement(value, funcHandler);
        argValues.push_back(val);
    }

    if (isConstructor)
        name += "_factory";
    llvm::Function* targetFunction = module.getFunction(name);

    // check if parameter is matching
    if (targetFunction->arg_size() != argValues.size()) {
        int line = node->begin().line;
        throw std::runtime_error(std::to_string(line) + ": " + name + " parameter size is not matching");
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

void CodeGenner::generateObjectDeclaration(std::string& name, std::vector<std::string>& memberTypeNames, std::vector<std::string>& memberNames) {
    llvm::StructType* structType = llvm::StructType::create(context, name);

    Object object;
    object.name = name;
    object.members = memberNames; 
    objectMap[name] = object;

    std::vector<llvm::Type*> memberTypes;
    for (const auto& typeName : memberTypeNames) {
        memberTypes.push_back(typeMap[typeName](context));
    }
    structType->setBody(memberTypes);
    module.getOrInsertGlobal(name, structType);
    typeMap[name] = [structType](llvm::LLVMContext& context) { return structType; };

    // create constructor
    llvm::FunctionType* funcType = llvm::FunctionType::get(structType, memberTypes, false);
    llvm::Function* func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name + "_factory", &module);
    llvm::BasicBlock* block = llvm::BasicBlock::Create(context, "entry", func);
    builder.SetInsertPoint(block);
    llvm::Value* thisPtr = builder.CreateAlloca(structType, nullptr, "this");
    int i = 0;
    for (auto& arg : func->args()) {
        llvm::Value* ptr = builder.CreateStructGEP(structType, thisPtr, i++);
        builder.CreateStore(&arg, ptr);
    }
    llvm::Value* ret = builder.CreateLoad(structType, thisPtr);
    builder.CreateRet(ret);
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
        llvm::Value* start = llvm::ConstantInt::get(typeMap["Int"](context), 0);
        llvm::Value* end = llvm::ConstantInt::get(typeMap["Int"](context), 0);
        llvm::Value* increment = llvm::ConstantInt::get(typeMap["Int"](context), 1);

        for (const auto& child : condition->children) {
            if (child->type == "ddlbx::parser::RangeStart")
                start = generateStatement(child->children[0], funcHandler);
            if (child->type == "ddlbx::parser::RangeEnd")
                end = generateStatement(child->children[0], funcHandler);
            if (child->type == "ddlbx::parser::RangeStep")
                increment = generateStatement(child->children[0], funcHandler);
        }

        llvm::AllocaInst* idx = builder.CreateAlloca(typeMap["Int"](context), nullptr, idxName);
        builder.CreateStore(start, idx);
        variableMap[idxName] = idx;

        if (child->type == "ddlbx::parser::Block")
            loopBlock = generateBlock(child, funcHandler);
        else if (child->type == "ddlbx::parser::Expression") {
            loopBlock = llvm::BasicBlock::Create(context, "loop", funcHandler.getFunction());
            builder.SetInsertPoint(loopBlock);
            generateExpression(child, funcHandler);
        }
        llvm::Value* currentIdx = builder.CreateLoad(typeMap["Int"](context), idx);
        llvm::Value* nextIdx = builder.CreateAdd(currentIdx, increment);
        builder.CreateStore(nextIdx, idx);
        builder.CreateBr(conditionBlock);

        builder.SetInsertPoint(currentBlock);
        builder.CreateBr(conditionBlock);
        builder.SetInsertPoint(conditionBlock);
        llvm::Value* cond = builder.CreateICmpSLT(builder.CreateLoad(typeMap["Int"](context), idx), end);
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
