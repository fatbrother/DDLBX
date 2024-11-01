#include "utils/type_parser.hpp"

std::vector<std::string> ddlbx::utility::getTemplateArgsFromFullName(const std::string &name) {
    std::vector<std::string> templateArgs;
    size_t start = name.find("<");
    if (start == std::string::npos) {
        return templateArgs;
    }
    size_t end = name.find(">");
    if (end == std::string::npos) {
        return templateArgs;
    }
    std::string args = name.substr(start + 1, end - start - 1);
    size_t pos = 0;
    while ((pos = args.find(",")) != std::string::npos) {
        templateArgs.push_back(args.substr(0, pos));
        args.erase(0, pos + 1);
    }
    templateArgs.push_back(args);
    return templateArgs;
}

std::string ddlbx::utility::getOrginalNameFromFullName(const std::string &name) {
    size_t start = name.find("<");
    if (start == std::string::npos) {
        return name;
    }
    return name.substr(0, start);
}

std::string ddlbx::utility::getTemplateString(const std::vector<std::string> &templateArgs) {
    std::string templateString = "<";
    for (const auto &arg : templateArgs) {
        templateString += arg + ",";
    }
    templateString.pop_back();
    templateString += ">";
    return templateString;
}