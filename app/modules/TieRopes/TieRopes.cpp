#include "gtest/gtest.h"

#include <vector>

using namespace std;

int solution(int K, vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {1, 2, 3, 4, 1, 1, 3};

    ASSERT_EQ(3, solution(4, input));
}

TEST(add, test2)
{
    vector<int> input = {1};

    ASSERT_EQ(0, solution(4, input));
}

TEST(add, test3)
{
    vector<int> input = {1};

    ASSERT_EQ(1, solution(1, input));
}

TEST(add, test4)
{
    vector<int> input = {1, 4, 1, 3, 5, 1};

    ASSERT_EQ(3, solution(4, input));
}

TEST(add, test5)
{
    vector<int> input = {1000000000, 1000000000-1, 1000000000-1, 1, 1000000000-1};

    ASSERT_EQ(3, solution(1000000000, input));
}

TEST(add, test6)
{
    vector<int> input = {1, 1, 1, 1, 1, 1, 1, 1, 1};

    ASSERT_EQ(0, solution(10, input));
}

int solution(int K, vector<int> &A)
{
    int N = static_cast<int>(A.size());
    int cnt = 0;
    int64_t sum = 0;

    for(int i = 0; i < N; ++i)
    {
        if(A[i] >= K)
        {
            ++cnt;
            sum = 0;
        }
        else
        {
            if(A[i] + sum >= K)
            {
                ++cnt;
                sum = 0;
            }
            else
            {
                sum += A[i];
            }
        }
    }

    return cnt;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
