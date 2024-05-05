#include "ir/function_handler.hpp"

namespace ddlbx {
namespace ir {

FunctionHandler::FunctionHandler(const std::unique_ptr<pegtl::parse_tree::node>& node): body(node->children.back()) {
    int idx = 0;
    if (node->children[idx]->type == "ddlbx::parser::Type") {
        parentTypeName = node->children[idx++]->string();
    }

    name = (parentTypeName != "" ? parentTypeName + "_" : "") + node->children[idx++]->string();
    const auto& params = node->children[idx++];
    retTypeName = node->children[idx++]->string();
    
    for (const auto& param : params->children) {
        std::string paramName = param->children[0]->string();
        std::string typeName = param->children[1]->string();
        paramNamesAndTypeNames.push_back({paramName, typeName});
    }
}

llvm::Function* FunctionHandler::createFunction(llvm::Module& module, std::map<std::string, llvm::Type*>& typeMap) {
    llvm::Type* retType = typeMap[retTypeName];
    if (!retType) {
        throw std::runtime_error("Type " + retTypeName + " not found");
    }

    std::vector<llvm::Type*> argTypes;
    for (const auto& [paramName, typeName] : paramNamesAndTypeNames) {
        llvm::Type* argType = typeMap[typeName];
        if (!argType) {
            throw std::runtime_error("Type " + typeName + " not found");
        }
        argTypes.push_back(argType);
    }

    llvm::FunctionType* funcType = llvm::FunctionType::get(retType, argTypes, false);
    function = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name, &module);
    
    // Set parameter names
    for (int i = 0; i < function->arg_size(); i++) {
        function->getArg(i)->setName(paramNamesAndTypeNames[i].first);
    }

    return function;
}



} // namespace ir
} // namespace ddlbx