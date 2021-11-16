#include <gtest/gtest.h>
#include "../collatz.h"

TEST(TestCollatz, collatz1)
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

TEST(TestCollatz, makePair1)
{
    std::pair<unsigned int, unsigned int> pair(1, 1);
    EXPECT_EQ(pair, Collatz::largestPair(1));
}

TEST(TestCollatz, makePair837799)
{
    std::pair<unsigned int, unsigned int> pair(525, 837799);
    EXPECT_EQ(pair, Collatz::largestPair(837799));
}

TEST(TestCollatz, makePair1000000)
{
    std::pair<unsigned int, unsigned int> pair(525, 837799);
    EXPECT_EQ(pair, Collatz::largestPair(1000000));
}