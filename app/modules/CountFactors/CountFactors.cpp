#include "gtest/gtest.h"

#include <vector>
#include <map>
#include <cmath>

using namespace std;

int solution2(int N);

TEST(add, test1)
{
    ASSERT_EQ(8, solution2(24));
}

TEST(add, test2)
{
    ASSERT_EQ(9, solution2(36));
}

TEST(add, test3)
{
    ASSERT_EQ(2, solution2(3));
}

TEST(add, test4)
{
    ASSERT_EQ(2, solution2(7));
}

TEST(add, test5)
{
    ASSERT_EQ(4, solution2(14));
}

TEST(add, test6)
{
    ASSERT_EQ(5, solution2(16));
}

int solution(int N)
{
    int result = 1;
    int cnt = 0;

    for(int i = 2; i <= N;)
    {
        if(N % i == 0)
        {
            cnt++;
            N = N / i;
        }
        else
        {
            result *= (cnt + 1);
            cnt = 0;
            ++i;
        }

        if(N == 1)
        {
            result *= (cnt + 1);
            break;
        }
    }

    return result;
}

// This answer is taken from https://github.com/markhary/codility/blob/master/src/CountFactors.cpp
int solution2(int N)
{
    if(N <= 2)
        return N;

    int factor = 2;
    double dSqrtN = sqrt(N);
    int nSqrtN = static_cast<int>(dSqrtN);

    bool perfectSqrt = dSqrtN == static_cast<double>(nSqrtN);

    for(int i = 2; i <= nSqrtN; ++i)
    {
        if(N % i == 0)
        {
            if(perfectSqrt && i == nSqrtN)
                factor += 1;
            else
                factor += 2;
        }

    }

    return factor;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
