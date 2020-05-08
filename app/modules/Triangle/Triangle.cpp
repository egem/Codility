#include "gtest/gtest.h"

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {10, 2, 5, 1, 8, 20};
    ASSERT_EQ(1, solution(input));
}

TEST(add, test2)
{
    vector<int> input = {10, 50, 5, 1};
    ASSERT_EQ(0, solution(input));
}

TEST(add, test3)
{
    vector<int> input = {10, 1};
    ASSERT_EQ(0, solution(input));
}

TEST(add, test4)
{
    vector<int> input = {10};
    ASSERT_EQ(0, solution(input));
}

TEST(add, test5)
{
    vector<int> input = {10, 10, 10, 10, 10};
    ASSERT_EQ(1, solution(input));
}

TEST(add, test6)
{
    vector<int> input = {10, 10, 20};
    ASSERT_EQ(0, solution(input));
}

TEST(add, test7)
{
    vector<int> input = {10, 10, 19};
    ASSERT_EQ(1, solution(input));
}

TEST(add, test8)
{
    vector<int> input = {2147483647, 2147483647, 2147483647};
    ASSERT_EQ(1, solution(input));
}

TEST(add, test9)
{
    vector<int> input = {-2147483648, -2147483648, -2147483648};
    ASSERT_EQ(0, solution(input));
}

TEST(add, test10)
{
    vector<int> input = {-3, -3, -3};
    ASSERT_EQ(0, solution(input));
}

int solution(vector<int> &A)
{
    if(A.size() < 2)
        return 0;

    sort(A.begin(), A.end());

    for(size_t i = 1; i < A.size() - 1; ++i)
    {
        if(static_cast<int64_t>(A[i - 1]) + A[i] > A[i+1])
            return 1;
    }

    return 0;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
