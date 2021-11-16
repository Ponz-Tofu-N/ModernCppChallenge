#include <gtest/gtest.h>
#include "../collatz.h"

TEST(TestCollatz, collatz6)
{
    EXPECT_EQ(8, Collatz::collatzSeqSize(6));
}
TEST(TestCollatz, collatz837799)
{
    EXPECT_EQ(524, Collatz::collatzSeqSize(837799));
}
TEST(TestCollatz, collatz27)
{
    EXPECT_EQ(111, Collatz::collatzSeqSize(27));
}
TEST(TestCollatz, collatz1000000)
{
    EXPECT_EQ(152, Collatz::collatzSeqSize(1000000));
}