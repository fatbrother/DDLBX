#pragma once

#include <llvm/IR/Value.h>

#include <iostream>
#include <memory>
#include <vector>

#include "ir/code_gen_context.hpp"
#include "utils/logger.hpp"

using namespace ddlbx::utility;

namespace ddlbx::ir {

class NStatement;
class NExpression;
class NVariableDeclaration;

class Node {
public:
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
    std::string name;
    NArgument(std::shared_ptr<NType> type, std::string name) : type(type), name(name) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override { return nullptr; }
    virtual std::string getType() override { return "NArgument"; }
};

class NFunctionDefinition : public NStatement {
public:
    std::shared_ptr<NType> retType;
    std::string name;
    std::vector<std::shared_ptr<NArgument>> arguments;
    NFunctionDefinition(std::shared_ptr<NType> type, std::string name, std::vector<std::shared_ptr<NArgument>> arguments)
        : retType(type), name(name), arguments(arguments) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NFunctionDeclaration"; }
};

class NTemplateFunctionDefinition : public NFunctionDefinition {
public:
    std::vector<std::string> templates;
    NTemplateFunctionDefinition(std::shared_ptr<NType> type, std::string name,
                                std::vector<std::shared_ptr<NArgument>> arguments, std::vector<std::string> templates)
        : NFunctionDefinition(type, name, arguments), templates(templates) {}
    virtual std::string getType() override { return "NTemplateFunctionDefinition"; }
};

class NFunctionDeclaration : public NStatement {
public:
    std::shared_ptr<NFunctionDefinition> definition;
    std::shared_ptr<NBlock> block;
    NFunctionDeclaration(std::shared_ptr<NFunctionDefinition> definition, std::shared_ptr<NBlock> block) : definition(definition), block(block) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NFunctionDefinition"; }
};

class NTemplateFunctionDeclaration : public NFunctionDeclaration {
public:
    NTemplateFunctionDeclaration(std::shared_ptr<NFunctionDefinition> definition, std::shared_ptr<NBlock> block)
        : NFunctionDeclaration(definition, block) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override {
        LOG_DEBUG("NTemplateFunctionDeclaration::codeGen() should not be called");
        return nullptr;
    }
    llvm::Value* codeGen(CodeGenContext& context, std::vector<std::string> templateArgs);
    virtual std::string getType() override { return "NTemplateFunctionDeclaration"; }
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
    std::vector<std::string> templateArgs;
    std::shared_ptr<NMemberAccess> parent;
    std::string name;
    std::vector<std::shared_ptr<NExpression>> arguments;
    NFunctionCall(std::shared_ptr<NMemberAccess> parent,
                  std::vector<std::shared_ptr<NExpression>> arguments) : parent(parent), name(parent->ids.back()->name), arguments(arguments) {
        parent->ids.pop_back();
    }
    NFunctionCall(std::string name,
                  std::vector<std::shared_ptr<NExpression>> arguments) : name(name), arguments(arguments) {}
    NFunctionCall(std::string name,
                  std::vector<std::shared_ptr<NExpression>> arguments,
                  std::vector<std::string> templateArgs) : name(name), arguments(arguments), templateArgs(templateArgs) {}
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
    NForStatement(std::shared_ptr<NIdentifier> iterator, std::shared_ptr<NExpression> init, std::shared_ptr<NExpression> condition,
                  std::shared_ptr<NExpression> increment, std::shared_ptr<NBlock> block) : iterator(iterator), init(init), condition(condition), increment(increment), block(block) {}
    virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NMemberDeclaration : public NStatement {
public:
    std::shared_ptr<NType> type;
    std::string name;
    NMemberDeclaration(std::shared_ptr<NType> type, std::string name) : type(type), name(name) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) {
        LOG_DEBUG("NMemberDeclaration::codeGen() should not be called");
        return nullptr;
    }
};

class NObjectDeclaration : public NStatement {
public:
    std::string name;
    std::vector<std::shared_ptr<NMemberDeclaration>> members;
    NObjectDeclaration(std::string name, std::vector<std::shared_ptr<NMemberDeclaration>> members)
        : name(name), members(members) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NObjectDeclaration"; }
};

class NTemplateObjectDeclaration : public NObjectDeclaration {
public:
    std::vector<std::string> templates;
    NTemplateObjectDeclaration(std::string name, std::vector<std::shared_ptr<NMemberDeclaration>> members, std::vector<std::string> templates)
        : NObjectDeclaration(name, members), templates(templates) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override {
        LOG_DEBUG("NTemplateObjectDeclaration::codeGen() should not be called");
        return nullptr;
    }
    llvm::Value* codeGen(CodeGenContext& context, std::vector<std::shared_ptr<NType>> templateArgs);
    virtual std::string getType() override { return "NTemplateObjectDeclaration"; }
};

class NObjectCreation : public NExpression {
public:
    std::string name;
    std::vector<std::shared_ptr<NExpression>> arguments;
    std::vector<std::string> templateArgs;
    NObjectCreation(std::string name, std::vector<std::shared_ptr<NExpression>> arguments)
        : name(name), arguments(arguments) {}
    NObjectCreation(std::string name, std::vector<std::shared_ptr<NExpression>> arguments, std::vector<std::string> templateArgs)
        : name(name), arguments(arguments), templateArgs(templateArgs) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NObjectCreation"; }
};

class NMethodDeclaration : public NStatement {
public:
    std::string name;
    std::shared_ptr<NFunctionDeclaration> declaration;
    NMethodDeclaration(std::string name, std::shared_ptr<NFunctionDeclaration> declaration) : name(name), declaration(declaration) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NMethodDeclaration"; }
};

class NTraitMethodDeclaration : public NMethodDeclaration {
public:
    std::vector<std::shared_ptr<NMemberDeclaration>> traits;
    NTraitMethodDeclaration(std::string name, std::shared_ptr<NFunctionDeclaration> declaration, std::vector<std::shared_ptr<NMemberDeclaration>> traits)
        : NMethodDeclaration(name, declaration), traits(traits) {}
    llvm::Value* codeGen(CodeGenContext& context, std::string parentName);
    virtual std::string getType() override { return "NTraitMethodDeclaration"; }
};

}  // namespace ddlbx::ir