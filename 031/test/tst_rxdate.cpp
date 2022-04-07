#include <gtest/gtest.h>

#include "../rxdate.h"

TEST(extraction, parseDate)
{
    std::string input1("21-03-1289");
    std::string input2("21.03.1289");

    std::string re(R"(^(\w{2})(-|.)(\w{2})(-|.)(\w{4})$)");

    auto parsed1 = rx::parseDate(input1, re);
    auto parsed2 = rx::parseDate(input2, re);

    EXPECT_EQ(parsed1, "1289-03-21");
    EXPECT_EQ(parsed2, "1289-03-21");
}