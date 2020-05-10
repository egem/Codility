#include "gtest/gtest.h"

#include <vector>
#include <cmath>

using namespace std;

int solution2(int N, int M);

TEST(add, test1)
{
    ASSERT_EQ(5, solution2(10, 4));
}

TEST(add, test2)
{
    ASSERT_EQ(1, solution2(1, 1));
}

TEST(add, test3)
{
    ASSERT_EQ(1000000000, solution2(1000000000, 1));
}

TEST(add, test4)
{
    ASSERT_EQ(1, solution2(1, 1000000000));
}

TEST(add, test5)
{
    ASSERT_EQ(1, solution2(6, 12));
}

TEST(add, test6)
{
    ASSERT_EQ(3, solution2(3, 2));
}

TEST(add, test7)
{
    ASSERT_EQ(13, solution2(13, 6));
}

TEST(add, test8)
{
    ASSERT_EQ(27, solution2(27, 16));
}

TEST(add, test9)
{
    ASSERT_EQ(947853, solution2(947853, 4453));
}

TEST(add, test10)
{
    ASSERT_EQ(19683, solution2(pow(3,9) * pow(2,14), pow(2,14) * pow(2,14)));
}



int solution(int N, int M)
{
    if(N % M == 0)
        return N/M;

    if(M % N == 0)
        return 1;

    return N / (N % (M % N));
}

// This solution is taken by https://codesays.com/2014/solution-to-chocolates-by-numbers-by-codility/
int gcd(int a, int b)   // Greatest common divisor
{
    if(a % b == 0)
        return b;

    return gcd(b, a % b);
}

int solution2(int N, int M)
{
    int64_t lcm = static_cast<int64_t>(N) * M / gcd(N, M);    // Least Common Multiple

    return lcm / M;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
