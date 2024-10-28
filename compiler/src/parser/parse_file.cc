#include "parser/parse_file.hpp"

#include "utils/logger.hpp"

#include <fstream>
#include <iostream>
#include <string>

bool ddlbx::parser::parseFile(const std::string &fileName) {
    std::ifstream file(fileName);
    if (!file) {
        LOG_ERROR("Failed to open file: " + fileName);
        return false;
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    parseContent(content);

    file.close();

    return true;
}

bool ddlbx::parser::parseContent(const std::string &content) {
    yylineno = 1;
    YY_BUFFER_STATE my_string_buffer = yy_scan_string(content.c_str());
    yy_switch_to_buffer( my_string_buffer); // switch flex to the buffer we just created
    int res = yyparse();
    yy_delete_buffer(my_string_buffer);

    if (res != 0) {
        LOG_ERROR("Failed to parse content");
        return false;
    }
    return true;
}