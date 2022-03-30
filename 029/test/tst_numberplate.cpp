#include <gtest/gtest.h>

#include "../numberplate.h"

TEST(numberplate, validate)
{
    std::string re(R"([A-Z]{3}-[A-Z]{2} \d{3,4})");
    std::string input1("ABC-AB 1000");
    std::string input2("ABC-ABC 1000");
    std::string input3("ABC-AB 100");
    std::string input4("ABC-AB 10");

    EXPECT_TRUE(validate(input1, re));
    EXPECT_FALSE(validate(input2, re));
    EXPECT_TRUE(validate(input3, re));
    EXPECT_FALSE(validate(input4, re));
}

TEST(numberplate, find_numberplate)
{
    std::string re(R"([A-Z]{3}-[A-Z]{2} \d{3,4})");
    std::string input("ABC-AB 1000 QJ ABC-ABC 1000 QJDSKJFGABC-AB 100 abc-AB 100");
    std::vector<std::string> exp_str;

    exp_str.push_back("ABC-AB 1000");
    exp_str.push_back("ABC-AB 100");

    EXPECT_EQ(exp_str, find_numberplate(input, re));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
