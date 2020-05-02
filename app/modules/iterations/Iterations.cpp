#include "gtest/gtest.h"
#include <iostream>

#include <vector>

void getRightMostBinaryDigit(int input, std::vector<int>& result)
{
    if(input == 0)
    {
        return;
    }

    int rightDigit = input % 2;
    result.push_back(rightDigit);

    input = input >> 1;

    getRightMostBinaryDigit(input, result);
}

int solution(int N)
{
    std::vector<int> result;

    getRightMostBinaryDigit(N, result);

    bool firstOneEncountered = false;
    int maxBinaryGap = 0;
    int binaryGap = 0;

    for(auto it= result.rbegin(); it != result.rend(); it++)
    {
        if(1 == *it && !firstOneEncountered)
        {
            firstOneEncountered = true;

            binaryGap = 0;
        }
        else if(0 == *it && firstOneEncountered)
        {
            ++binaryGap;
        }
        else if(1 == *it && firstOneEncountered)
        {
            if(binaryGap > maxBinaryGap)
            {
                maxBinaryGap = binaryGap;
            }

            binaryGap = 0;
        }
    }

    return maxBinaryGap;
}

TEST(solution, testcase_9)
{
    ASSERT_EQ(2, solution(9));
}

TEST(solution, testcase_1041)
{
    ASSERT_EQ(5, solution(1041));
}

TEST(solution, testcase_32)
{
    ASSERT_EQ(0, solution(32));
}

TEST(solution, testcase_529)
{
    ASSERT_EQ(4, solution(529));
}

TEST(solution, testcase_0)
{
    ASSERT_EQ(0, solution(0));
}

TEST(solution, testcase_15)
{
    ASSERT_EQ(0, solution(15));
}

TEST(solution, testcase_20)
{
    ASSERT_EQ(1, solution(20));
}

TEST(solution, testcase_1376796946)
{
    ASSERT_EQ(5, solution(1376796946));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}