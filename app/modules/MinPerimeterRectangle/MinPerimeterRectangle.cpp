#include "gtest/gtest.h"

#include <vector>
#include <cmath>

using namespace std;

int solution(int N);

TEST(add, test1)
{
    ASSERT_EQ(22, solution(30));
}

TEST(add, test2)
{
    ASSERT_EQ(20, solution(25));
}

TEST(add, test3)
{
    ASSERT_EQ(4, solution(1));
}

TEST(add, test4)
{
    ASSERT_EQ(28, solution(48));
}


int solution(int N)
{
    double dSqrtN = sqrt(N);
    int nSqrtN = static_cast<int>(dSqrtN);

    if(dSqrtN == static_cast<double>(nSqrtN))
    {
        return dSqrtN * 4;
    }
    else
    {
        int side1 = nSqrtN;
        int side2;

        while(true)
        {
            if(N % side1 == 0)
            {
                break;
            }

            --side1;
        }

        side2 = N / side1;

        return (side1 + side2) * 2;
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
