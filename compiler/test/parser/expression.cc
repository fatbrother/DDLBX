#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "parser/grammar.hpp"

using namespace tao::pegtl;
using namespace ddlbx::parser;

TEST(Grammar, Expression) {
    std::string sample1 = "var a = 1!";
    std::string sample2 = "var b = 'hello' !";
    std::string sample3 = "1 + 2!";
    std::string sample4 = "+ 1 2!";
    std::string sample5 = "ret 1!";
    std::string sample6 = "ret 1 + 1!";
    std::string sample7 = "print('Hello, World!')!";
    std::string sample8 = "opt (a == 1) { print(1)! }!";
    std::string sample9 = "opt (a == 1) print(1)!";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");
    string_input<> in3(sample3, "input");
    string_input<> in4(sample4, "input");
    string_input<> in5(sample5, "input");
    string_input<> in6(sample6, "input");
    string_input<> in7(sample7, "input");
    string_input<> in8(sample8, "input");
    string_input<> in9(sample9, "input");

    EXPECT_TRUE(parse<Expression>(in1));
    EXPECT_TRUE(parse<Expression>(in2));
    EXPECT_TRUE(parse<Expression>(in3));
    EXPECT_FALSE(parse<Expression>(in4));
    EXPECT_TRUE(parse<Expression>(in5));
    EXPECT_TRUE(parse<Expression>(in6));
    EXPECT_TRUE(parse<Expression>(in7));
    EXPECT_TRUE(parse<Expression>(in8));
    EXPECT_TRUE(parse<Expression>(in9));
}