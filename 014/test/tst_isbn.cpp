#include <gtest/gtest.h>
#include "../isbn.h"

TEST(TestISBN, ctoi)
{
    EXPECT_EQ(9, ISBN::ctoi('9'));
    EXPECT_EQ(0, ISBN::ctoi('0'));
}

TEST(TestISBN, validateIsbn)
{
    EXPECT_TRUE(ISBN::validateIsbn("4063339661"));
    EXPECT_FALSE(ISBN::validateIsbn("1324654785"));
    EXPECT_FALSE(ISBN::validateIsbn("132465478X"));
    EXPECT_TRUE(ISBN::validateIsbn("409126168X"));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
