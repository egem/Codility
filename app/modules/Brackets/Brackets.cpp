#include "gtest/gtest.h"

#include <stack>
#include <map>

#include <cstring>

using namespace std;

int solution(string &S);

TEST(add, test1)
{
    string input = "{[()()]}";

    ASSERT_EQ(1, solution(input));
}

TEST(add, test2)
{
    string input = "{[(()]}";

    ASSERT_EQ(0, solution(input));
}

TEST(add, test3)
{
    string input = "";

    ASSERT_EQ(1, solution(input));
}

TEST(add, test4)
{
    string input = "(((";

    ASSERT_EQ(0, solution(input));
}

TEST(add, test5)
{
    string input = "(";

    ASSERT_EQ(0, solution(input));
}

TEST(add, test6)
{
    string input = ")";

    ASSERT_EQ(0, solution(input));
}

TEST(add, test7)
{
    string input = "((()))";

    ASSERT_EQ(1, solution(input));
}

TEST(add, test8)
{
    string input = "(]";

    ASSERT_EQ(0, solution(input));
}

TEST(add, test9)
{
    string input = "]()[";

    ASSERT_EQ(0, solution(input));
}

TEST(add, test10)
{
    string input = "]()";

    ASSERT_EQ(0, solution(input));
}

int solution(string &S)
{
    std::map<char, char> pairs = {
        std::pair<char, char>(')', '('),
        std::pair<char, char>(']', '['),
        std::pair<char, char>('}', '{')
    };

    stack<char> tmp;

    for(auto elem: S)
    {
        auto it = pairs.find(elem);

        if(it != pairs.end() && tmp.size() > 0 && tmp.top() == it->second)
        {
            tmp.pop();
        }
        else
        {
            tmp.push(elem);
        }
    }

    return tmp.size() == 0;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
