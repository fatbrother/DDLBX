#pragma once

#include <iostream>
#include <map>
#include <stack>
#include <memory>

#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>

namespace ddlbx::ir {

struct Variable {
    llvm::Type *type;
    llvm::Value *ptr;
};

struct Type {
    std::string name;
    llvm::Type *type;
    std::unordered_map<std::string, llvm::Type *> nameTypeMap;
};

class NTemplateObjectDeclaration;
class NTemplateFunctionDeclaration;
class NTraitMethodDeclaration;

class CodeGenContext {
public:
    CodeGenContext(llvm::LLVMContext &context, llvm::Module &module)
        : context(context), module(module), builder(context) {
        types["Int"] = {"Int", llvm::Type::getInt32Ty(context), {}};
        types["Flt"] = {"Flt", llvm::Type::getFloatTy(context), {}};
        types["Str"] = {"Str", llvm::Type::getInt8PtrTy(context), {}};
        types["Boo"] = {"Boo", llvm::Type::getInt1Ty(context), {}};
        types["Non"] = {"Non", llvm::Type::getVoidTy(context), {}};
    }
    llvm::Module &getModule();
    llvm::LLVMContext &getContext();
    llvm::IRBuilder<> &getBuilder();
    llvm::Type *getType(const std::string &name);
    void addType(const std::string &name, llvm::Type *type, const std::unordered_map<std::string, llvm::Type *> &nameTypeMap);
    std::string getTypeName(llvm::Type *type);
    Variable& getVariable(const std::string &name);
    void setVariable(const std::string &name, Variable variable);
    int getTypeMemberIndex(const std::string &typeName, const std::string &memberName);
    void registerTemplateObject(std::shared_ptr<NTemplateObjectDeclaration> templateObject);
    void registerTemplateFunction(std::shared_ptr<NTemplateFunctionDeclaration> templateFunction);
    void registerTraitMethod(std::shared_ptr<NTraitMethodDeclaration> traitMethod);
    void pushTemplateTypeStack();
    void registerTemplateType(const std::string &templateName, const std::string &type);
    void popTemplateTypeStack();
    std::shared_ptr<NTemplateObjectDeclaration> getTemplateObject(const std::string &name);
    std::shared_ptr<NTemplateFunctionDeclaration> getTemplateFunction(const std::string &name);
    std::shared_ptr<NTraitMethodDeclaration> getTraitMethod(const std::string &name);

private:
    llvm::LLVMContext &context;
    llvm::Module &module;
    llvm::IRBuilder<> builder;

    std::map<std::string, Type> types;
    std::map<std::string, Variable> variables;
    std::map<std::string, std::shared_ptr<NTemplateObjectDeclaration>> templateObjects;
    std::map<std::string, std::shared_ptr<NTemplateFunctionDeclaration>> templateFunctions;
    std::map<std::string, std::shared_ptr<NTraitMethodDeclaration>> traitMethods;
    std::stack<std::map<std::string, Type>> templateTypeStack;
};

} // namespace ddlbx::ir