#include "gtest/gtest.h"

#include <vector>
#include <cmath>

using namespace std;

int solution2(vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {3, 2, -6, 4, 0};

    ASSERT_EQ(5, solution2(input));
}

TEST(add, test2)
{
    vector<int> input = {3, 2, -1, 4, 0};

    ASSERT_EQ(8, solution2(input));
}

TEST(add, test3)
{
    vector<int> input = {-10, -1};

    ASSERT_EQ(-1, solution2(input));
}

TEST(add, test4)
{
    vector<int> input;
    input.resize(1000000, 1000000);

    ASSERT_EQ(2147483647, solution2(input));
}

TEST(add, test5)
{
    vector<int> input;
    input.resize(1000000, -1000000);

    ASSERT_EQ(-1000000, solution2(input));
}

TEST(add, test6)
{
    vector<int> input = {-10};

    ASSERT_EQ(-10, solution2(input));
}

TEST(add, test7)
{
    vector<int> input = {-10, 1};

    ASSERT_EQ(1, solution2(input));
}

TEST(add, test8)
{
    vector<int> input = {-10, 20, -1, -5, -4, 1};

    ASSERT_EQ(20, solution2(input));
}

TEST(add, test9)
{
    vector<int> input = {-10, 20, -1, -5, -4, 11};

    ASSERT_EQ(21, solution2(input));
}

TEST(add, test10)
{
    vector<int> input = {-10, -20, -1};

    ASSERT_EQ(-1, solution2(input));
}

TEST(add, test11)
{
    vector<int> input = {-10, -20, -1, 5};

    ASSERT_EQ(5, solution2(input));
}

TEST(add, test12)
{
    vector<int> input = {0, 10, 20};

    ASSERT_EQ(30, solution2(input));
}

TEST(add, test13)
{
    vector<int> input = {-1, 10, 20};

    ASSERT_EQ(30, solution2(input));
}

TEST(add, test14)
{
    vector<int> input = {10, -1, 20};

    ASSERT_EQ(29, solution2(input));
}

TEST(add, test15)
{
    vector<int> input = {10, -1, -1};

    ASSERT_EQ(10, solution2(input));
}

TEST(add, test16)
{
    vector<int> input = {10, 0, 1};

    ASSERT_EQ(11, solution2(input));
}

TEST(add, test17)
{
    vector<int> input = {10, -11, 8};

    ASSERT_EQ(10, solution2(input));
}

TEST(add, test18)
{
    vector<int> input = {10, -11, 12};

    ASSERT_EQ(12, solution2(input));
}

int solution(vector<int> &A)
{
    int64_t sum[2] = {A[0], A[0]};
    int part = 0;

    for(size_t i = 1; i < A.size(); ++i)
    {
        if(sum[part] > 2147483647)
            return 2147483647;

        if(sum[part] < 0 && A[i] > sum[part])
        {
            sum[part] = A[i];
        }
        else if(sum[part] < 0 && A[i] < 0)
        {
            continue;
        }
        else if(A[i] >= 0)
        {
            sum[part] += A[i];
        }
        else
        {
            int otherPart = (part + 1) % 2;

            sum[otherPart] = sum[part] + A[i++];

            while(i < A.size())
            {
                if(A[i] > 0 && sum[otherPart] >= 0)
                {
                    sum[otherPart] += A[i];
                    break;
                }
                else if(A[i] > 0 && sum[otherPart] < 0)
                {
                    sum[otherPart] = A[i];
                    break;
                }
                else
                {
                    sum[otherPart] += A[i++];
                }
            }

            if(sum[otherPart] > sum[part])
            {
                part = otherPart;
            }
        }
    }

    return sum[0] > sum[1] ? sum[0] : sum[1];
}
#include <cmath>

int solution2(vector<int> &A)
{
    int64_t maxValue = A[0];

    vector<int64_t> K(A.size());
    K[0] = A[0];

    int N = static_cast<int>(A.size());

    for(int i = 1; i < N; ++i)
    {
        K[i] = max(K[i-1] + A[i], static_cast<int64_t>(A[i]));

        if(K[i] > maxValue)
        {
            maxValue = K[i];
        }

        if(maxValue >= 2147483647)
            return 2147483647;
    }

    return maxValue;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
