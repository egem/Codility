#include "gtest/gtest.h"

#include <vector>
using namespace std;

vector<int> solution(vector<int> &A, int K);

TEST(solution, array0_0_0_k_1)
{
    std::vector<int> a{0,0,0};

    std::vector<int> result{0,0,0};

    ASSERT_EQ(result, solution(a,1));
}

TEST(solution, array3_8_9_7_6_k_3)
{
    std::vector<int> a{3, 8, 9, 7, 6};

    std::vector<int> result{9, 7, 6, 3, 8};

    ASSERT_EQ(result, solution(a,3));
}

TEST(solution, array3_8_9_7_6_k_8)
{
    std::vector<int> a{3, 8, 9, 7, 6};

    std::vector<int> result{9, 7, 6, 3, 8};

    ASSERT_EQ(result, solution(a,8));
}

TEST(solution, array1_2_3_4_k_4)
{
    std::vector<int> a{1, 2, 3, 4};

    std::vector<int> result{1, 2, 3, 4};

    ASSERT_EQ(result, solution(a,4));
}

TEST(solution, array1_2_3_4_k_8)
{
    std::vector<int> a{1, 2, 3, 4};

    std::vector<int> result{1, 2, 3, 4};

    ASSERT_EQ(result, solution(a,8));
}

TEST(solution, array1_2_3_4_k_5)
{
    std::vector<int> a{1, 2, 3, 4};

    std::vector<int> result{4, 1, 2, 3};

    ASSERT_EQ(result, solution(a,5));
}

TEST(solution, array1_2_3_4_k_0)
{
    std::vector<int> a{1, 2, 3, 4};

    std::vector<int> result{1, 2, 3, 4};

    ASSERT_EQ(result, solution(a,0));
}

TEST(solution, array_empty_k_5)
{
    std::vector<int> a{};

    std::vector<int> result{};

    ASSERT_EQ(result, solution(a,5));
}

vector<int> solution(vector<int> &A, int K) {
    int size = A.size();

    if(size == 0)
    {
        return A;
    }

    int k = K % size;
    k = k == 0 ? size : k;

    vector<int> result;

    int index = size - k;
    int count = size;

    while(count)
    {
        result.push_back(A[index]);
        index = (index + 1) % size;

        count--;
    }

    return result;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}