#include "gtest/gtest.h"

#include <vector>
#include <map>

using namespace std;

int solution(vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {3, 4, 3, 2, 3, -1, 3, 3};

    int result = solution(input);

    ASSERT_EQ(3, input[result]);
}

TEST(add, test2)
{
    vector<int> input = {1, 1, 3};

    int result = solution(input);

    ASSERT_EQ(1, input[result]);
}

TEST(add, test3)
{
    vector<int> input = {1, 1, 3, 3};

    ASSERT_EQ(-1, solution(input));
}

TEST(add, test4)
{
    vector<int> input = {};

    ASSERT_EQ(-1, solution(input));
}

TEST(add, test5)
{
    vector<int> input = {-10, -4, -10};

    int result = solution(input);

    ASSERT_EQ(-10, input[result]);
}

TEST(add, test6)
{
    vector<int> input = {2147483647};

    int result = solution(input);

    ASSERT_EQ((long)2147483647, input[result]);
}

TEST(add, test7)
{
    vector<int> input = {-2147483648};

    int result = solution(input);

    ASSERT_EQ((long)-2147483648, input[result]);
}


int solution(vector<int> &A)
{
    map< int, int> tmp;
    map< int, int> order;

    int index = 0;

    for(auto elem: A)
    {
        if(tmp.find(elem) == tmp.end())
        {
            tmp[elem] = 1;
        }
        else
        {
            tmp[elem] += 1;
        }

        order[elem] = index++;
    }

    bool dominatorFound = false;
    int dominatorValue = -1;
    int thresholdValue = A.size() / 2;

    for(auto elem: tmp)
    {
        if(elem.second > thresholdValue)
        {
            dominatorValue = elem.first;
            dominatorFound = true;
        }
    }

    if(!dominatorFound)
        return -1;

    return order[dominatorValue];
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
