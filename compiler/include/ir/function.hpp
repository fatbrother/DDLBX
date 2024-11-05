#pragma once

#include "ir/node.hpp"
#include "ir/statement.hpp"

#include <string>
#include <vector>
#include <memory>

namespace ddlbx::ir {

class NArgument : public NExpression {
public:
    std::shared_ptr<NType> type;
    std::string name;
    NArgument(std::shared_ptr<NType> type, std::string name) : type(type), name(name) {}
    virtual Value codeGenValue(CodeGenContext& context) override {
        LOG_DEBUG("NArgument::codeGenValue() should not be called");
        return Value::null();
    }
    virtual std::string getType() override { return "NArgument"; }
};

class NFunctionDefinition : public NStatement {
public:
    std::shared_ptr<NType> retType;
    std::string name;
    std::vector<std::shared_ptr<NArgument>> arguments;
    NFunctionDefinition(std::shared_ptr<NType> retType, std::string funcName, std::vector<std::shared_ptr<NArgument>> arguments)
        : retType(retType), name(funcName), arguments(arguments) {}
    virtual Value codeGenValue(CodeGenContext& context) override;
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
    virtual Value codeGenValue(CodeGenContext& context) override;
    virtual std::string getType() override { return "NFunctionDefinition"; }
};

class NTemplateFunctionDeclaration : public NFunctionDeclaration {
public:
    NTemplateFunctionDeclaration(std::shared_ptr<NFunctionDefinition> definition, std::shared_ptr<NBlock> block)
        : NFunctionDeclaration(definition, block) {}
    virtual Value codeGenValue(CodeGenContext& context) override {
        LOG_DEBUG("NTemplateFunctionDeclaration::codeGenValue() should not be called");
        return Value::null();
    }
    Value codeGenValue(CodeGenContext& context, std::vector<std::string> templateArgs);
    virtual std::string getType() override { return "NTemplateFunctionDeclaration"; }
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
    virtual Value codeGenValue(CodeGenContext& context) override;
    virtual std::string getType() override { return "NFunctionCall"; }
};

class NMethodDefinition : public NFunctionDefinition {
public:
    std::string parentName;
    NMethodDefinition(std::shared_ptr<NType> retType, std::string funcName,
                      std::vector<std::shared_ptr<NArgument>> arguments,
                      std::string parentName) : NFunctionDefinition(retType, funcName, arguments), parentName(parentName) {}
    virtual std::string getType() override { return "MethodDefinition"; }
};

class NMethodDeclaration : public NFunctionDeclaration {
public:
    NMethodDeclaration(std::shared_ptr<NFunctionDefinition> definition, std::shared_ptr<NBlock> block)
        : NFunctionDeclaration(definition, block) {}
    virtual Value codeGenValue(CodeGenContext& context) override;
    virtual std::string getType() override { return "NMethodDeclaration"; }
};

class NTemplateObjectMethodDefinition : public NMethodDefinition {
public:
    std::vector<std::string> templates;
    NTemplateObjectMethodDefinition(std::shared_ptr<NType> retType, std::string funcName,
                                    std::vector<std::shared_ptr<NArgument>> arguments,
                                    std::string parentName, std::vector<std::string> templates)
        : NMethodDefinition(retType, funcName, arguments, parentName), templates(templates) {}
    virtual std::string getType() override { return "NTemplateObjectMethodDefinition"; }
};

class NTemplateObjectMethodDeclaration : public NMethodDeclaration {
public:
    NTemplateObjectMethodDeclaration(std::shared_ptr<NFunctionDefinition> definition, std::shared_ptr<NBlock> block)
        : NMethodDeclaration(definition, block) {}
    virtual Value codeGenValue(CodeGenContext& context) override {
        LOG_DEBUG("NTemplateObjectMethodDeclaration::codeGenValue() should not be called");
        return Value::null();
    }
    Value codeGenValue(CodeGenContext& context, std::vector<std::string> templateArgs);
    virtual std::string getType() override { return "NTemplateObjectMethodDeclaration"; }
};

class NTraitMethodDeclaration : public NMethodDeclaration {
public:
    std::vector<std::shared_ptr<NMemberDeclaration>> traits;
    NTraitMethodDeclaration(std::shared_ptr<NFunctionDeclaration> declaration, std::vector<std::shared_ptr<NMemberDeclaration>> traits)
        : NMethodDeclaration(declaration->definition, declaration->block), traits(traits) {}
    Value codeGenValue(CodeGenContext& context, std::string parentName);
    virtual std::string getType() override { return "NTraitMethodDeclaration"; }
};

}  // namespace ddlbx::ir