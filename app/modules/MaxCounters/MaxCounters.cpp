#include "gtest/gtest.h"
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution2(int N, vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {3, 4, 4, 6, 1, 4, 4};
    vector<int> result = {3, 2, 2, 4, 2};

    ASSERT_EQ(result, solution2(result.size(), input));
}

TEST(add, test2)
{
    vector<int> input = {3, 4, 4, 6, 1, 4, 4};
    vector<int> result = {1};

    ASSERT_EQ(result, solution2(result.size(), input));
}

TEST(add, test3)
{
    vector<int> input = {3, 4, 4, 6, 1, 4, 4};
    vector<int> result = {1};

    ASSERT_EQ(result, solution2(result.size(), input));
}

TEST(add, test4)
{
    vector<int> input = {1, 1, 1, 1, 1, 5};
    vector<int> result = {5, 5};

    ASSERT_EQ(result, solution2(result.size(), input));
}

TEST(add, test5)
{
    vector<int> input = {3, 3, 3, 3, 3, 5};
    vector<int> result = {0, 0};

    ASSERT_EQ(result, solution2(result.size(), input));
}

TEST(add, test6)
{
    vector<int> input = {2, 2, 2, 2, 2};
    vector<int> result = {0, 5};

    ASSERT_EQ(result, solution2(result.size(), input));
}


TEST(add, test7)
{
    vector<int> input = {2, 2, 2, 2, 2, 5};
    vector<int> result = {5, 5};

    ASSERT_EQ(result, solution2(result.size(), input));
}

TEST(add, test8)
{
    vector<int> input = {1, 2, 2, 2, 2, 5, 1, 1, 1, 6, 2};
    vector<int> result = {7, 8, 7};

    ASSERT_EQ(result, solution2(result.size(), input));
}

/* Its complexity is M * N assuming that size of A is M. */
vector<int> solution(int N, vector<int> &A) {
    vector<int> result;
    result.resize(N, 0);
    int max = 0;

    for(unsigned int i = 0; i < A.size(); ++i)
    {
        int elem = A[i];
        if(elem <= N)
        {
            result[elem-1] += 1;

            if(result[elem-1] > max)
            {
                max = result[elem -1];
            }
        }
        else
        {
            fill(result.begin(), result.end(), max);
        }
    }

    return result;
}

/* Its complexity is M + N assuming that size of A is M. */
vector<int> solution2(int N, vector<int> &A) {
    vector<int> result;
    result.resize(N, 0);
    int max = 0;
    int globalMax = 0;

    for(unsigned int i = 0; i < A.size(); ++i)
    {
        int elem = A[i] - 1;
        if(elem < N)
        {
            if(result[elem] < globalMax)
            {
                result[elem] = globalMax + 1;
            }
            else
            {
                result[elem] += 1;
            }

            if(result[elem] > max)
            {
                max = result[elem];
            }
        }
        else
        {
            globalMax = max;
        }
    }

    for(auto it = result.begin(); it < result.end(); ++it)
    {
        if(*it < globalMax)
            *it = globalMax;
    }

    return result;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}