#include <gtest/gtest.h>

TEST(SampleTest, AssertionTrue) {
    EXPECT_EQ(1, 1);
}

TEST(SampleTest, MathWorks) {
    EXPECT_TRUE(2 + 2 == 4);
}