#include <gtest/gtest.h>

#include "../directory.h"

TEST(dirsize, directory_size)
{
    std::string input("/home/haraponz/dev/ModernCppChallenge/035/test/test");

    EXPECT_EQ(74, directory_size(input));
}