#include "gtest/gtest.h"

int add(int a, int b)
{
    return a+b;
}

TEST(add, success)
{
    ASSERT_EQ(4, add(2,2));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}