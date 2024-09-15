#pragma once

#include "ir/node.hpp"
#include "ir/expression.hpp"
#include "ir/statement.hpp"
#include "utils/logger.hpp"

namespace ddlbx::ir {

class NObjectDeclaration : public NStatement {
public:
    std::string name;
    std::vector<std::shared_ptr<NMemberDeclaration>> members;
    NObjectDeclaration(std::string name, std::vector<std::shared_ptr<NMemberDeclaration>> members)
        : name(name), members(members) {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    void genConstructor(CodeGenContext& context, std::vector<llvm::Type*>& argTypes);
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
    llvm::Type* codeGen(CodeGenContext& context, std::vector<std::shared_ptr<NType>> templateArgs);
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

}  // namespace ddlbx::ir