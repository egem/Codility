#include "gtest/gtest.h"

#include <vector>

using namespace std;

int solution2(vector<int> &A, vector<int> &B);

TEST(add, test1)
{
    vector<int> input1 = {1, 3, 7, 9, 9};
    vector<int> input2 = {5, 6, 8, 9, 10};

    ASSERT_EQ(3, solution2(input1, input2));
}

TEST(add, test2)
{
    vector<int> input1 = {9, 9};
    vector<int> input2 = {9, 10};

    ASSERT_EQ(1, solution2(input1, input2));
}

TEST(add, test3)
{
    vector<int> input1 = {1, 6, 8, 10, 1};
    vector<int> input2 = {5, 7, 9, 11, 13};

    ASSERT_EQ(4, solution2(input1, input2));
}

TEST(add, test3m)
{
    vector<int> input1 = {1, 0, 3, 6, 1};
    vector<int> input2 = {5, 7, 9, 11, 13};

    ASSERT_EQ(2, solution2(input1, input2));
}

TEST(add, test4)
{
    vector<int> input1 = {1, 5};
    vector<int> input2 = {5, 7};

    ASSERT_EQ(1, solution2(input1, input2));
}

TEST(add, test5)
{
    vector<int> input1 = {1, 6};
    vector<int> input2 = {5, 7};

    ASSERT_EQ(2, solution2(input1, input2));
}


#include <map>
#include <set>

int solution(vector<int> &A, vector<int> &B)
{
    int N = static_cast<int>(A.size());

    map<int, set<int>> nonoverlappingSet;

    for(int i = 0; i < N - 1; ++i)
    {
        set<int> tmp;
        nonoverlappingSet[i] = move(tmp);
        auto it = nonoverlappingSet.find(i);

        int j = 1;

        while(true)
        {
            if(B[i] < A[i+j])
            {
                it->second.insert(i+j);
            }

            ++j;

            if(i+j >= N)
                break;
        }
    }

    map<int, int> result;
    int max = 0;
    int global_max = 0;

    for(auto it = nonoverlappingSet.rbegin(); it != nonoverlappingSet.rend(); ++it)
    {
        for(auto elem2: it->second)
        {
            if(result.find(elem2) == result.end())
                result[elem2] = 1;

            if(result[elem2] > max)
            {
                max = result[elem2];
                result[it->first] = max;

                if(max > global_max)
                    global_max = max;
            }
        }

        result[it->first]++;
    }

    return global_max + 1;
}

#include <algorithm>

bool isOverlapped(int a1, int b1, int a2, int b2)
{
    if( (a1 >= a2 && a1 <= b2)  ||
        (b1 >= a2 && b1 <= b2)  ||
        (a1 < a2 && b1 > b2)    ||
        (a2 < a1 && b2 > b1))
        return true;

    return false;
}

int solution2(vector<int> &A, vector<int> &B)
{
    int N = static_cast<int>(A.size());

    if(N < 2)
        return N;

    int left = A[N-1], right = B[N-1];
    int cnt = 1;

    for(int i = N-2; i >= 0; --i)
    {
        if(!isOverlapped(left, right, A[i], B[i]))
        {
            ++cnt;
            left = A[i];
            right = B[i];
        }
        else
        {
            left = max(A[i], left);
        }
    }

    return cnt;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
