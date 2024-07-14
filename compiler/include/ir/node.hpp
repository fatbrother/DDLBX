#pragma once

#include <llvm/IR/Value.h>

#include <iostream>
#include <memory>
#include <vector>

#include "ir/code_gen_context.hpp"

namespace ddlbx::ir {

class NStatement;
class NExpression;
class NVariableDeclaration;

class Node {
public:
    // virtual ~Node() {}
    virtual llvm::Value* codeGen(CodeGenContext& context) = 0;
    virtual std::string getType() { return "Node"; }
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

class NBlock : public NStatement {
public:
    std::vector<NStatement*> statements;
    NBlock() {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NBlock"; }
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

class NVariableDeclarationList : public NExpression {
public:
    std::vector<std::shared_ptr<NVariableDeclaration>> declarations;
    NVariableDeclarationList(std::vector<std::shared_ptr<NVariableDeclaration>> declarations) : declarations(declarations) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NVariableDeclarationList"; }
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

class NArgument : public NExpression {
public:
    std::shared_ptr<NType> type;
    std::shared_ptr<NIdentifier> id;
    NArgument(std::shared_ptr<NType> type, std::shared_ptr<NIdentifier> id) : type(type), id(id) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override { return nullptr; }
    virtual std::string getType() override { return "NArgument"; }
};

class NFunctionDefinition : public NStatement {
public:
    std::shared_ptr<NType> retType;
    std::shared_ptr<NIdentifier> id;
    std::vector<std::shared_ptr<NArgument>> arguments;
    NFunctionDefinition(std::shared_ptr<NType> type, std::shared_ptr<NIdentifier> id, std::vector<std::shared_ptr<NArgument>> arguments) : retType(type), id(id), arguments(arguments) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NFunctionDeclaration"; }
};

class NFunctionDeclaration : public NStatement {
public:
    std::shared_ptr<NFunctionDefinition> definition;
    std::shared_ptr<NBlock> block;
    NFunctionDeclaration(std::shared_ptr<NFunctionDefinition> definition, std::shared_ptr<NBlock> block) : definition(definition), block(block) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NFunctionDefinition"; }
};

class NReturnStatement : public NStatement {
public:
    std::shared_ptr<NExpression> expression;
    NReturnStatement(std::shared_ptr<NExpression> expression = nullptr) : expression(expression) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NReturnStatement"; }
};

class NMemberAccess : public NExpression {
public:
    std::shared_ptr<NExpression> parent;
    std::vector<std::shared_ptr<NIdentifier>> ids;
    NMemberAccess(std::shared_ptr<NExpression> parent, const std::vector<std::shared_ptr<NIdentifier>>& ids) : parent(parent), ids(ids) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NMemberAccess"; }
};

class NFunctionCall : public NExpression {
public:
    std::shared_ptr<NMemberAccess> parent;
    std::shared_ptr<NIdentifier> id;
    std::vector<std::shared_ptr<NExpression>> arguments;
    NFunctionCall(std::shared_ptr<NMemberAccess> parent,
                  std::vector<std::shared_ptr<NExpression>> arguments) : parent(parent), id(parent->ids.back()), arguments(arguments) {
        parent->ids.pop_back();
    }
    NFunctionCall(std::shared_ptr<NIdentifier> id,
                  std::vector<std::shared_ptr<NExpression>> arguments) : id(id), arguments(arguments) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NFunctionCall"; }
};

class NOptStatement : public NStatement {
public:
    std::shared_ptr<NExpression> condition;
    std::shared_ptr<NBlock> then;

    NOptStatement(std::shared_ptr<NExpression> condition, std::shared_ptr<NBlock> then) : condition(condition), then(then) {}
    virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NForStatement : public NStatement {
public:
    std::shared_ptr<NIdentifier> iterator;
    std::shared_ptr<NExpression> init;
    std::shared_ptr<NExpression> condition;
    std::shared_ptr<NExpression> increment;
    std::shared_ptr<NBlock> block;
    NForStatement(std::shared_ptr<NIdentifier>iterator, std::shared_ptr<NExpression> init, std::shared_ptr<NExpression> condition, 
                  std::shared_ptr<NExpression> increment, std::shared_ptr<NBlock> block) : iterator(iterator), init(init), condition(condition), increment(increment), block(block) {}
    virtual llvm::Value* codeGen(CodeGenContext& context);
};

}  // namespace ddlbx::ir