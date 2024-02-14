#include "pass/object_genner.hpp"

#include <llvm/IR/Module.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/MC/TargetRegistry.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>
#include <llvm/TargetParser/Host.h>

namespace ddlbx {
namespace pass {

void ObjectGenner::generate(llvm::Module& module) {
    auto targetTriple = llvm::sys::getDefaultTargetTriple();
    llvm::InitializeAllTargetInfos();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();

    std::string error;
    auto target = llvm::TargetRegistry::lookupTarget(targetTriple, error);
    if (!target) {
        llvm::errs() << error;
        return;
    }

    auto cpu = "generic";
    auto features = "";
    llvm::TargetOptions opt;
    auto targetMachine = target->createTargetMachine(targetTriple, cpu, features, opt, llvm::Reloc::PIC_);
    module.setDataLayout(targetMachine->createDataLayout());
    module.setTargetTriple(targetTriple);

    auto filename = "output.o";
    std::error_code ec;
    llvm::raw_fd_ostream dest(filename, ec, llvm::sys::fs::OF_None);
    if (ec) {
        llvm::errs() << "Could not open file: " << ec.message();
        return;
    }

    llvm::legacy::PassManager pass;
    auto FileType = llvm::CodeGenFileType::ObjectFile;

    if (targetMachine->addPassesToEmitFile(pass, dest, nullptr, FileType)) {
        llvm::errs() << "TheTargetMachine can't emit a file of this type";
        return;
    }

    pass.run(module);
    dest.flush();
}

}  // namespace pass
}  // namespace ddlbx