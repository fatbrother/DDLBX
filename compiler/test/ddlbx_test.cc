#include <gtest/gtest.h>

#include "grammerCP.hpp"

using namespace tao::pegtl;

TEST(grammerCP, basic)
{
    std::string sample1 = "-10.123!";
    std::string sample2 = "\'abcd\n\'";           //string內不能有單引號 註:\n,\t...等特殊符號需加入規則
    std::string sample3 = "true";
    std::string sample4 = "[ 123, 134, 1234 ]";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");
    string_input<> in3(sample3, "input");
    string_input<> in4(sample4, "input");

    EXPECT_TRUE(pegtl::parse<ddlbx::grammer::Number>(in1));
    EXPECT_TRUE(pegtl::parse<ddlbx::grammer::String>(in2));
    EXPECT_TRUE(pegtl::parse<ddlbx::grammer::Boolean>(in3));
    EXPECT_TRUE(pegtl::parse<ddlbx::grammer::List>(in4));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}