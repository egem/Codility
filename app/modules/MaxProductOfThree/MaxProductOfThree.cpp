#include "gtest/gtest.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {-3, 1, 2, -2, 5, 6};

    ASSERT_EQ(60, solution(input));
}

TEST(add, test2)
{
    vector<int> input = {3, 1, 2, -2, -5, -6};

    ASSERT_EQ(90, solution(input));
}

TEST(add, test3)
{
    vector<int> input = {3, 1, 2, 2, -5, -6};

    ASSERT_EQ(90, solution(input));
}

TEST(add, test4)
{
    vector<int> input = {-3, 1, 2};

    ASSERT_EQ(-6, solution(input));
}

TEST(add, test5)
{
    vector<int> input = {-3, -1, 1, 2};

    ASSERT_EQ(6, solution(input));
}

TEST(add, test6)
{
    vector<int> input = {-3, 1, 1, 2};

    ASSERT_EQ(2, solution(input));
}

TEST(add, test7)
{
    vector<int> input = {-3, -8, -5};

    ASSERT_EQ(-120, solution(input));
}

TEST(add, test8)
{
    vector<int> input = {-3, -8, -5, -1};

    ASSERT_EQ(-15, solution(input));
}

TEST(add, test9)
{
    vector<int> input = {-1, 3, 5, 8};

    ASSERT_EQ(120, solution(input));
}

/* This solution is taken by https://sites.google.com/site/spaceofjameschen/home/codibility/6-3-maxproductofthree */
int solution(vector<int> &A)
{
    sort(A.begin(), A.end());

    int s = int(A.size());

    int m1 = A[s - 1] * A[s- 2] * A[s - 3];
    if ((A[s - 1] < 0) || (A[0] > 0)) return m1;

    int m2 = A[0] * A[1] * A[s - 1];

    return max(m1, m2);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
