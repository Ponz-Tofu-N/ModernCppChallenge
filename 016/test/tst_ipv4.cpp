#include <gtest/gtest.h>
#include "../ipv4.h"

TEST(TestIPV4, operatorEQ)
{
    Ipv4 a, b, c;
    a = Ipv4("0.0.0.1");
    b = Ipv4("0.0.0.2");
    c = Ipv4("1.0.0.2");

    EXPECT_TRUE( a < b);
    EXPECT_TRUE( b < c);
    EXPECT_FALSE( c < a);
}

TEST(TestIPV4, operatorINCR)
{
    Ipv4 a, b, c, d;

    a = Ipv4(0,0,0,0);
    b = Ipv4(0,0,0,255);
    c = Ipv4(0,0,0,1);
    d = Ipv4(0,0,1,0);

    EXPECT_EQ(c, ++a);
    EXPECT_EQ(d, ++b);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
