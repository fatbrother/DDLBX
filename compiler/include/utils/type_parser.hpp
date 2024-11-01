#pragma once

#include <string>
#include <vector>

namespace ddlbx::utility {

std::vector<std::string> getTemplateArgsFromFullName(const std::string &name);
std::string getOrginalNameFromFullName(const std::string &name);
std::string getTemplateString(const std::vector<std::string> &templateArgs);

} // namespace ddlbx::utility