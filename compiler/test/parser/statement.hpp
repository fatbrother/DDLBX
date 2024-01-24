#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "grammer.hpp"

using namespace tao::pegtl;
using namespace ddlbx::parser;

TEST(grammer, statement) {
    std::string sample1 = "var a = 1!";
    std::string sample2 = "var b = 'hello' !";
    std::string sample3 = "1 + 2!";
    std::string sample4 = "+ 1 2!";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");
    string_input<> in3(sample3, "input");
    string_input<> in4(sample4, "input");

    EXPECT_TRUE(parse<Statement>(in1));
    EXPECT_TRUE(parse<Statement>(in2));
    EXPECT_TRUE(parse<Statement>(in3));
    EXPECT_FALSE(parse<Statement>(in4));
}