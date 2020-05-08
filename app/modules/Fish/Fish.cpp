#include "gtest/gtest.h"

#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> &A, vector<int> &B);

TEST(add, test1)
{
    vector<int> input1 = {4, 3, 2, 1, 5};
    vector<int> input2 = {0, 1, 0, 0, 0};

    ASSERT_EQ(2, solution(input1, input2));
}

TEST(add, test2)
{
    vector<int> input1 = {1, 2, 3, 4, 5};
    vector<int> input2 = {1, 1, 0, 0, 0};

    ASSERT_EQ(3, solution(input1, input2));
}

TEST(add, test3)
{
    vector<int> input1 = {6, 2, 3, 4, 5};
    vector<int> input2 = {1, 1, 0, 0, 0};

    ASSERT_EQ(1, solution(input1, input2));
}

TEST(add, test4)
{
    vector<int> input1 = {};
    vector<int> input2 = {};

    ASSERT_EQ(0, solution(input1, input2));
}

TEST(add, test5)
{
    vector<int> input1 = {1, 2, 3};
    vector<int> input2 = {1, 1, 1};

    ASSERT_EQ(3, solution(input1, input2));
}

TEST(add, test6)
{
    vector<int> input1 = {1, 2, 3};
    vector<int> input2 = {0, 0, 0};

    ASSERT_EQ(3, solution(input1, input2));
}

TEST(add, test7)
{
    vector<int> input1 = {1, 2, 3};
    vector<int> input2 = {0, 1, 1};

    ASSERT_EQ(3, solution(input1, input2));
}

TEST(add, test8)
{
    vector<int> input1 = {1000000000, 10000000 , 1000000};
    vector<int> input2 = {1, 0, 0};

    ASSERT_EQ(1, solution(input1, input2));
}

int solution(vector<int> &A, vector<int> &B)
{
    stack<int> upstream;

    int cnt = A.size();

    for(size_t i = 0; i < A.size(); ++i)
    {
        if(B[i] == 0)
        {
            if(upstream.size() > 0 && upstream.top() > A[i])
            {
                --cnt;
                continue;
            }

            while(upstream.size() > 0)
            {
                if(upstream.top() < A[i])
                {
                    upstream.pop();
                    --cnt;
                }
                else
                {
                    --cnt;
                    break;
                }

            }
        }
        else
        {
            upstream.push(A[i]);
        }
    }

    return cnt;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
