#include "ir/value.hpp"

namespace ddlbx {
namespace ir {

llvm::Value* Value::create(const std::unique_ptr<pegtl::parse_tree::node> &root, llvm::LLVMContext &context) {
    if (!root) return nullptr;
    if (root->type != "ddlbx::parser::Value") return nullptr;

    llvm::IRBuilder<> builder(context);

    llvm::Value *result = nullptr;

    const auto &value = root->children[0];
    if (value->type == "ddlbx::parser::Integer") {
        result = llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), std::stoi(value->string()));
    } else if (value->type == "ddlbx::parser::Float") {
        result = llvm::ConstantFP::get(llvm::Type::getFloatTy(context), std::stof(value->string()));
    } else if (value->type == "ddlbx::parser::String") {
        std::string str = value->string().substr(1, value->string().size() - 2); // remove quotes
        result = llvm::ConstantDataArray::getString(context, str);
    } else if (value->type == "ddlbx::parser::Boolean") {
        if (value->string() == "true") {
            result = llvm::ConstantInt::getTrue(context);
        } else if (value->string() == "false") {
            result = llvm::ConstantInt::getFalse(context);
        } else if (value->string() == "maybe") {
            result = llvm::UndefValue::get(llvm::Type::getInt1Ty(context));
        }
    }

    return result;
}

}  // namespace ir
}  // namespace ddlbx