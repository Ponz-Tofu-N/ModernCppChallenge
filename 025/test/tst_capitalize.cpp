#include <gtest/gtest.h>

#include "../capitalize.h"

TEST(CapitalizeTest, capitalize)
{
    std::string text = "cpp is so difficult..";
    EXPECT_EQ("Cpp Is So Difficult..", capitalize(text));
}

TEST(CapitalizeTest, capitalize2)
{
    std::string text = "cPp is sO dIfFicuLt..";
    EXPECT_EQ("Cpp Is So Difficult..", capitalize(text));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
