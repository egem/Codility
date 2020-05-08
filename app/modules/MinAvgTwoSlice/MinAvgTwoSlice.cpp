#include "gtest/gtest.h"

#include <vector>

using namespace std;

int solution2(vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {4, 2, 2, 5, 1, 5, 8};
    ASSERT_EQ(1, solution2(input));
}

TEST(add, test2)
{
    vector<int> input = {4, 2};
    ASSERT_EQ(0, solution2(input));
}

TEST(add, test3)
{
    vector<int> input = {1, 5, 2, 4, 7, 1};
    ASSERT_EQ(0, solution2(input));
}

TEST(add, test4)
{
    vector<int> input = {10, 1, 5, 2, 4, 7, 1};
    ASSERT_EQ(1, solution2(input));
}

TEST(add, test5)
{
    vector<int> input = {5, 1, 2, 4, 7, 1};
    ASSERT_EQ(1, solution2(input));
}

TEST(add, test6)
{
    vector<int> input = {1, 2, 4, 7, 1, 2};
    ASSERT_EQ(0, solution2(input));
}

TEST(add, test7)
{
    vector<int> input = {10, 1, 5, 8};
    ASSERT_EQ(1, solution2(input));
}

TEST(add, test8)
{
    vector<int> input = {1, 2, 3};
    ASSERT_EQ(0, solution2(input));
}

int solution(vector<int> &A) {

    if(A.size() == 2)
    {
        return 0;
    }

    vector<int> tmp;

    for(size_t i = 0; i < A.size() - 1; ++i)
    {
        tmp.push_back((A[i] + A[i+1]) / 2);
    }

    int minValue = tmp[0];
    int minIndex = 0;

    for(size_t i = 1; i < tmp.size(); ++i)
    {
        if(tmp[i] < minValue)
        {
            minIndex = i;
            minValue = tmp[i];
        }

    }

    return minIndex;
}

int solution2(vector<int> &A) {
    vector<int> pre_sum(A.size());
    int pre_s = 0;

    for (size_t i = 0; i < A.size(); i++) {
            pre_s += A[i];
            pre_sum[i] = pre_s;
        }

    int start = 0;
    int end = 1;
    int min_start = start;
    double min_avg = double(pre_sum[end] - pre_sum[start] + A[start]) / (end - start + 1);

    for (size_t i = 1; i < A.size(); i++) {
    double avg = double(pre_sum[i] - pre_sum[start] + A[start]) / (i - start + 1);

    if (avg < min_avg) {
                min_avg = avg;
                min_start = start;
            }

    if (A[i] < min_avg) {
                start = i;
            }

        }

    return min_start;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}