#include <gtest/gtest.h>

#include "../concatenate.h"

TEST(ConcatenateTest, concatenate)
{
    std::vector<std::string> input{"Cpp", "Is", "So", "Difficult.."};
    EXPECT_EQ("Cpp Is So Difficult..", concatenate(input, " "));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
