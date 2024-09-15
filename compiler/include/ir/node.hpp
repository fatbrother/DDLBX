#pragma once

#include <llvm/IR/Value.h>

#include <iostream>
#include <memory>
#include <vector>

#include "ir/code_gen_context.hpp"
#include "utils/logger.hpp"

using namespace ddlbx::utility;

namespace ddlbx::ir {

class Node {
public:
    virtual llvm::Value* codeGen(CodeGenContext& context) = 0;
    virtual std::string getType() { return "Node"; }
};

class NExpression : public Node {
public:
    NExpression() {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override { return nullptr; }
    virtual std::string getType() override { return "NExpression"; }
};

class NStatement : public Node {
public:
    NStatement() {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override { return nullptr; }
    virtual std::string getType() override { return "NStatement"; }
};

class NProgram : public Node {
public:
    std::vector<std::shared_ptr<NStatement>> statements;
    NProgram() {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NProgram"; }
};

class NType {
public:
    std::string name;
    NType(std::string name) : name(name) {}
    virtual llvm::Type* codeGen(CodeGenContext& context);
    virtual std::string getType() { return "NType"; }
};

}  // namespace ddlbx::ir