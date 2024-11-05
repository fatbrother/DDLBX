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
    bool isAsignable = false;
    virtual Value codeGenValue(CodeGenContext& context) = 0;
    virtual Value codeGenLoacation(CodeGenContext& context) {
        if (false == isAsignable) {
            LOG_ERROR("Node is not asignable");
            return Value::null();
        }

        LOG_ERROR("Node codeGenLoacation not implemented");
        return Value::null();
    }
    virtual std::string getType() { return "Node"; }
};

class NExpression : public Node {
public:
    NExpression() {}
    virtual Value codeGenValue(CodeGenContext& context) override { return Value::null(); }
    virtual std::string getType() override { return "NExpression"; }
};

class NStatement : public Node {
public:
    NStatement() {}
    virtual Value codeGenValue(CodeGenContext& context) override { return Value::null(); }
    virtual std::string getType() override { return "NStatement"; }
};

class NProgram : public Node {
public:
    std::vector<std::shared_ptr<NStatement>> statements;
    NProgram() {}
    virtual Value codeGenValue(CodeGenContext& context) override;
    virtual std::string getType() override { return "NProgram"; }
};

class NType {
public:
    std::string name;
    NType(std::string name) : name(name) {}
    virtual Type& codeGenValue(CodeGenContext& context);
    virtual std::string getType() { return "NType"; }
};

}  // namespace ddlbx::ir