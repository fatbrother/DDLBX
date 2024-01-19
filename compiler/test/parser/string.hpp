#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "grammer.hpp"

using namespace tao::pegtl;
using namespace ddlbx::grammer;

TEST(grammer, string) {
    std::string sample1 = "'hello'";
    std::string sample2 = "'hello world'";
    std::string sample3 = "'hello world!'";
    std::string sample4 = "'he??o'";
    std::string sample5 = "'he\\'o'";
    std::string sample6 = "hello";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");
    string_input<> in3(sample3, "input");
    string_input<> in4(sample4, "input");
    string_input<> in5(sample5, "input");
    string_input<> in6(sample6, "input");

    EXPECT_TRUE(parse<String>(in1));
    EXPECT_TRUE(parse<String>(in2));
    EXPECT_TRUE(parse<String>(in3));
    EXPECT_TRUE(parse<String>(in4));
    EXPECT_TRUE(parse<String>(in5));
    EXPECT_FALSE(parse<String>(in6));
}