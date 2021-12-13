#include <gtest/gtest.h>

#include "../hexutils.h"

TEST(HexTst, toHex)
{
    EXPECT_EQ('0', hex::toHex(0));
    EXPECT_EQ('F', hex::toHex(15));
    EXPECT_EQ('9', hex::toHex(9));
    EXPECT_EQ('A', hex::toHex(10));
}

TEST(HexTst, hexToStr)
{
    std::array<uint8_t, 4> input = {0xBA, 0xAD, 0xF0, 0x0D};
    std::array<uint8_t, 6> input2 = {1, 2, 3, 4, 5, 6};

    EXPECT_EQ("BAADF00D", hex::hexToStr(input));
    EXPECT_EQ("baadf00d", hex::hexToStr(input, hex::CASE::Lower));

    EXPECT_EQ("010203040506", hex::hexToStr(input2));
    EXPECT_EQ("010203040506", hex::hexToStr(input2, hex::CASE::Lower));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
