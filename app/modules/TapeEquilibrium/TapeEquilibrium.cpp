#include "gtest/gtest.h"
#include <vector>

using namespace std;

int solution(vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {3, 1, 2, 4, 3};

    ASSERT_EQ(1, solution(input));
}

TEST(add, test2)
{
    vector<int> input = {5, 1};

    ASSERT_EQ(4, solution(input));
}

TEST(add, test3)
{
    vector<int> input = {5, 1, 1};

    ASSERT_EQ(3, solution(input));
}

TEST(add, test4)
{
    vector<int> input = {2, 1, 1};

    ASSERT_EQ(0, solution(input));
}

TEST(add, test5)
{
    vector<int> input = {2, 10, 1};

    ASSERT_EQ(9, solution(input));
}

TEST(add, test6)
{
    vector<int> input = {2, 2};

    ASSERT_EQ(0, solution(input));
}

TEST(add, test7)
{
    vector<int> input = {2, 3};

    ASSERT_EQ(1, solution(input));
}

TEST(add, test8)
{
    vector<int> input = {3, 2};

    ASSERT_EQ(1, solution(input));
}


int solution(vector<int> &A)
{
    #define abs(diff) (diff) > 0 ? (diff) : (diff) * (-1)

    int leftSum = A[0];
    int rightSum = 0;

    for(unsigned int i = 1; i < A.size(); ++i)
    {
        rightSum += A[i];
    }

    int mindiff = abs(leftSum - rightSum);

    for(unsigned int i = 1; i < A.size() - 1; ++i)
    {
        leftSum += A[i];
        rightSum -= A[i];

        int diff = abs(leftSum - rightSum);

        if( diff < mindiff)
        {
            mindiff = diff;
        }
    }

    return mindiff;
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}