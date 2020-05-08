#include "gtest/gtest.h"
#include <vector>

using namespace std;

int solution(vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {4, 1, 3, 2};
    ASSERT_EQ(1, solution(input));
}

TEST(add, test2)
{
    vector<int> input = {4, 1, 3};
    ASSERT_EQ(0, solution(input));
}

TEST(add, test3)
{
    vector<int> input = {1};
    ASSERT_EQ(1, solution(input));
}

TEST(add, test4)
{
    vector<int> input = {6};
    ASSERT_EQ(0, solution(input));
}

TEST(add, test5)
{
    vector<int> input = {7, 1 , 2};
    ASSERT_EQ(0, solution(input));
}

TEST(add, test6)
{
    vector<int> input = {1, 2, 3, 3};
    ASSERT_EQ(0, solution(input));
}

TEST(add, test7)
{
    vector<int> input = {2, 2, 3};
    ASSERT_EQ(0, solution(input));
}

TEST(add, test8)
{
    vector<int> input = {1, 2, 2};
    ASSERT_EQ(0, solution(input));
}

TEST(add, test9)
{
    vector<int> input = {100000000, 2, 2};
    ASSERT_EQ(0, solution(input));
}

TEST(add, test10)
{
    vector<int> input = {10, 5, 4, 3, 7, 8, 2, 9, 1, 6};
    ASSERT_EQ(1, solution(input));
}

int solution(vector<int> &A) {
    vector<bool> tmp;
    tmp.resize(A.size(), false);

    for(auto elem: A)
    {
        if(elem > static_cast<int>(A.size()))
            return 0;

        if(!tmp[elem - 1])
        {
            tmp[elem - 1] = true;
        }
        else
        {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}