#include "gtest/gtest.h"

#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <list>

using namespace std;

int solution2(vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {1, 5, 2, 1, 4, 0};

    ASSERT_EQ(11, solution2(input));
}

TEST(add, test2)
{
    vector<int> input = {1, 3, 1, 1};

    ASSERT_EQ(5, solution2(input));
}

TEST(add, test3)
{
    vector<int> input = {1, 3};

    ASSERT_EQ(1, solution2(input));
}

TEST(add, test4)
{
    vector<int> input = {1, 3, 1};

    ASSERT_EQ(3, solution2(input));
}

/* TODO: Correct later */
int solution(vector<int> &A)
{
    #define between(x, a, b) (x >= a && x <= b) ? true : false

    int cnt = 0;

    for(size_t i = 0; i < A.size(); ++i)
    {
        int leftmost = i - A[i];
        int rightmost = i + A[i];

        for(size_t j = i+1; j < A.size(); ++j)
        {
            int leftmost_j = j - A[j];
            int rightmost_j = j+ A[j];

            if( between(leftmost, leftmost_j, rightmost_j) ||
                between(rightmost, leftmost_j, rightmost_j) ||
                (leftmost < leftmost_j && rightmost > rightmost_j)
                )
            {
                ++cnt;

                if(cnt > 10000000)
                    return -1;
            }
        }
    }

    return cnt;
}

// % 81
// Test [1, 2147483647, 0] got 0, expected 2
// Complexity is not good.
int solution2(vector<int> &A)
{
    multimap<int, int> leftRight;

    for(size_t i = 0; i < A.size(); ++i)
    {
        int left = i - A[i];
        int right = i + A[i];

        leftRight.insert(pair<int, int>(left,right));
    }

    multimap<int, int> rightLeft;
    int cnt = 0;

    for(auto elem: leftRight)
    {
        for(auto it = rightLeft.begin(); it != rightLeft.end();)
        {
            if(elem.first > it->first)
            {
                it = rightLeft.erase(it);
            }
            else
            {
                ++cnt;
                ++it;
            }
        }

        rightLeft.insert(std::pair<int, int>(elem.second, elem.first));
    }

    return cnt;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
