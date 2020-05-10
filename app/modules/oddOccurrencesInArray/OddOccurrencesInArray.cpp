#include "gtest/gtest.h"
#include <vector>
#include <list>

using namespace std;

int solution(vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {9, 3, 9, 3, 9, 7, 9};

    ASSERT_EQ(7, solution(input));
}

TEST(add, test2)
{
    vector<int> input = {2, 1, 1, 1, 1, 1, 1};

    ASSERT_EQ(2, solution(input));
}

TEST(add, test3)
{
    vector<int> input = {9, 7, 3, 3, 3, 7, 9};

    ASSERT_EQ(3, solution(input));
}

TEST(add, test4)
{
    vector<int> input = {3, 4, 4};

    ASSERT_EQ(3, solution(input));
}

TEST(add, test5)
{
    vector<int> input = {5, 3, 5, 3, 4};

    ASSERT_EQ(4, solution(input));
}

int solution(vector<int> &A) {
    vector<int> tmp = A;

    sort(tmp.begin(), tmp.end());

    int N = static_cast<int>(tmp.size());

    for(int i = 1; i < N;)
    {
        if(tmp[i] != tmp[i-1])
            return tmp[i-1];

        i += 2;
    }

    return tmp[N-1];
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}