#include "gtest/gtest.h"

#include <vector>
#include <set>

using namespace std;

int solution(vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {2, 1, 1, 2, 3, 1};

    ASSERT_EQ(3, solution(input));
}

TEST(add, test2)
{
    vector<int> input = {2};

    ASSERT_EQ(1, solution(input));
}

TEST(add, test3)
{
    vector<int> input = {2, 2, 2, 2};

    ASSERT_EQ(1, solution(input));
}

TEST(add, test4)
{
    vector<int> input = {};

    ASSERT_EQ(0, solution(input));
}

TEST(add, test5)
{
    vector<int> input = {-1, -1, -3, 0};

    ASSERT_EQ(3, solution(input));
}

int solution(vector<int> &A)
{
    set<int> uniqueValues;

    for(auto elem: A)
    {
        uniqueValues.insert(elem);
    }

    return uniqueValues.size();
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
