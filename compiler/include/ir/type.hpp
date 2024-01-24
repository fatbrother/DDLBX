#pragma once

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>
#include <tao/pegtl/contrib/parse_tree_to_dot.hpp>

#include <map>

#include "parser/grammer.hpp"

namespace pegtl = tao::pegtl;

namespace ddlbx {
namespace ir {

class Type {
public:
    Type(llvm::LLVMContext& context);

    llvm::Type* get(const std::string& type);

private:
    void initTypes();

    llvm::LLVMContext& context;

    static std::map<std::string, llvm::Type*> types;
    static bool init;
};

}  // namespace ir
}  // namespace ddlbx