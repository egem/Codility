#include "gtest/gtest.h"

#include <vector>

using namespace std;

int solution(vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {-5, -3, -1, 0, 3, 6};

    ASSERT_EQ(5, solution(input));
}

TEST(add, test2)
{
    vector<int> input = {-5, -3, -1, 0};

    ASSERT_EQ(4, solution(input));
}

TEST(add, test3)
{
    vector<int> input = {-5, -3, -1};

    ASSERT_EQ(3, solution(input));
}

TEST(add, test4)
{
    vector<int> input = {1, 3, 5};

    ASSERT_EQ(3, solution(input));
}

TEST(add, test5)
{
    vector<int> input = {-3, 1, 3, 5, 20, 30};

    ASSERT_EQ(5, solution(input));
}

TEST(add, test6)
{
    vector<int> input = {1};

    ASSERT_EQ(1, solution(input));
}

TEST(add, test7)
{
    vector<int> input = {0};

    ASSERT_EQ(1, solution(input));
}

TEST(add, test8)
{
    vector<int> input = {-1};

    ASSERT_EQ(1, solution(input));
}

TEST(add, test9)
{
    vector<int> input = {-5, -4, -1, 2, 3, 6, 7};

    ASSERT_EQ(7, solution(input));
}

TEST(add, test10)
{
    vector<int> input = {1, 1};

    ASSERT_EQ(1, solution(input));
}

#include <cmath>
#include <set>

int solution(vector<int> &A)
{
    set<int> numbers;

    for(auto& elem: A)
    {
        numbers.insert(abs(elem));
    }

    return numbers.size();
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
