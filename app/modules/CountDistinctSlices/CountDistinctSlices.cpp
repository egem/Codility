#include "gtest/gtest.h"

#include <vector>

using namespace std;

int solution2(int M, vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {3, 4, 5, 5, 2};

    ASSERT_EQ(9, solution2(6, input));
}

TEST(add, test2)
{
    vector<int> input = {0, 0, 0, 0};

    ASSERT_EQ(4, solution2(0, input));
}

TEST(add, test3)
{
    vector<int> input = {1, 1};

    ASSERT_EQ(2, solution2(1, input));
}

TEST(add, test4)
{
    vector<int> input = {0};

    ASSERT_EQ(1, solution2(100000, input));
}

#include <algorithm>

int solution(int M, vector<int> &A)
{
    if(M == 0 || A.size() == 1)
        return 1;

    vector<bool> status(M + 1, false);
    int64_t distinctSlices = 0;

    int cnt = 0;

    for(auto& elem: A)
    {
        if(!status[elem])
        {
            ++cnt;
            status[elem] = true;
        }
        else
        {
            distinctSlices += (cnt * (cnt + 1))/2;
            cnt = 0;
            fill(status.begin(), status.end(), false);
        }
    }

    ++cnt;
    distinctSlices += (cnt * (cnt + 1))/2;

    return distinctSlices > 1000000000 ? 1000000000 : static_cast<int>(distinctSlices);
}

#include <set>

// %30
int solution2(int M, vector<int> &A)
{
    (void)M;

    set<int> slice;

    int districtNumber = 0;

    for(auto& elem: A)
    {
        if(slice.find(elem) == slice.end())
        {
            slice.insert(elem);
        }
        else
        {
            districtNumber += ((slice.size() + 1) * slice.size()) / 2;
            slice.clear();
            slice.insert(elem);
        }
    }

    districtNumber += ((slice.size() + 1) * slice.size()) / 2;

    return districtNumber;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
