#include <gtest/gtest.h>

#include "../extraction.h"

TEST(extraction, parse_url)
{
    std::string re(R"(^(\w+):\/\/([\w.-]+)\:?(\d+)?([\w\/\.]+)?\?([\w=&]*)?#?(/w+)?$)");
    std::string input1("https://www.touyube.com:80/watch?v=sJjZ4A_AAAA&ab_channel=AAA");

    rx::urlparts expected{"https", "www.touyube.com", 80, "/watch", "v=sJjZ4A_AAAA&ab_channel=AAA", "BBB"};
    
    auto actual = rx::parse_url(input1, re);

    EXPECT_EQ(actual->protcol, expected.protcol);
    EXPECT_EQ(actual->domain, expected.domain);
    if(actual->port.has_value())
        EXPECT_EQ(actual->port.value(), expected.port);
    
    if (actual->path.has_value())
        EXPECT_EQ(actual->path.value(), expected.path);
    
    if(actual->query.has_value())
        EXPECT_EQ(actual->query.value(), expected.query);

    if(actual->fragment.has_value())
        EXPECT_EQ(actual->fragment.value(), expected.fragment);
}