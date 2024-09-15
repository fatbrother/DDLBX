#pragma once

#include "ir/node.hpp"
#include "ir/expression.hpp"
#include "ir/block.hpp"

#include <string>
#include <memory>

namespace ddlbx::ir {

class NReturnStatement : public NStatement {
public:
    std::shared_ptr<NExpression> expression;
    NReturnStatement(std::shared_ptr<NExpression> expression = nullptr) : expression(expression) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NReturnStatement"; }
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

class NOptStatement : public NStatement {
public:
    std::shared_ptr<NExpression> condition;
    std::shared_ptr<NBlock> then;

    NOptStatement(std::shared_ptr<NExpression> condition, std::shared_ptr<NBlock> then) : condition(condition), then(then) {}
    virtual llvm::Value* codeGen(CodeGenContext& context);
};

}  // namespace ddlbx::ir
