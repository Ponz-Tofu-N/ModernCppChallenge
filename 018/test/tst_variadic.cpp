#include <gtest/gtest.h>
#include <functional>
#include "../variadic.h"

TEST(TstVariadic, minimum)
{
    EXPECT_EQ(1, minimum(1, 2, 3, 4, 5, 6));
    EXPECT_EQ(1, minimum(2, 3, 4, 1, 5, 6));
    EXPECT_EQ(1, minimum(2, 3, 4, 5, 6, 1));
}

TEST(TstVariadic, functionalCompareLess)
{
    EXPECT_EQ(2, functionalCompare(std::less<>(), 2, 3, 4, 5, 6));
    EXPECT_EQ(1, functionalCompare(std::less<>(), 2, 3, 4, 1, 5, 6));
    EXPECT_EQ(1, functionalCompare(std::less<>(), 2, 3, 4, 5, 6, 1));
}

TEST(TstVariadic, functionalCompareGreater)
{
    EXPECT_EQ(6, functionalCompare(std::greater<>(), 2, 3, 4, 5, 6));
    EXPECT_EQ(6, functionalCompare(std::greater<>(), 2, 3, 4, 1, 5, 6));
    EXPECT_EQ(6, functionalCompare(std::greater<>(), 2, 3, 4, 5, 6, 1));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
