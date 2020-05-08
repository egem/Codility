#include "gtest/gtest.h"

#include <vector>

using namespace std;

int solution2(vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {3, 2, 6, -1, 4, 5, -1, 2};

    ASSERT_EQ(17, solution2(input));
}

TEST(add, test2)
{
    vector<int> input = {3, -7, 6, -1, 4, 5, -1, 2};

    ASSERT_EQ(15, solution2(input));
}

TEST(add, test3)
{
    vector<int> input = {3, 2, -60, -1, 4, 5, -1, 2};

    ASSERT_EQ(10, solution2(input));
}

TEST(add, test4)
{
    vector<int> input = {5, 17, 0, 3};

    ASSERT_EQ(17, solution2(input));
}

int solution(vector<int> &A)
{
    int a1 = 0, a2 = 1, a3 = 2;
    int sum1 = 0, sum2 = 0;

    int N = static_cast<int>(A.size());

    int tmpSum1 = 0, tmpSum2 = 0;

    for(int i = 3; i < N; ++i)
    {
        tmpSum2 = tmpSum2 + A[i-1];

        if(A[i-1] >= 0)
        {
            if(A[a3] <= 0)
            {
                tmpSum1 = A[a2];

                if(sum2 + tmpSum1 < sum2)
                {
                    a1 = a2;
                    tmpSum1 = 0;
                    sum1 = 0;
                }

                sum1 = sum1 + sum2 + tmpSum1;
                sum2 = 0;

                a2 = a3;
                tmpSum2 -= A[a2];
            }

            sum2 = sum2 + tmpSum2;
            a3 = i;
            tmpSum1 = 0;
            tmpSum2 = 0;
        }
    }

    cout << a1 << " " << a2 << " " << a3 << endl;

    return sum1 + sum2;
}

#include <cmath>

int solution2(vector<int> &A)
{
    vector<int> K1(A.size(), 0);
    vector<int> K2(A.size(), 0);

    int N = static_cast<int>(A.size());

    for(int i = 2; i < N; ++i)
    {
        K1[i] = max(K1[i-1] + A[i - 1], 0);
    }

    for(int i = N - 3; i >= 0; --i)
    {
        K2[i] = max(K2[i+1] + A[i + 1], 0);
    }

    int maxValue = 0;

    for(int i = 1; i < N - 1; ++i)
    {
        maxValue = max(maxValue, K1[i] + K2[i]);
    }

    return maxValue;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
