#include "gtest/gtest.h"
#include <vector>
#include <list>

using namespace std;

int solution(vector<int> &A);

TEST(add, test1_return_7)
{
    vector<int> input = {9, 3, 9, 3, 9, 7, 9};

    ASSERT_EQ(7, solution(input));
}

TEST(add, test2_return_2)
{
    vector<int> input = {2, 1, 1, 1, 1, 1, 1};

    ASSERT_EQ(2, solution(input));
}

TEST(add, test3_return_3)
{
    vector<int> input = {9, 7, 3, 3, 3, 7, 9};

    ASSERT_EQ(3, solution(input));
}

int solution(vector<int> &A) {
    // TODO: Later, we can implemented sorted tmp to reduce complexity
    list<int> tmp;
    int tmpSize = 0;

    for(auto elem: A)
    {
        if(0 == tmpSize)
        {
            tmp.push_back(elem);
            ++tmpSize;
            continue;
        }

        for(auto it = tmp.begin(); it != tmp.end(); it++)
        {
            if(*it == elem)
            {
                tmp.erase(it);
                --tmpSize;
                break;
            }
            else if(*it > elem)
            {
                if(1 == tmpSize)
                {
                    tmp.push_front(elem);
                }
                else
                {
                    tmp.insert(--it, elem);

                }

                ++tmpSize;
                break;
            }
        }
    }

    return *(tmp.begin());
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}