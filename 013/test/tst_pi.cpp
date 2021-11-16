#include <gtest/gtest.h>
#include "../pi.h"

/* 乱数のテストケースはどう作る？ */
TEST(TestPI, genRandomPoint)
{
    auto point = PI::genRandomPoint();
    EXPECT_GE(1, point.first);
    EXPECT_GE(1, point.second);
}

TEST(TestPI, distance)
{
    auto point = std::make_pair(3.0f, 3.0f);

    EXPECT_EQ(std::sqrt(18.0f), PI::distance(point));
}

TEST(TestPI, pi)
{
    auto point = PI::genRandomPoint();
    auto pi = PI::calcPI(20000);
    EXPECT_LT(3.110f, pi);
    EXPECT_GE(3.160f, pi);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
