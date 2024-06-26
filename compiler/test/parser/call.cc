#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "parser/grammar.hpp"

using namespace tao::pegtl;
using namespace ddlbx::parser;

TEST(Grammar, Call) {
    std::string input1 = "foo()";
    std::string input2 = "foo(1)";
    std::string input3 = "foo(1, 2, 3)";
    std::string input4 = "foo(1, 2, 3,)";
    std::string input5 = "foo(1,";
    std::string input6 = "foo(a.b)";
    std::string input7 = "foo<Int>(1)";
    std::string input8 = "foo<Int, Str>(1)";

    string_input<> in1(input1, "input");
    string_input<> in2(input2, "input");
    string_input<> in3(input3, "input");
    string_input<> in4(input4, "input");
    string_input<> in5(input5, "input");
    string_input<> in6(input6, "input");
    string_input<> in7(input7, "input");
    string_input<> in8(input8, "input");

    EXPECT_TRUE(parse<FunctionCall>(in1));
    EXPECT_TRUE(parse<FunctionCall>(in2));
    EXPECT_TRUE(parse<FunctionCall>(in3));
    EXPECT_FALSE(parse<FunctionCall>(in4));
    EXPECT_FALSE(parse<FunctionCall>(in5));
    EXPECT_TRUE(parse<FunctionCall>(in6));
    EXPECT_TRUE(parse<FunctionCall>(in7));
    EXPECT_TRUE(parse<FunctionCall>(in8));
}