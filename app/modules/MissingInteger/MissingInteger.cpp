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
    vector<int> input = {1,1,1,1,1,1,1,1,1};

    ASSERT_EQ(2, solution(input));
}

TEST(add, test6)
{
    vector<int> input = {1, 3, 4};

    ASSERT_EQ(2, solution(input));
}

TEST(add, test7)
{
    vector<int> input = {1};

    ASSERT_EQ(2, solution(input));
}

int solution(vector<int> &A) {
    int maxNumber = 0;

    for(auto elem: A)
    {
        if(elem > maxNumber)
            maxNumber = elem;
    }

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

    return i + 1;
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}