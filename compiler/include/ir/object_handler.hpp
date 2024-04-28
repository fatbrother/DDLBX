#pragma once

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

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

class ObjectHandler {
public:
    ObjectHandler() = default;
    ObjectHandler(const std::unique_ptr<pegtl::parse_tree::node>& node);
    ObjectHandler(const std::string& name, const std::map<std::string, std::string>& memberNameType)
        : name(name), memberNameType(memberNameType) {}

    llvm::StructType* createObject(llvm::LLVMContext& context, llvm::Module& module, std::map<std::string, llvm::Type*>& typeMap, std::map<std::string, std::string>& templateMap);

    std::string getName() const { return name; }
    std::map<std::string, std::string> getMemberNameType() const { return memberNameType; }
    int getMemberIndex(const std::string& memberName);

private:
    std::string name;
    std::map<std::string, std::string> memberNameType;
};

} // namespace ir
} // namespace ddlbx