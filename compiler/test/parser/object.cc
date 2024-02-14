#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "parser/grammar.hpp"

using namespace tao::pegtl;
using namespace ddlbx::parser;

TEST(Grammar, Object) {
    std::string sample1 = "obj A {}";

    std::string sample2 = "obj A {a: Int}";
    std::string sample3 = "obj A { a: Int, b: Int }";

    std::string sample4 = R"(obj A {
    a: Int
})";

    std::string sample5 = R"(obj A {
    a: Int,
    b: Int
})";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");
    string_input<> in3(sample3, "input");
    string_input<> in4(sample4, "input");
    string_input<> in5(sample5, "input");

    EXPECT_TRUE(parse<Object>(in1));
    EXPECT_TRUE(parse<Object>(in2));
    EXPECT_TRUE(parse<Object>(in3));
    EXPECT_TRUE(parse<Object>(in4));
    EXPECT_TRUE(parse<Object>(in5));
}
