#include <gtest/gtest.h>

#include "../palindrome.h"

TEST(palindrome, palindrome)
{
    std::string input("optharararahingararararararararara");
    std::string expected("ararararararararara");
    EXPECT_EQ(expected, find_palindrome(input));
}

TEST(palindrome, palindrome2)
{
    std::string input("optharararahing");
    std::string expected("harararah");
    EXPECT_EQ(expected, find_palindrome(input));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
