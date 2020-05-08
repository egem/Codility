#include "gtest/gtest.h"
#include <vector>

using namespace std;

int solution(vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {};

    ASSERT_EQ(1, solution(input));
}

TEST(add, test2)
{
    vector<int> input = {2, 3, 1, 5};

    ASSERT_EQ(4, solution(input));
}

TEST(add, test3)
{
    vector<int> input = {4, 3, 1, 5};

    ASSERT_EQ(2, solution(input));
}

TEST(add, test4)
{
    vector<int> input = {4, 3, 1, 2};

    ASSERT_EQ(5, solution(input));
}

TEST(add, test5)
{
    vector<int> input = {1};

    ASSERT_EQ(2, solution(input));
}

TEST(add, test6)
{
    vector<int> input = {2};

    ASSERT_EQ(1, solution(input));
}

TEST(add, test7)
{
    vector<int> input = {2, 3 ,5, 4};

    ASSERT_EQ(1, solution(input));
}

int solution(vector<int> &A) {
    if(A.size() == 0)
    {
        return 1;
    }

    vector<bool> tmp;

    tmp.resize(A.size() + 1, false);

    for(auto elem: A)
    {
        tmp[elem-1] = true;
    }

    for(size_t i = 0; i < tmp.size(); ++i)
    {
        if(!tmp[i])
        {
            return i+1;
        }
    }

    return -1;
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}