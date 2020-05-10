
#include "gtest/gtest.h"

#include <vector>

using namespace std;

int solution(int N);

TEST(add, test1)
{
    ASSERT_EQ(2, solution(9));
}

TEST(add, test2)
{
    ASSERT_EQ(4, solution(529));
}

TEST(add, test3)
{
    ASSERT_EQ(4, solution(0b100001000100));
}

TEST(add, test4)
{
    ASSERT_EQ(0, solution(0b100));
}

TEST(add, test5)
{
    ASSERT_EQ(2, solution(0b1001000));
}

TEST(add, test6)
{
    ASSERT_EQ(0, solution(0b1111));
}

TEST(add, test7)
{
    ASSERT_EQ(1, solution(0b101));
}

TEST(add, test8)
{
    ASSERT_EQ(5, solution(1041));
}

int solution(int N)
{
    int tmp = N;

    bool firstOneFound = false;
    int cnt = 0;
    int max = 0;

    while(tmp > 0)
    {
        int rightBit = tmp % 2;

        if(rightBit == 1 && !firstOneFound)
        {
            firstOneFound = true;
        }
        else if(rightBit == 1)
        {
            if(cnt > max)
                max = cnt;

            cnt = 0;
        }
        else if(rightBit == 0 && firstOneFound)
        {
            ++cnt;
        }

        tmp = tmp / 2;
    }

    return max;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
