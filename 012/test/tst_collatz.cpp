#include <gtest/gtest.h>
#include "../collatz.h"

TEST(TestCollatz, collatz6)
{
    EXPECT_EQ(1, Collatz::collatzSeqSize(1));
}

TEST(TestCollatz, collatz837799)
{
    EXPECT_EQ(525, Collatz::collatzSeqSize(837799));
}

TEST(TestCollatz, collatz1000000)
{
    EXPECT_EQ(153, Collatz::collatzSeqSize(1000000));
}