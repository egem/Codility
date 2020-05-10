#include "gtest/gtest.h"

#include <vector>

using namespace std;

int solution(vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {10, 2, 5, 1, 8, 12};

    ASSERT_EQ(4, solution(input));
}

TEST(add, test2)
{
    vector<int> input = {};

    ASSERT_EQ(0, solution(input));
}

TEST(add, test3)
{
    vector<int> input = {1};

    ASSERT_EQ(0, solution(input));
}

TEST(add, test4)
{
    vector<int> input = {1, 2};

    ASSERT_EQ(0, solution(input));
}

TEST(add, test5)
{
    vector<int> input = {1, 2, 3};

    ASSERT_EQ(0, solution(input));
}

TEST(add, test6)
{
    vector<int> input = {4, 1, 2};

    ASSERT_EQ(0, solution(input));
}

TEST(add, test7)
{
    vector<int> input = {4, 2, 5};

    ASSERT_EQ(1, solution(input));
}

TEST(add, test8)
{
    vector<int> input = {4, 4, 1, 2};

    ASSERT_EQ(2, solution(input));
}

TEST(add, test9)
{
    vector<int> input = {4, 4, 2, 3};

    ASSERT_EQ(4, solution(input));
}

TEST(add, test10)
{
    vector<int> input = {4, 4, 4};

    ASSERT_EQ(1, solution(input));
}

TEST(add, test11)
{
    vector<int> input = {4, 4, 4, 4, 4};

    ASSERT_EQ(10, solution(input));
}

TEST(add, test12)
{
    vector<int> input = {4, 4, 4, 4, 4, 4};

    ASSERT_EQ(20, solution(input));
}

#include <algorithm>

// %90
// Failed same value with large size
int solution(vector<int> &A)
{
    sort(A.begin(), A.end());

    int N = static_cast<int>(A.size());

    if(N > 2 && A[0] == A[N-1])
    {
        int result1 = 1;
        int result2 = 1;

        for(int i = N; i > 3; --i)
            result1 *= i;

        for(int i = N-3; i > 0; --i)
            result2 *= i;

        return result1 / result2;
    }

    int cnt = 0;

    for(int i = 0; i < N - 2; ++i)
    {
        int j = 1;

        while(true)
        {
            int k = 1;

            while(true)
            {
                if(A[i] + A[i+j] > A[i+j+k])
                {
                    ++cnt;
                }
                else
                    break;

                ++k;

                if(i+j+k >= N)
                    break;
            }

            ++j;

            if(i+j >= N-1)
                break;
        }
    }

    return cnt;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
