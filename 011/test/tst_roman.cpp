#include <gtest/gtest.h>
#include "../roman.h"

TEST(TestMakeRoman, convert1)
{
    EXPECT_EQ(makeRoman(1), "I");
}
TEST(TestMakeRoman, convert50)
{
    EXPECT_EQ(makeRoman(50), "L");
}
TEST(TestMakeRoman, convert538)
{
    EXPECT_EQ(makeRoman(538), "DXXXVIII");
}

TEST(TestMakeRoman, convert913)
{
    EXPECT_EQ(makeRoman(913), "CMXIII");
}