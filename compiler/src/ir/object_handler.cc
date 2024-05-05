#include "ir/object_handler.hpp"

namespace ddlbx {
namespace ir {

ObjectHandler::ObjectHandler(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    name = node->children[0]->string();
    const auto& members = node->children.back();

    if (node->children.size() > 2) {
        for (const auto& templateNode : node->children[1]->children) {
            templateList.push_back(templateNode->string());
        }
    }

    for (const auto& member : members->children) {
        std::string typeName = member->children[1]->string();
        std::string memberName = member->children[0]->string();
        memberNameType[memberName] = typeName;
    }
}

llvm::StructType* ObjectHandler::createObject(llvm::LLVMContext& context, llvm::Module& module, std::map<std::string, llvm::Type*>& typeMap, std::map<std::string, std::string>& templateMap) {
    std::string realName = name;
    for (const auto& templateName : templateList) {
        realName += "_" + templateName;
    }
    
    llvm::StructType* structType = llvm::StructType::create(context, realName);
    std::vector<llvm::Type*> memberTypes;
    for (const auto& [memberName, typeName] : memberNameType) {
        std::string templateName = typeName;
        if (templateMap.find(typeName) != templateMap.end()) {
            templateName = templateMap[typeName];
        }

        llvm::Type* memberType = typeMap[templateName];
        if (!memberType) {
            throw std::runtime_error("Type " + typeName + " not found");
        }
        memberTypes.push_back(memberType);
    }
    structType->setBody(memberTypes);

    // create constructor
    llvm::IRBuilder<> builder(context);
    llvm::FunctionType* funcType = llvm::FunctionType::get(structType, memberTypes, false);
    llvm::Function* func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, realName + "_factory", &module);
    llvm::BasicBlock* block = llvm::BasicBlock::Create(context, "entry", func);
    builder.SetInsertPoint(block);
    llvm::Value* thisPtr = builder.CreateAlloca(structType, nullptr, "this");
    int i = 0;
    for (auto& arg : func->args()) {
        llvm::Value* ptr = builder.CreateStructGEP(structType, thisPtr, i++);
        builder.CreateStore(&arg, ptr);
    }
    llvm::Value* ret = builder.CreateLoad(structType, thisPtr);
    builder.CreateRet(ret);

    return structType;
}

int ObjectHandler::getMemberIndex(const std::string& memberName) {
    int i = std::distance(memberNameType.begin(), memberNameType.find(memberName));
    return i == memberNameType.size() ? -1 : i;
}

}  // namespace ir
}  // namespace ddlbx