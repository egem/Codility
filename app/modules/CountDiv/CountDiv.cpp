#include "gtest/gtest.h"

#include <vector>

using namespace std;

int solution2(int A, int B, int K);

TEST(add, test1)
{
    ASSERT_EQ(3, solution2(6, 11, 2));
}

TEST(add, test2)
{
    ASSERT_EQ(4, solution2(6, 12, 2));
}

TEST(add, test3)
{
    ASSERT_EQ(2, solution2(6, 12, 6));
}

TEST(add, test4)
{
    ASSERT_EQ(3, solution2(6, 12, 3));
}

TEST(add, test5)
{
    ASSERT_EQ(1, solution2(6, 12, 7));
}

TEST(add, test6)
{
    ASSERT_EQ(0, solution2(6, 12, 13));
}

TEST(add, test7)
{
    ASSERT_EQ(1, solution2(6, 25, 13));
}

TEST(add, test8)
{
    ASSERT_EQ(1, solution2(1, 13, 7));
}

TEST(add, test9)
{
    ASSERT_EQ(1, solution2(12, 25, 13));
}

TEST(add, test10)
{
    ASSERT_EQ(0, solution2(1, 12, 13));
}

TEST(add, test11)
{
    ASSERT_EQ(1, solution2(6, 8, 7));
}

TEST(add, test12)
{
    ASSERT_EQ(1, solution2(6, 8, 6));
}

TEST(add, test13)
{
    ASSERT_EQ(1, solution2(6, 8, 8));
}

TEST(add, test14)
{
    ASSERT_EQ(3, solution2(6, 8, 1));
}

TEST(add, test16)
{
    ASSERT_EQ(15, solution2(6, 20, 1));
}

TEST(add, test17)
{
    ASSERT_EQ(20, solution2(11, 345, 17));
}

int solution(int A, int B, int K) {
    int diff = B - A;

    if(K > diff && K >= A && K <= B)
        return 1;

    int number = diff / K;

    number = A % K == 0 ? number + 1 : number;

    return number;
}

int solution2(int A, int B, int K)
{
    int before = (A - 1) / K;
    int after = B / K;

    return after - before;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}