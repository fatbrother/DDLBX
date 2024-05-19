#pragma once

#include "ir/function_handler.hpp"

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>

#include <map>
#include <vector>
#include <memory>
#include <string>
#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>
#include <iostream>

namespace pegtl = tao::pegtl;

namespace ddlbx{
namespace ir{

class FunctionHandler;
class ObjectHandler {
public:
    ObjectHandler() = default;
    ObjectHandler(const std::unique_ptr<pegtl::parse_tree::node>& node);
    ObjectHandler(const std::string& name, const std::map<std::string, std::string>& memberNameType, llvm::Type* type)
        : name(name), memberNameType(memberNameType), type(type) {}

    llvm::StructType* createObject(llvm::LLVMContext& context, llvm::Module& module, std::map<std::string, std::shared_ptr<ObjectHandler>>& objectMap, std::map<std::string, std::string>& templateMap);

    std::string getName() const { return name; }
    std::map<std::string, std::string> getMemberNameType() const { return memberNameType; }
    std::vector<std::string> getTemplateList() const { return templateList; }
    int getMemberIndex(const std::string& memberName);
    void insertMethod(std::shared_ptr<FunctionHandler> method) {
        methodList.push_back(method);
    }
    std::vector<std::shared_ptr<FunctionHandler>> getMethodList() const { return methodList; }
    llvm::Type* getType() const { 
        if (!type) {
            throw std::runtime_error(name + " type has not been created");
        }
        return type;
    }

private:
    std::string name;
    std::map<std::string, std::string> memberNameType;
    std::vector<std::string> templateList;
    std::vector<std::shared_ptr<FunctionHandler>> methodList;
    llvm::Type* type;
};

} // namespace ir
} // namespace ddlbx