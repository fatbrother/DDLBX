#pragma once

#include "ir/node.hpp"

#include <string>
#include <memory>

namespace ddlbx::ir {

class NExpressionStatement : public NStatement {
public:
    std::shared_ptr<NExpression> expression;

    NExpressionStatement(std::shared_ptr<NExpression> expression)
        : expression(expression) {
    }

    virtual llvm::Value* codeGen(CodeGenContext& context) override {
        return expression->codeGen(context);
    }
    virtual std::string getType() override { return "NExpressionStatement"; }
};

class NInteger : public NExpression {
public:
    long long value;
    NInteger(long long value) : value(value) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NInteger"; }
};

class NFloat : public NExpression {
public:
    double value;
    NFloat(double value) : value(value) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NFloat"; }
};

class NString : public NExpression {
public:
    std::string value;
    NString(std::string value) : value(value.substr(1, value.size() - 2)) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NString"; }
};

class NBoolean : public NExpression {
public:
    bool value;
    NBoolean(bool value) : value(value) {}
    NBoolean(std::string value);
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NBoolean"; }
};

class NIdentifier : public NExpression {
public:
    std::string name;
    NIdentifier(std::string name) : name(name) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NIdentifier"; }
};

class NAssignment : public NExpression {
public:
    std::shared_ptr<NIdentifier> lhs;
    std::shared_ptr<NExpression> rhs;
    NAssignment(std::shared_ptr<NIdentifier> lhs, std::shared_ptr<NExpression> rhs) : lhs(lhs), rhs(rhs) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NAssignment"; }
};

class NVariableDeclaration : public NExpression {
public:
    std::shared_ptr<NIdentifier> id;
    std::shared_ptr<NExpression> assignmentExpr;
    NVariableDeclaration(std::shared_ptr<NIdentifier> id, std::shared_ptr<NExpression> assignmentExpr = nullptr) : id(id), assignmentExpr(assignmentExpr) {}
    NVariableDeclaration(std::shared_ptr<NAssignment> assignment) : id(assignment->lhs), assignmentExpr(assignment->rhs) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NVariableDeclaration"; }
};

class NVariableDeclarationList : public NExpression {
public:
    std::vector<std::shared_ptr<NVariableDeclaration>> declarations;
    NVariableDeclarationList(std::vector<std::shared_ptr<NVariableDeclaration>> declarations) : declarations(declarations) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NVariableDeclarationList"; }
};

class NBinaryOperator : public NExpression {
public:
    int op;
    std::shared_ptr<NExpression> lhs;
    std::shared_ptr<NExpression> rhs;
    NBinaryOperator(std::shared_ptr<NExpression> lhs, int op, std::shared_ptr<NExpression> rhs) : lhs(lhs), op(op), rhs(rhs) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NBinaryOperator"; }
};

class NUnaryOperator : public NExpression {
public:
    int op;
    std::shared_ptr<NExpression> expr;
    NUnaryOperator(int op, std::shared_ptr<NExpression> expr) : op(op), expr(expr) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NUnaryOperator"; }
};

class NMemberAccess : public NExpression {
public:
    std::shared_ptr<NExpression> parent;
    std::vector<std::shared_ptr<NIdentifier>> ids;
    NMemberAccess(std::shared_ptr<NExpression> parent, const std::vector<std::shared_ptr<NIdentifier>>& ids) : parent(parent), ids(ids) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NMemberAccess"; }
};

}  // namespace ddlbx::ir