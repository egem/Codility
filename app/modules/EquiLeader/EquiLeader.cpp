#include "gtest/gtest.h"

#include <vector>
#include <map>

using namespace std;

int solution(vector<int> &A);

TEST(add, test1)
{
    vector<int> input = {4, 3, 4, 4, 4, 2};

    ASSERT_EQ(2, solution(input));
}

TEST(add, test2)
{
    vector<int> input = {4};

    ASSERT_EQ(0, solution(input));
}

TEST(add, test3)
{
    vector<int> input = {4, 4};

    ASSERT_EQ(1, solution(input));
}

TEST(add, test4)
{
    vector<int> input = {4, 10, 2, 4, 4};

    ASSERT_EQ(0, solution(input));
}

TEST(add, test5)
{
    vector<int> input = {4, 4, 4};

    ASSERT_EQ(2, solution(input));
}

TEST(add, test6)
{
    vector<int> input = {4, 4, 4, 4};

    ASSERT_EQ(3, solution(input));
}

TEST(add, test7)
{
    vector<int> input = {1, 4, 4, 4, 4};

    ASSERT_EQ(2, solution(input));
}

TEST(add, test8)
{
    vector<int> input = {1000000000, 1000000000};

    ASSERT_EQ(1, solution(input));
}

TEST(add, test9)
{
    vector<int> input = {1, 2, 1, 1, 2, 1};

    ASSERT_EQ(3, solution(input));
}

int solution(vector<int> &A)
{
    if(A.size() < 1)
    {
        return 0;
    }

    map< int, vector<int> > locations;

    for(size_t i = 0; i < A.size(); ++i)
    {
        if(locations.find(A[i]) == locations.end())
        {
            vector<int> tmp;
            tmp.push_back(i);
            locations[A[i]] = std::move(tmp);
        }
        else
        {
            locations[A[i]].push_back(i);
        }
    }

    vector<int> leaderVector;
    int leader = 0;

    for(auto& elem: locations)
    {
        if(elem.second.size() > leaderVector.size())
        {
            leaderVector = elem.second;
            leader = elem.first;
        }
    }

    int numberOfOccurrencesLeft = 0;
    int cnt = 0;

    for(size_t i = 0; i < leaderVector.size() - 1; ++i)
    {
        ++numberOfOccurrencesLeft;
        int numberOfOccurrencesRight = leaderVector.size() - numberOfOccurrencesLeft;
        int numbersRight = A.size() - leaderVector[i] - 1;

        bool leaderInLeft = numberOfOccurrencesLeft > ((leaderVector[i]+1)/2);
        bool leaderInRight = numberOfOccurrencesRight > (numbersRight/2);

        if( leaderInLeft && leaderInRight)
        {
            ++cnt;
        }
    }

    bool leaderLeft = (leaderVector.size() - 1) > ((A.size()-1) / 2);
    bool lastElementLeader = leaderVector[leaderVector.size() - 1] == static_cast<int>(A.size() - 1);
    bool sizeGreaterOne = A.size() > 1;
    bool hasAlreadyCounted = leaderVector[leaderVector.size() - 1] == (leaderVector[leaderVector.size() - 2] + 1);

    if(leaderLeft && lastElementLeader && sizeGreaterOne && !hasAlreadyCounted)
        ++cnt;

    return cnt;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
