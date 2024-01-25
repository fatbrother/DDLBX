#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "parser/grammer.hpp"

using namespace tao::pegtl;
using namespace ddlbx::parser;

TEST(grammer, declaration) {
    std::string sample1 = "var a = 1";
    std::string sample2 = "var b = 'hello'";
    std::string sample3 = "var c = true";
    std::string sample4 = "var d = 2.3";
    std::string sample5 = "var e = 1 + 2";
    std::string sample6 = "var a";
    std::string sample7 = "var";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");
    string_input<> in3(sample3, "input");
    string_input<> in4(sample4, "input");
    string_input<> in5(sample5, "input");
    string_input<> in6(sample6, "input");
    string_input<> in7(sample7, "input");

    EXPECT_TRUE(parse<VariableDeclaration>(in1));
    EXPECT_TRUE(parse<VariableDeclaration>(in2));
    EXPECT_TRUE(parse<VariableDeclaration>(in3));
    EXPECT_TRUE(parse<VariableDeclaration>(in4));
    EXPECT_TRUE(parse<VariableDeclaration>(in5));
    EXPECT_FALSE(parse<VariableDeclaration>(in6));
    EXPECT_FALSE(parse<VariableDeclaration>(in7));
}
