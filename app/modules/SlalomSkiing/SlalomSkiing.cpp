#include "gtest/gtest.h"

#include <vector>

using namespace std;

int solution();

TEST(add, test1)
{
    ASSERT_EQ(-1, solution());
}

int solution()
{
    return -1;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
