#include <gtest/gtest.h>

#include "../hexutils.h"

TEST(HexTst, strToHex)
{
    std::string str1 = "BAADF00D";
    std::string str2 = "010203040506";
    std::vector<uint8_t> arr1 = {0xBA, 0xAD, 0xF0, 0x0D};
    std::vector<uint8_t> arr2 = {1, 2, 3, 4, 5, 6};

    EXPECT_EQ(arr1, hex::strToHex(str1));
    EXPECT_EQ(arr2, hex::strToHex(str2));

}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
