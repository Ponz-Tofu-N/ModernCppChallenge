#include <gtest/gtest.h>

#include "../remove_blank_line.h"
#include <fstream>

TEST(removeBlankLine, removeBlankLine)
{
    std::string input("test.txt");
    std::string output("test_out.txt");

    removeBlankLines(input, output);

    std::ifstream ifs_expected("test_expected.txt");
    std::ifstream ifs_out(output);

    EXPECT_TRUE(ifs_out.is_open());
    
    for(std::string line, line_exp; std::getline(ifs_out, line); )
    {
        std::getline(ifs_expected, line_exp);
        EXPECT_EQ(line, line_exp);
    }
}