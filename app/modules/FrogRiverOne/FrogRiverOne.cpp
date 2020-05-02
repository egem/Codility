#include "gtest/gtest.h"
#include <vector>

using namespace std;

int solution(int X, vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {1, 3, 1, 4, 2, 3, 5, 4};

    ASSERT_EQ(6, solution(5, input));
}

TEST(add, test2)
{
    vector<int> input = {1, 3, 1, 4, 2, 3, 5, 4};

    ASSERT_EQ(-1, solution(7, input));
}

TEST(add, test3)
{
    vector<int> input = {1, 3, 1, 4, 3, 5, 4};

    ASSERT_EQ(-1, solution(5, input));
}

TEST(add, test4)
{
    vector<int> input = {1};

    ASSERT_EQ(-1, solution(2, input));
}

TEST(add, test5)
{
    vector<int> input = {2};

    ASSERT_EQ(-1, solution(2, input));
}

TEST(add, test6)
{
    vector<int> input = {1};

    ASSERT_EQ(0, solution(1, input));
}

TEST(add, test7)
{
    vector<int> input = {1, 3, 1, 4, 3, 5, 4};

    ASSERT_EQ(0, solution(1, input));
}

TEST(add, test8)
{
    vector<int> input = {1, 3, 1, 4, 3, 5, 4, 2};

    ASSERT_EQ(7, solution(4, input));
}

TEST(add, test9)
{
    vector<int> input = {1, 3, 2};

    ASSERT_EQ(2, solution(3, input));
}

TEST(add, test10)
{
    vector<int> input = {1, 2, 3};

    ASSERT_EQ(2, solution(3, input));
}


int solution(int X, vector<int> &A)
{
    vector<bool> tmp;
    int numberOfFound = 0;

    if(static_cast<unsigned int>(X) > A.size())
        return -1;

    tmp.resize(X, false);

    for(unsigned int i = 0; i < A.size(); ++i)
    {
        int elem = A[i];

        if(elem > X)
            continue;

        if(!tmp[elem - 1])
        {
            tmp[elem - 1] = true;
            numberOfFound++;

            if(numberOfFound == X)
            {
                return i;
            }
        }
    }

    return -1;
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}