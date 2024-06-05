#include "ir/function_handler.hpp"

#include "ir/object_handler.hpp"

namespace ddlbx {
namespace ir {

FunctionHandler::FunctionHandler(const std::unique_ptr<pegtl::parse_tree::node>& node): body(node->children.back()) {
    int idx = 0;
    if (node->children[idx]->type == "ddlbx::parser::Type") {
        parentTypeName = node->children[idx++]->string();
    } else if (node->children[idx]->type == "ddlbx::parser::Trait") {
        for (const auto& trait : node->children[idx]->children[0]->children) {
            std::string typeName = trait->children[1]->string();
            std::string traitName = trait->children[0]->string();
            parentTrait[traitName] = typeName;
        }
        idx++;
    }

    name = node->children[idx++]->string(); // TODO: support template object
    const auto& params = node->children[idx++];
    retTypeName = node->children[idx++]->string();

    
    for (const auto& param : params->children) {
        std::string paramName = param->children[0]->string();
        std::string typeName = param->children[1]->string();
        paramNamesAndTypeNames.push_back({paramName, typeName});
    }
}

llvm::Function* FunctionHandler::createFunction(llvm::Module& module, std::map<std::string, std::shared_ptr<ObjectHandler>>& objectMap, const std::string& traitParent) {
    llvm::Type* retType = objectMap[retTypeName]->getType();
    if (!retType) {
        throw std::runtime_error("Type " + retTypeName + " not found");
    }

    if (traitParent != "" && objectMap.find(traitParent) != objectMap.end()) {
        // check if traitParent valid
        for (const auto& [traitName, typeName] : parentTrait) {
            if (objectMap[traitParent]->getMemberType(traitName) != typeName) {
                throw std::runtime_error("Trait " + traitName + ": " + typeName + " not found in " + traitParent);
            }
        }

        parentTypeName = traitParent;
    }

    if (parentTypeName != "") {
        paramNamesAndTypeNames.push_back({"this", parentTypeName});
    }

    std::vector<llvm::Type*> argTypes;
    for (const auto& [paramName, typeName] : paramNamesAndTypeNames) {
        llvm::Type* argType = objectMap[typeName]->getType();
        if (!argType) {
            throw std::runtime_error("Type " + typeName + " not found");
        }
        argTypes.push_back(argType);
    }

    std::string realName = parentTypeName == "" ? name : parentTypeName + "_" + name;

    llvm::FunctionType* funcType = llvm::FunctionType::get(retType, argTypes, false);
    function = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, realName, &module);
    function->setGC("coreclr");
    // Set parameter names
    for (int i = 0; i < function->arg_size(); i++) {
        function->getArg(i)->setName(paramNamesAndTypeNames[i].first);
    }

    if (traitParent != "" && objectMap.find(traitParent) != objectMap.end()) {
        paramNamesAndTypeNames.pop_back();
    }

    return function;
}

void FunctionHandler::insertVariable(std::string variableName, llvm::AllocaInst* alloca){
    variableMap[variableName] = alloca;
}

llvm::AllocaInst* FunctionHandler::getVariableAlloca(std::string variableName){
    llvm::AllocaInst* alloca = nullptr;
    if(variableMap.find(variableName) != variableMap.end()){
        alloca = variableMap[variableName];
    }
    return alloca;
}

llvm::Value* FunctionHandler::getVariableValue(std::string variableName){
    llvm::Value* value = nullptr;
    if (function) {
        for (auto& arg : function->args()) {
            if (arg.getName() == variableName) {
                value = &arg;
                return value;
            }
        }
    }
    return value;
}

bool FunctionHandler::deleteVariable(std::string variableName){
    if(variableMap.find(variableName) != variableMap.end()){
        variableMap.erase(variableName);
        return true;
    }
    return false;
}

} // namespace ir
} // namespace ddlbx