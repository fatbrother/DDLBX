#pragma once

#include <llvm/IR/Module.h>

namespace ddlbx {
namespace pass {

class ObjectGenner {
public:
    ObjectGenner() = default;

    void generate(llvm::Module& module);
};

} // namespace pass
} // namespace ddlbx