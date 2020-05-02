#include "gtest/gtest.h"

int solution(int X, int Y, int D);

TEST(add, test1)
{
    ASSERT_EQ(3, solution(10, 85, 30));
}

TEST(add, test2)
{
    ASSERT_EQ(3, solution(10, 99, 30));
}

TEST(add, test3)
{
    ASSERT_EQ(4, solution(10, 101, 30));
}

TEST(add, test4)
{
    ASSERT_EQ(3, solution(10, 100, 30));
}

TEST(add, test5)
{
    ASSERT_EQ(2, solution(1, 3, 1));
}

TEST(add, test6)
{
    ASSERT_EQ(3, solution(1, 7, 2));
}

TEST(add, test7)
{
    ASSERT_EQ(1, solution(1, 7, 20));
}

TEST(add, test8)
{
    ASSERT_EQ(1, solution(2, 7, 5));
}

TEST(add, test9)
{
    ASSERT_EQ(1, solution(1, 7, 7));
}

int solution(int X, int Y, int D) {
    int totalDistance = Y - X;
    int numberOfJump = totalDistance / D;

    numberOfJump = totalDistance == numberOfJump * D ? numberOfJump : numberOfJump + 1;

    return numberOfJump;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}