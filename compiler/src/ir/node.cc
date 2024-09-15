#include "ir/node.hpp"

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Value.h>

#include "utils/logger.hpp"
#include "utils/scope_guard.hpp"
#include "ir/statement.hpp"
#include "ir/object.hpp"
#include "ir/function.hpp"
#include "parser/parser.hpp"

using namespace ddlbx::ir;
using namespace ddlbx::utility;

llvm::Value* NProgram::codeGen(CodeGenContext& context) {
    for (auto& statement : statements) {
        if ("NTemplateObjectDeclaration" == statement->getType()) {
            std::shared_ptr<NObjectDeclaration> objectDeclaration = std::dynamic_pointer_cast<NObjectDeclaration>(statement);
            std::shared_ptr<NTemplateObjectDeclaration> templateObject = std::dynamic_pointer_cast<NTemplateObjectDeclaration>(objectDeclaration);
            context.registerTemplateObject(templateObject);
            continue;
        }
        if ("NTemplateFunctionDeclaration" == statement->getType()) {
            std::shared_ptr<NFunctionDeclaration> functionDeclaration = std::dynamic_pointer_cast<NFunctionDeclaration>(statement);
            std::shared_ptr<NTemplateFunctionDeclaration> templateFunction = std::dynamic_pointer_cast<NTemplateFunctionDeclaration>(functionDeclaration);
            context.registerTemplateFunction(templateFunction);
            continue;
        }
        if ("NTraitMethodDeclaration" == statement->getType()) {
            std::shared_ptr<NTraitMethodDeclaration> traitMethod = std::dynamic_pointer_cast<NTraitMethodDeclaration>(statement);
            context.registerTraitMethod(traitMethod);
            continue;
        }
        statement->codeGen(context);
    }
    return nullptr;
}

llvm::Type* NType::codeGen(CodeGenContext& context) {
    return context.getType(name);
}
