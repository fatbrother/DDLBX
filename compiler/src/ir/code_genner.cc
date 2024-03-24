#include "ir/code_genner.hpp"

#include <stack>
#include <llvm/IR/Verifier.h>

namespace ddlbx {
namespace ir {

std::map<std::string, std::function<llvm::Type*(llvm::LLVMContext&)>> CodeGenner::typeMap = {
    {"Int", [](llvm::LLVMContext& context) { return llvm::Type::getInt32Ty(context); }},
    {"Flo", [](llvm::LLVMContext& context) { return llvm::Type::getFloatTy(context); }},
    {"Str", [](llvm::LLVMContext& context) { return llvm::Type::getInt8PtrTy(context); }},
    {"Boo", [](llvm::LLVMContext& context) { return llvm::Type::getInt1Ty(context); }},
    {"Non", [](llvm::LLVMContext& context) { return llvm::Type::getVoidTy(context); }},
};

std::map<std::string, int> CodeGenner::opPropertyMap = {
    {"+", 1},
    {"-", 1},
    {"*", 2},
    {"/", 2},
    {"%", 2},
};

std::map<std::string, llvm::Instruction::BinaryOps> CodeGenner::opMap = {
    {"+", llvm::Instruction::BinaryOps::Add},
    {"-", llvm::Instruction::BinaryOps::Sub},
    {"*", llvm::Instruction::BinaryOps::Mul},
    {"/", llvm::Instruction::BinaryOps::SDiv},
    {"%", llvm::Instruction::BinaryOps::SRem},
};

std::map<std::string, CodeGenner::ExpressionType> CodeGenner::expressionTypeMap = {
    {"ddlbx::parser::VariableDeclaration", CodeGenner::ExpressionType::VariableDeclaration},
    {"ddlbx::parser::FunctionCall", CodeGenner::ExpressionType::FunctionCall},
    {"ddlbx::parser::Return", CodeGenner::ExpressionType::Return},
    {"ddlbx::parser::Statement", CodeGenner::ExpressionType::Statement},
};

void CodeGenner::generate(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Program") return;
    if (node->children.empty()) return;

    for (const auto& child : node->children) {
        if (child->type == "ddlbx::parser::Function") {
            generateFunctionDeclaration(child);
        }
        if (child->type == "ddlbx::parser::ExternalFunction") {
            generateExternalFunctionDeclaration(child);
        }
        if (child->type == "ddlbx::parser::Object") {
            generateObjectDeclaration(child);
        }
    }
}

void CodeGenner::generateBlock(const std::unique_ptr<pegtl::parse_tree::node> &node, llvm::Function *function = nullptr) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Block") return;

    llvm::BasicBlock* block = llvm::BasicBlock::Create(context, "entry", function);
    builder.SetInsertPoint(block);

    for (const auto& child : node->children) {
        generateExpression(child, function);
    }

    if (block->getTerminator()) return;

    // check if last statement is return
    if (function && function->getReturnType()->isVoidTy()) {
        builder.CreateRetVoid();
    } else {
        int line = node->begin().line;
        throw std::runtime_error(std::to_string(line) + ": last statement should be return");
    }
}

void CodeGenner::generateFunctionDeclaration(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Function") return;

    int idx = 0;
    std::string parentType = "";
    if (node->children[idx]->type == "ddlbx::parser::Type") {
        parentType = node->children[idx++]->string();
    }
    const auto name = (parentType != "" ? parentType + "_" : "") + node->children[idx++]->string();
    const auto& params = node->children[idx++];
    const auto& ret = node->children[idx++];
    const auto& body = node->children[idx++];
    int param_count = params->children.size();

    llvm::Type* structType = nullptr;
    if (parentType != "") {
        structType = typeMap[parentType](context);
    }

    // Get parameter types
    std::vector<llvm::Type*> paramTypes;
    if (structType) {
        paramTypes.push_back(structType->getPointerTo());
        param_count++;
    }
    for (const auto& param : params->children) {
        std::string type = param->children[1]->string();
        paramTypes.push_back(typeMap[type](context));
    }

    // Get return type
    auto retType = typeMap[ret->string()](context);

    // Create function type
    llvm::FunctionType* funcType = llvm::FunctionType::get(retType, paramTypes, false);
    llvm::Function* func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name, &module);

    // Set parameter names
    for (int i = 0; i < param_count; i++) {
        if (i == 0 && structType) {
            func->getArg(i)->setName("this");
            continue;
        }
        func->getArg(i)->setName(params->children[i]->children[0]->string());
    }

    // Generate function body
    generateBlock(body, func);

    // Verify function
    std::string error;
    llvm::raw_string_ostream errorStream = llvm::raw_string_ostream(error);
    if (llvm::verifyFunction(*func, &errorStream)) {
        int line = node->begin().line;
        throw std::runtime_error(std::to_string(line) + ": " + errorStream.str());
    }
}

void CodeGenner::generateExternalFunctionDeclaration(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return;
    if (node->type != "ddlbx::parser::ExternalFunction") return;

    auto name = node->children[0]->string();
    const auto& params = node->children[1];
    const auto& ret = node->children[2];
    int param_count = params->children.size();

    auto func = module.getOrInsertFunction(name, typeMap[ret->string()](context));
}

void CodeGenner::generateExpression(const std::unique_ptr<pegtl::parse_tree::node>& node, llvm::Function* function = nullptr) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Expression") return;

    const auto& child = node->children[0];
    switch (expressionTypeMap[std::string{child->type}]) {
        case ExpressionType::VariableDeclaration:
            generateVariableDeclaration(child, function);
            break;
        case ExpressionType::FunctionCall:
            generateFunctionCall(child, function);
            break;
        case ExpressionType::Return:
            builder.CreateRet(generateStatement(child->children[0], function));
            break;
        case ExpressionType::Statement:
            generateStatement(child, function);
            break;
    }
}

llvm::Value* CodeGenner::generateStatement(const std::unique_ptr<pegtl::parse_tree::node>& node, llvm::Function* function = nullptr) {
    if (!node) return nullptr;
    if (node->type != "ddlbx::parser::Statement") return nullptr;

    std::stack<llvm::Value*> valueStack;
    std::stack<std::string> opStack;

    for (const auto& child : node->children) {
        if (child->type == "ddlbx::parser::Bracket")
            valueStack.push(generateStatement(child->children[0], function));
        if (child->type == "ddlbx::parser::Value")
            valueStack.push(generateValue(child));
        if (child->type == "ddlbx::parser::FunctionCall")
            valueStack.push(generateFunctionCall(child, function));
        if (child->type == "ddlbx::parser::Identifier") {
            std::string name = child->string();
            llvm::Value* var = nullptr;

            if (function) {
                for (auto& arg : function->args()) {
                    if (arg.getName() == name) {
                        var = &arg;
                        break;
                    }
                }
            }
            if (!var && variableMap.find(name) != variableMap.end()) {
                llvm::AllocaInst * alloca = variableMap[name];
                llvm::Type* type = alloca->getAllocatedType();
                var = builder.CreateLoad(type, alloca);
                // check if variable is struct ptr
                if (var->getType()->isPointerTy()) {
                    // TODO: support struct ptr
                    throw std::runtime_error("struct ptr is not supported yet");
                }
            }
            if (!var) {
                int line = child->begin().line;
                throw std::runtime_error(std::to_string(line) + ": " + name + " is not defined");
            }

            valueStack.push(var);
        }
        if (child->type == "ddlbx::parser::Operator") {
            std::string op = child->string();
            if (opStack.empty()) {
                opStack.push(op);
                continue;
            }
            while (!opStack.empty() && opPropertyMap[opStack.top()] >= opPropertyMap[op]) {
                llvm::Value* rhs = valueStack.top();
                valueStack.pop();
                llvm::Value* lhs = valueStack.top();
                valueStack.pop();
                llvm::Instruction::BinaryOps op = opMap[opStack.top()];
                opStack.pop();
                valueStack.push(builder.CreateBinOp(op, lhs, rhs));
            }
            opStack.push(op);
        }
    }

    while (!opStack.empty()) {
        llvm::Value* rhs = valueStack.top();
        valueStack.pop();
        llvm::Value* lhs = valueStack.top();
        valueStack.pop();
        llvm::Instruction::BinaryOps op = opMap[opStack.top()];
        opStack.pop();
        valueStack.push(builder.CreateBinOp(op, lhs, rhs));
    }

    if (!valueStack.empty())
        return valueStack.top();
    return nullptr;
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
        std::string str = value->string().substr(1, value->string().size() - 2);  // remove quotes
        result = llvm::ConstantDataArray::getString(context, str);
    }
    else if (value->type == "ddlbx::parser::Boolean") {
        if (value->string() == "true") {
            result = llvm::ConstantInt::getTrue(context);
        }
        else if (value->string() == "false") {
            result = llvm::ConstantInt::getFalse(context);
        }
        else if (value->string() == "maybe") {
            result = llvm::UndefValue::get(typeMap["Boo"](context));
        }
    }

    return result;
}

llvm::Value* CodeGenner::generateFunctionCall(const std::unique_ptr<pegtl::parse_tree::node>& node, llvm::Function* function = nullptr) {
    if (!node) return nullptr;
    if (node->type != "ddlbx::parser::FunctionCall") return nullptr;

    auto name = node->children[0]->string();

    bool isConstructor = false;
    if (typeMap.find(name) != typeMap.end())
        isConstructor = true;

    std::vector<llvm::Value*> argValues;
    for (size_t i = 1; i < node->children.size(); i++) {
        const auto& value = node->children[i];
        llvm::Value* val = generateStatement(value, function);
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

void CodeGenner::generateVariableDeclaration(const std::unique_ptr<pegtl::parse_tree::node>& node, llvm::Function* function = nullptr) {
    if (!node) return;
    if (node->type != "ddlbx::parser::VariableDeclaration") return;

    const auto& name = node->children[0]->string();
    const auto& value = node->children[1];

    llvm::Value* val = generateStatement(value, function);
    
    llvm::AllocaInst* alloca = builder.CreateAlloca(val->getType(), nullptr, name);
    builder.CreateStore(val, alloca);
    variableMap[name] = alloca;
}

void CodeGenner::generateObjectDeclaration(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Object") return;

    std::string name = node->children[0]->string();
    const auto& members = node->children[1];

    llvm::StructType* structType = llvm::StructType::create(context, name);
    std::vector<llvm::Type*> memberTypes;
    for (const auto& member : members->children) {
        std::string type = member->children[1]->string();
        memberTypes.push_back(typeMap[type](context));
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

}  // namespace ir
}  // namespace ddlbx
