#include "gtest/gtest.h"

#include <vector>

using namespace std;

int solution(vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {4, 2, 2, 5, 1, 5, 8};
    ASSERT_EQ(1, solution(input));
}

TEST(add, test2)
{
    vector<int> input = {4, 2};
    ASSERT_EQ(0, solution(input));
}

TEST(add, test3)
{
    vector<int> input = {1, 5, 2, 4, 7, 1};
    ASSERT_EQ(0, solution(input));
}

TEST(add, test4)
{
    vector<int> input = {10, 1, 5, 2, 4, 7, 1};
    ASSERT_EQ(1, solution(input));
}

TEST(add, test5)
{
    vector<int> input = {5, 1, 2, 4, 7, 1};
    ASSERT_EQ(1, solution(input));
}

TEST(add, test6)
{
    vector<int> input = {1, 2, 4, 7, 1, 2};
    ASSERT_EQ(0, solution(input));
}

TEST(add, test7)
{
    vector<int> input = {10, 1, 5, 8};
    ASSERT_EQ(1, solution(input));
}

TEST(add, test8)
{
    vector<int> input = {1, 2, 3};
    ASSERT_EQ(0, solution(input));
}

int solution(vector<int> &A) {

    if(A.size() == 2)
    {
        return 0;
    }

    vector<int> tmp;

    for(size_t i = 0; i < A.size() - 1; ++i)
    {
        tmp.push_back((A[i] + A[i+1]) / 2);
    }

    int minValue = tmp[0];
    int minIndex = 0;

    for(size_t i = 1; i < tmp.size(); ++i)
    {
        if(tmp[i] < minValue)
        {
            minIndex = i;
            minValue = tmp[i];
        }

    }

    return minIndex;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}