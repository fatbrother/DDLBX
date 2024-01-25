#include "ir/type.hpp"

#include <map>

namespace ddlbx {
namespace ir {

std::map<std::string, llvm::Type*> Type::types;
bool Type::init = false;

llvm::Type* Type::get(const std::string& type, llvm::LLVMContext& context) {
    if (!init) initTypes(context);
    return types[type];
}

void Type::initTypes(llvm::LLVMContext& context) {
    types["Int"] = llvm::Type::getInt32Ty(context);
    types["Flo"] = llvm::Type::getFloatTy(context);
    types["Str"] = llvm::Type::getInt8PtrTy(context);
    types["Boo"] = llvm::Type::getInt1Ty(context);
    types["Non"] = llvm::Type::getVoidTy(context);
    init = true;
}

}  // namespace ir
}  // namespace ddlbx