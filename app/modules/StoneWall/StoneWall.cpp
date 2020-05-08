#include "gtest/gtest.h"

#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> &H);

TEST(add, test1)
{
    vector<int> input = {8, 8, 5, 7, 9, 8, 7, 4, 8};

    ASSERT_EQ(7, solution(input));
}

int solution(vector<int> &H)
{
    // Problem description is not clear so I don't understand the question
    // I mostly get the answer from
    // https://medium.com/a-layman/the-practicing-of-the-codility-lesson-6-10-f06f439d74ce
    stack<int> tmp;
    int cnt = 0;

    for(auto elem: H)
    {
        while(tmp.size() > 0 && tmp.top() > elem)
        {
            tmp.pop();
        }

        if(tmp.size() == 0 || tmp.top() != elem)
        {
            tmp.push(elem);
            ++cnt;
        }
    }

    return cnt;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
