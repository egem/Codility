#include "gtest/gtest.h"

#include <vector>

using namespace std;

int solution(vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {0, 1, 0, 1, 1};

    ASSERT_EQ(5, solution(input));
}

TEST(add, test2)
{
    vector<int> input = {0, 1};

    ASSERT_EQ(1, solution(input));
}

TEST(add, test3)
{
    vector<int> input = {0};

    ASSERT_EQ(0, solution(input));
}

// TEST(add, test4)
// {
//     vector<int> input;

//     for(int i = 0; i < 1000000000; ++i)
//     {
//         input.push_back(i%2);
//     }

//     ASSERT_EQ(-1, solution(input));
// }

TEST(add, test5)
{
    vector<int> input = {0, 1, 0};

    ASSERT_EQ(1, solution(input));
}


int solution(vector<int> &A)
{
    int totalOnes = 0;

    std::vector<int> missedOnes;

    for(size_t i = 0; i < A.size(); ++i)
    {
        if(0 == A[i])
        {
            missedOnes.push_back(totalOnes);
        }
        else if(1 == A[i])
        {
            ++totalOnes;
        }
    }

    int count = 0;

    for(auto elem: missedOnes)
    {
        count += (totalOnes - elem);

        if(count > 1000000000)
            return -1;
    }

    return count;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}