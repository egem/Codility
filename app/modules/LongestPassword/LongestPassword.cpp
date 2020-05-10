#include "gtest/gtest.h"

#include <vector>
#include <cstring>

using namespace std;

int solution(string &S);

TEST(add, test1)
{
    string input = "test 5 a0A pass007 ?xy1";

    ASSERT_EQ(7, solution(input));
}

TEST(add, test2)
{
    string input = "1";

    ASSERT_EQ(1, solution(input));
}

TEST(add, test3)
{
    string input = "a";

    ASSERT_EQ(-1, solution(input));
}

TEST(add, test4)
{
    string input = "aa";

    ASSERT_EQ(-1, solution(input));
}

TEST(add, test5)
{
    string input = "aa0";

    ASSERT_EQ(3, solution(input));
}

TEST(add, test6)
{
    string input = "aa?0";

    ASSERT_EQ(-1, solution(input));
}

TEST(add, test7)
{
    string input = "test    5   a0A     pass007   ?xy1";

    ASSERT_EQ(7, solution(input));
}

TEST(add, test8)
{
    string input = "W i k ? 5 + a";

    ASSERT_EQ(1, solution(input));
}

bool isDigit(char c)
{
    if(c >= '0' && c <= '9')
        return true;

    return false;
}

bool isLetter(char c)
{
    if( (c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z'))
        return true;

    return false;
}

int solution(string &S)
{
    bool hasNonAlphaNumericValue = false;
    int numberOfLetters = 0;
    int numberOfDigits = 0;

    int numberOfChar = 0;
    int maxNumberOfChar = 0;

    int N = static_cast<int>(S.size());

    for(int i = 0; i <= N; i++)
    {
        if(S[i] == ' ' || S[i] == '\0')
        {
            if( !hasNonAlphaNumericValue    &&
                (numberOfLetters % 2 == 0)  &&
                (numberOfDigits % 2 == 1) )
            {
                if(numberOfChar > maxNumberOfChar)
                {
                    maxNumberOfChar = numberOfChar;
                }
            }

            hasNonAlphaNumericValue = false;
            numberOfLetters = 0;
            numberOfDigits = 0;
            numberOfChar = 0;
        }
        else
        {
            if(isDigit(S[i]))
                ++numberOfDigits;
            else if(isLetter(S[i]))
                ++numberOfLetters;
            else
                hasNonAlphaNumericValue = true;

            ++numberOfChar;
        }
    }

    return maxNumberOfChar == 0 ? -1 : maxNumberOfChar;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
