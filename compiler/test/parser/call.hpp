#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "parser/grammar.hpp"

using namespace tao::pegtl;
using namespace ddlbx::parser;

TEST(grammer, call) {
    std::string input1 = "foo()";
    std::string input2 = "foo(1)";
    std::string input3 = "foo(1, 2, 3)";
    std::string input4 = "foo(1, 2, 3,)";
    std::string input5 = "foo(1,";

    string_input<> in1(input1, "input");
    string_input<> in2(input2, "input");
    string_input<> in3(input3, "input");
    string_input<> in4(input4, "input");
    string_input<> in5(input5, "input");

    EXPECT_TRUE(parse<FunctionCall>(in1));
    EXPECT_TRUE(parse<FunctionCall>(in2));
    EXPECT_TRUE(parse<FunctionCall>(in3));
    EXPECT_FALSE(parse<FunctionCall>(in4));
    EXPECT_FALSE(parse<FunctionCall>(in5));
}