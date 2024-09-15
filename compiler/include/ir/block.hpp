#pragma once

#include "ir/node.hpp"

#include <vector>

namespace ddlbx::ir {

class NBlock : public NStatement {
public:
    std::vector<NStatement*> statements;
    NBlock() {}
    virtual llvm::Value* codeGen(CodeGenContext& context) override;
    virtual std::string getType() override { return "NBlock"; }
};

}  // namespace ddlbx::ir