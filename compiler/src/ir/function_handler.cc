#include "ir/function_handler.hpp"

#include <llvm/IR/Verifier.h>

#include <iostream>

namespace ddlbx {
namespace ir {
    llvm::Function* FunctionHandler::createFunction(llvm::FunctionType* funcType, std::string name, llvm::Module &module){
        llvm::Function* function = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name, &module);
        return function;
    }

    void FunctionHandler::insertVariable(std::string variableName, llvm::AllocaInst* alloca){
        variableMap[variableName] = alloca;
    }

    llvm::AllocaInst* FunctionHandler::getVariableAlloca(std::string variableName){
        llvm::AllocaInst* alloca = nullptr;
        if(variableMap.find(variableName) != variableMap.end()){
            alloca = variableMap[variableName];
        }
        return alloca;
    }

    llvm::Value* FunctionHandler::getVariableValue(std::string variableName){
        llvm::Value* value = nullptr;
        if(variableMap.find(variableName) != variableMap.end()){
            value = variableMap[variableName];
        }
        return value;
    }

    bool FunctionHandler::deleteVariable(std::string variableName){
        if(variableMap.find(variableName) != variableMap.end()){
            variableMap.erase(variableName);
            return true;
        }
        return false;
    }
}
}