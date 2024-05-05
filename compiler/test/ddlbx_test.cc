#include <gtest/gtest.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    // test grammer first
    ::testing::GTEST_FLAG(filter) = "Grammar*";
    int ret = RUN_ALL_TESTS();
    if (ret != 0) {
        return ret;
    }
    // test code genner
    ::testing::GTEST_FLAG(filter) = "CodeGenner*";
    return RUN_ALL_TESTS();
}