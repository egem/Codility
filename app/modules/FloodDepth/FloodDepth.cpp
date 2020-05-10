
#include "gtest/gtest.h"

#include <vector>

using namespace std;

int solution(vector<int> &A);

#if 0
TEST(add, test1)
{
    vector<int> input = {1, 3, 2, 1, 2, 1, 5, 3, 3, 4, 2};

    ASSERT_EQ(2, solution(input));
}

TEST(add, test2)
{
    vector<int> input = {5, 8};

    ASSERT_EQ(0, solution(input));
}

TEST(add, test3)
{
    vector<int> input = {8, 5};

    ASSERT_EQ(0, solution(input));
}

TEST(add, test4)
{
    vector<int> input = {1, 6, 1, 2, 3, 1, 2, 3, 1, 6};

    ASSERT_EQ(5, solution(input));
}

TEST(add, test5)
{
    vector<int> input = {3, 1, 2};

    ASSERT_EQ(1, solution(input));
}
#endif

#include <cmath>

enum class State
{
    Idle,
    Stable,
    Increasing,
    Decreasing
};

int solution(vector<int> &A)
{
    State currentState = State::Idle;
    State previousState = State::Idle;

    int N = static_cast<int>(A.size());

    if(N < 3)
        return 0;

    int localMin = A[0];
    int localMax1 = A[0], localMax2 = A[0];
    int globalMax1 = A[0], globalMax2 = A[0];

    int minMax = 0;
    int maxDepth = 0;

    for(int i = 0; i < N-1; ++i)
    {
        if(A[i+1] > A[i])
        {
            previousState = currentState;
            currentState = State::Increasing;
        }
        else if(A[i+1] < A[i])
        {
            previousState = currentState;
            currentState = State::Decreasing;
        }
        else
        {
            continue;
        }

        switch (currentState)
        {
            case State::Increasing:
            {
                if(State::Decreasing == previousState)
                {
                    localMin = A[i];
                    localMax1 = localMax2;
                }

                localMax2 = A[i+1];
            }
            break;
            case State::Decreasing:
            {
                if(State::Increasing == previousState)
                {
                    if(localMax1 > globalMax1)
                    {
                        globalMax1 = localMax1;
                    }

                    if(localMax2 > globalMax2)
                    {
                        globalMax2 = localMax2;
                    }
                }

                localMin = A[i+1];
            }

            default:
                break;
        }



        cout << "local: " << localMax1 << " " << localMin << " " << localMax2 << endl;
        cout << "global: " << globalMax1 << " " << localMin << " " << globalMax2 << endl;

        minMax = min(globalMax1, globalMax2);
        int depth = minMax - localMin;

        if(depth > maxDepth)
            maxDepth = depth;
    }

    return maxDepth;
}

// int solution2(vector<int> &A)
// {
//     int N = static_cast<int>(A.size());

//     if(N<3)
//         return 0;

//     int localMin = A[0];
//     int localMax1, localMax2, globalMax1, globalMax2;

//     localMax1 = localMax2 = globalMax1 = globalMax2 = A[0];

//     for(int i = 1; i < N; ++i)
//     {
//         if(A[i] < A[i-1])
//         {
//             localMin = A[i];
//         }
//         else if(A[i] > A[i-1])
//         {
//             localMax2 = A[i];
//         }


//     }
// }


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
