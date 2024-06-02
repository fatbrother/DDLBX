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

    std::string sample6 = R"(obj A<T> {
    a: T
})";

    std::string sample7 = R"(obj A<T, U> {
    a: T,
    b: U
})";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");
    string_input<> in3(sample3, "input");
    string_input<> in4(sample4, "input");
    string_input<> in5(sample5, "input");
    string_input<> in6(sample6, "input");
    string_input<> in7(sample7, "input");

    EXPECT_TRUE(parse<Object>(in1));
    EXPECT_TRUE(parse<Object>(in2));
    EXPECT_TRUE(parse<Object>(in3));
    EXPECT_TRUE(parse<Object>(in4));
    EXPECT_TRUE(parse<Object>(in5));
    EXPECT_TRUE(parse<Object>(in6));
    EXPECT_TRUE(parse<Object>(in7));
}
