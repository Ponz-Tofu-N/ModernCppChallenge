#include <gtest/gtest.h>

#include "../split.h"

TEST(SplitTest, split)
{
    std::string input("Cpp Is So Difficult..");
    std::vector<std::string> expected{"Cpp", "Is", "So", "Difficult.."};
    EXPECT_EQ(expected, split<std::vector<std::string>>(input, ' '));
}

TEST(SplitTest, split2)
{
    std::string input("Cpp,Is So!Difficult..");
    std::vector<std::string> expected{"Cpp", "Is", "So", "Difficult.."};
    EXPECT_EQ(expected, split<std::vector<std::string>>(input, " !,"));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
