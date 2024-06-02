#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "parser/grammar.hpp"
#include "parser/selector.hpp"

using namespace tao::pegtl;
using namespace ddlbx::parser;

TEST(Grammar, Function) {
    std::string sample1 = R"(fun add(a: Int): Int { a + 1! })";

    std::string sample2 = R"(fun add(a: Int, b: Int): Int {
    a + b!
}
    )";

    std::string sample3 = "fun add(): Int {}";
    std::string sample4 = "fun add() {}";
    std::string sample5 = "fun add()";
    std::string sample6 = "fun a.b(): Int {}";
    std::string sample7 = "extern fun print(s: Str): Non";
    std::string sample8 = "fun add<T>(a: T): T { a + 1! }";
    std::string sample9 = "fun add<T, U>(a: T, b: U): T { a + b! }";
    std::string sample10 = "fun {a: Int, b: Int}.add(): Int { a + b! }";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");
    string_input<> in3(sample3, "input");
    string_input<> in4(sample4, "input");
    string_input<> in5(sample5, "input");
    string_input<> in6(sample6, "input");
    string_input<> in7(sample7, "input");
    string_input<> in8(sample8, "input");
    string_input<> in9(sample9, "input");
    string_input<> in10(sample10, "input");

    EXPECT_TRUE(parse<Function>(in1));
    EXPECT_TRUE(parse<Function>(in2));
    EXPECT_TRUE(parse<Function>(in3));
    EXPECT_FALSE(parse<Function>(in4));
    EXPECT_FALSE(parse<Function>(in5));
    EXPECT_TRUE(parse<Function>(in6));
    EXPECT_TRUE(parse<ExternalFunction>(in7));
    EXPECT_TRUE(parse<Function>(in8));
    EXPECT_TRUE(parse<Function>(in9));
    EXPECT_TRUE(parse<Function>(in10));
}
