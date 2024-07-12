#pragma once

#include <iostream>
#include <map>

#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>

#include "ir/code_genner.hpp"

namespace ddlbx::ir {

struct Variable {
    llvm::Type *type;
    llvm::Value *ptr;
};

struct Type {
    std::string name;
    llvm::Type *type;
    std::unordered_map<std::string, llvm::Type *> nameTypeMap;
};

class CodeGenContext {
public:
    CodeGenContext(llvm::LLVMContext &context, llvm::Module &module)
        : context(context), module(module), builder(context) {
        types["Int"] = {"Int", llvm::Type::getInt32Ty(context), {}};
        types["Flt"] = {"Flt", llvm::Type::getFloatTy(context), {}};
        types["Str"] = {"Str", llvm::Type::getInt8PtrTy(context), {}};
        types["Boo"] = {"Boo", llvm::Type::getInt1Ty(context), {}};
        types["Non"] = {"Non", llvm::Type::getVoidTy(context), {}};
    }

    llvm::Module &getModule() { return module; }

    llvm::LLVMContext &getContext() { return context; }

    llvm::IRBuilder<> &getBuilder() { return builder; }

    llvm::Type *getType(const std::string &name) {
        return types[name].type;
    }

    std::string getTypeName(llvm::Type *type) {
        for (auto &[name, t] : types) {
            if (t.type == type) return t.name;
        }
        return "";
    }

    Variable& getVariable(const std::string &name) {
        return variables[name];
    }

    void setVariable(const std::string &name, Variable variable) {
        variables[name] = variable;
    }

    int getTypeMemberIndex(const std::string &typeName, const std::string &memberName) {
        int i = std::distance(types[typeName].nameTypeMap.begin(),
                              types[typeName].nameTypeMap.find(memberName));
        return i == types[typeName].nameTypeMap.size() ? -1 : i;
    }

private:
    llvm::LLVMContext &context;
    llvm::Module &module;
    llvm::IRBuilder<> builder;

    std::map<std::string, Type> types;
    std::map<std::string, Variable> variables;
};

} // namespace ddlbx::ir