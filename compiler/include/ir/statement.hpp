#pragma once

#include "ir/node.hpp"
#include "ir/expression.hpp"

#include <string>
#include <memory>

namespace ddlbx::ir {

class NReturnStatement : public NStatement {
public:
    std::shared_ptr<NExpression> expression;
    NReturnStatement(std::shared_ptr<NExpression> expression = nullptr) : expression(expression) {}
    virtual Value codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NReturnStatement"; }
};

class NBlock : public NStatement {
public:
    std::vector<NStatement*> statements;
    NBlock() {}
    virtual Value codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NBlock"; }
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
    virtual Value codeGen(CodeGenContext& context);
    virtual std::string getType() override { return "NForStatement"; }
};

class NMemberDeclaration : public NStatement {
public:
    std::shared_ptr<NType> type;
    std::string name;
    NMemberDeclaration(std::shared_ptr<NType> type, std::string name) : type(type), name(name) {}
    virtual Value codeGen(CodeGenContext& context) {
        LOG_DEBUG("NMemberDeclaration::codeGen() should not be called");
        return Value::null();
    }
    virtual std::string getType() override { return "NMemberDeclaration"; }
};

class NOptStatement : public NStatement {
public:
    std::shared_ptr<NExpression> condition;
    std::shared_ptr<NBlock> then;

    NOptStatement(std::shared_ptr<NExpression> condition, std::shared_ptr<NBlock> then) : condition(condition), then(then) {}
    virtual Value codeGen(CodeGenContext& context);
    virtual std::string getType() override { return "NOptStatement"; }
};

}  // namespace ddlbx::ir
