#include "gtest/gtest.h"

#include <vector>

using namespace std;

int solution(vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {1, 5, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2};

    ASSERT_EQ(3, solution(input));
}

TEST(add, test2)
{
    vector<int> input = {0, 1, 0, 3, 4, 5, 4, 7, 1, 9, 1, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 19};

    ASSERT_EQ(4, solution(input));
}

TEST(add, test3)
{
    vector<int> input = {0};

    ASSERT_EQ(0, solution(input));
}

TEST(add, test4)
{
    vector<int> input = {1, 2, 3, 4};

    ASSERT_EQ(0, solution(input));
}

TEST(add, test5)
{
    vector<int> input = {1, 2, 5, 4};

    ASSERT_EQ(1, solution(input));
}

TEST(add, test6)
{
    vector<int> input = {1, 2, 5, 4, 6, 1};

    ASSERT_EQ(2, solution(input));
}

TEST(add, test7)
{
    vector<int> input = {1, 5, 1, 2, 6, 1, 2, 7};

    ASSERT_EQ(2, solution(input));
}

TEST(add, test8)
{
    vector<int> input = {1, 5, 1, 2, 6, 1, 2, 7, 1};

    ASSERT_EQ(3, solution(input));
}

#include <cmath>

// TODO: Need to fix
int solution(vector<int> &A)
{
    if(A.size() < 3)
        return 0;

    vector<int> peaks;

    int N = static_cast<int>(A.size());

    for(int i = 1; i < N - 1; ++i)
    {
        if(A[i] > A[i-1] && A[i] > A[i+1])
        {
            // peak
            peaks.push_back(i);
        }
    }

    int peaksN = static_cast<int>(peaks.size());

    if(peaksN == 0)
    {
        return 0;
    }

    for(int K = peaksN; K > 1; --K)
    {
        int cnt = 1;
        int lastFlag = peaks[0];

        for(int j = 1; j < peaksN; ++j)
        {
            if(peaks[j] - lastFlag >= K)
            {
                ++cnt;
                lastFlag = peaks[j];
            }
        }

        if(cnt == K)
            return cnt;
    }

    return 1;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
