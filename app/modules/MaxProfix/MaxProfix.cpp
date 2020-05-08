#include "gtest/gtest.h"

#include <vector>

using namespace std;

int solution2(vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {23171, 21011, 21123, 21366, 21013, 21367};

    ASSERT_EQ(356, solution2(input));
}

TEST(add, test2)
{
    vector<int> input = {5, 4, 3, 2, 1};

    ASSERT_EQ(0, solution2(input));
}

TEST(add, test3)
{
    vector<int> input = {1, 2, 3, 0, 4};

    ASSERT_EQ(4, solution2(input));
}

TEST(add, test4)
{
    vector<int> input = {10, 20, 30, 15, 25};

    ASSERT_EQ(20, solution2(input));
}

TEST(add, test5)
{
    vector<int> input = {};

    ASSERT_EQ(0, solution2(input));
}

TEST(add, test6)
{
    vector<int> input = {10};

    ASSERT_EQ(0, solution2(input));
}

TEST(add, test7)
{
    vector<int> input = {10, 20, 30, 15, 50};

    ASSERT_EQ(40, solution2(input));
}

TEST(add, test8)
{
    vector<int> input = {10, 20, 30, 5, 50};

    ASSERT_EQ(45, solution2(input));
}

TEST(add, test9)
{
    vector<int> input = {10, 20, 30, 20, 10};

    ASSERT_EQ(20, solution2(input));
}

TEST(add, test10)
{
    vector<int> input = {200000, 0, 200000};

    ASSERT_EQ(200000, solution2(input));
}


int solution(vector<int> &A)
{
    if(A.size() == 0)
        return 0;

    int minValue[2] = {A[0], A[0]};
    int profit[2] = {0, 0};

    int partition = 0;

    for(size_t i = 1; i < A.size(); ++i)
    {
        int diff = A[i] - minValue[partition];

        if(profit[partition] < diff)
        {
            profit[partition] = diff;
        }

        if(A[i] < minValue[partition])
        {
            partition = (partition + 1) % 2;
            minValue[partition] = A[i];
        }
    }

    return profit[0] > profit[1] ? profit[0] : profit[1];
}

int solution2(vector<int> &A)
{
    int N = static_cast<int>(A.size());
    vector<int> profit(A.size(), 0);
    int maxValue = 0;

    for(int i = 1; i < N; ++i)
    {
        int diff = A[i] - A[i-1];

        profit[i] = max(diff + profit[i-1], 0);

        if(profit[i] > maxValue)
        {
            maxValue = profit[i];
        }
    }

    return maxValue;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
