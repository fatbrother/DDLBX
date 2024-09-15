#include "ir/block.hpp"

using namespace ddlbx::ir;

llvm::Value* NBlock::codeGen(CodeGenContext& context) {
    for (auto& statement : statements) {
        statement->codeGen(context);
    }
    return nullptr;
}
