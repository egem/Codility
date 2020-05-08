#include "gtest/gtest.h"

#include <vector>

using namespace std;

int solution(vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {1, 3, 6, 4, 1, 2};

    ASSERT_EQ(5, solution(input));
}

TEST(add, test2)
{
    vector<int> input = {1, 2, 3};

    ASSERT_EQ(4, solution(input));
}

TEST(add, test3)
{
    vector<int> input = {-1, -3};

    ASSERT_EQ(1, solution(input));
}

TEST(add, test4)
{
    vector<int> input = {0};

    ASSERT_EQ(1, solution(input));
}

TEST(add, test5)
{
    vector<int> input = {1};

    ASSERT_EQ(2, solution(input));
}

TEST(add, test6)
{
    vector<int> input = {1, 2, 2, 2};

    ASSERT_EQ(3, solution(input));
}

TEST(add, test7)
{
    vector<int> input = {2};

    ASSERT_EQ(1, solution(input));
}

TEST(add, test8)
{
    vector<int> input = {0, 1};

    ASSERT_EQ(2, solution(input));
}

int solution(vector<int> &A)
{
    int maxNumber = 0;

    for(auto elem: A)
    {
        if(elem > maxNumber)
        {
            maxNumber = elem;
        }
    }

    if(0 == maxNumber)
        return 1;

    vector<bool> tmp;
    tmp.resize(maxNumber, false);

    for(auto elem: A)
    {
        if(elem > 0 && !tmp[elem - 1])
        {
            tmp[elem - 1] = true;
        }
    }

    unsigned int i = 0;

    for(; i < tmp.size(); ++i)
    {
        if(!tmp[i])
            return i+1;
    }

    return i+1;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}