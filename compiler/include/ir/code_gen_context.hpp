#pragma once

#include <iostream>
#include <map>
#include <stack>
#include <memory>

#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>

namespace ddlbx::ir {

struct Variable {
    std::string ddlbxTypeName;
    llvm::Value *ptr;
};

struct Type {
    std::string name;
    llvm::Type *type;
    std::unordered_map<std::string, llvm::Type *> nameTypeMap;
};

struct Value {
    std::string ddlbxTypeName;
    llvm::Value *llvmValue;

    static Value create(std::string ddlbxTypeName, llvm::Value *llvmValue) {
        return {ddlbxTypeName, llvmValue};
    }

    static Value null() {
        return {"", nullptr};
    }
};

struct Function {
    std::string name;
    std::string returnType;
};

class NTemplateObjectDeclaration;
class NTemplateFunctionDeclaration;
class NTraitMethodDeclaration;

#define DDLBX_TYPE_INT "Int"
#define DDLBX_TYPE_FLT "Flt"
#define DDLBX_TYPE_STR "Str"
#define DDLBX_TYPE_PTR "Ptr"
#define DDLBX_TYPE_BOO "Boo"
#define DDLBX_TYPE_NON "Non"
#define DDLBX_TYPE_CHR "Chr"
#define DDLBX_TYPE_FUN "Fun"

class CodeGenContext {
public:
    CodeGenContext(llvm::LLVMContext &context, llvm::Module &module)
        : context(context), module(module), builder(context) {
        types[DDLBX_TYPE_INT] = {DDLBX_TYPE_INT, llvm::Type::getInt32Ty(context), {}};
        types[DDLBX_TYPE_FLT] = {DDLBX_TYPE_FLT, llvm::Type::getFloatTy(context), {}};
        types[DDLBX_TYPE_STR] = {DDLBX_TYPE_STR, llvm::Type::getInt8PtrTy(context), {}};
        types[DDLBX_TYPE_PTR] = {DDLBX_TYPE_PTR, llvm::Type::getInt8PtrTy(context), {}};
        types[DDLBX_TYPE_BOO] = {DDLBX_TYPE_BOO, llvm::Type::getInt1Ty(context), {}};
        types[DDLBX_TYPE_NON] = {DDLBX_TYPE_NON, llvm::Type::getVoidTy(context), {}};
        types[DDLBX_TYPE_CHR] = {DDLBX_TYPE_CHR, llvm::Type::getInt8Ty(context), {}};
    }
    llvm::Module &getModule();
    llvm::LLVMContext &getContext();
    llvm::IRBuilder<> &getBuilder();
    llvm::Type *getType(const std::string &name);
    void addType(const std::string &name, llvm::Type *type, const std::unordered_map<std::string, llvm::Type *> &nameTypeMap);
    Variable& getVariable(const std::string &name);
    void setVariable(const std::string &name, Variable variable);
    int getTypeMemberIndex(const std::string &typeName, const std::string &memberName);
    void registerTemplateObject(std::shared_ptr<NTemplateObjectDeclaration> templateObject);
    void registerTemplateFunction(std::shared_ptr<NTemplateFunctionDeclaration> templateFunction);
    void registerTraitMethod(std::shared_ptr<NTraitMethodDeclaration> traitMethod);
    void registerFunction(const std::string &name, const std::string &returnType);
    void pushTemplateTypeStack();
    void registerTemplateType(const std::string &templateName, const std::string &type);
    void popTemplateTypeStack();
    std::shared_ptr<NTemplateObjectDeclaration> getTemplateObject(const std::string &name);
    std::shared_ptr<NTemplateFunctionDeclaration> getTemplateFunction(const std::string &name);
    std::shared_ptr<NTraitMethodDeclaration> getTraitMethod(const std::string &name);
    Function& getFunction(const std::string &name);

private:
    llvm::LLVMContext &context;
    llvm::Module &module;
    llvm::IRBuilder<> builder;

    std::map<std::string, Type> types;
    std::map<std::string, Variable> variables;
    std::map<std::string, Function> functions;
    std::map<std::string, std::shared_ptr<NTemplateObjectDeclaration>> templateObjects;
    std::map<std::string, std::shared_ptr<NTemplateFunctionDeclaration>> templateFunctions;
    std::map<std::string, std::shared_ptr<NTraitMethodDeclaration>> traitMethods;
    std::stack<std::map<std::string, Type>> templateTypeStack;
};

} // namespace ddlbx::ir