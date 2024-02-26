#define _IMPLEMENTATION_
#include "common.h"
#include "gtest/gtest.h"

// Solution
class Solution
{
public:
    // todo
};

Solution s;

TEST(case1, test1)
{
    // EXPECT_EQ(5, sum(2, 3)); // 求合2+3=5
    // EXPECT_NE(3, sum(3, 4)); // 求合3+4 != 3
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
