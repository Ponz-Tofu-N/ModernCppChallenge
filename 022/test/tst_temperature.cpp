#include <gtest/gtest.h>

#include "../temperature.h"

// class TempTst : public ::testing::Test
// {
// protected:
//     virtual void SetUp()
//     {
//         tempc(Temperature<UNIT::Celsius>(0.0000));
//     }

//     Temperature<UNIT::Celsius> tempc;
//     Temperature<UNIT::Fahrenheit> tempf;
//     Temperature<UNIT::Kelvin> tempk;
// };

using namespace Temperature;
using namespace Temperature::literals;

TEST(TempTst, plus)
{
    Quantity<UNIT::Celsius> tempc1(12.345);
    Quantity<UNIT::Celsius> tempc2(12.345);

    EXPECT_EQ(24.69e0, (double)(tempc2 + tempc1));
}

TEST(TempTst, literalc)
{
    Quantity<UNIT::Celsius> tempc(12.345_deg);
    EXPECT_EQ(12.345e0, (double)tempc);

    Quantity<UNIT::Fahrenheit> tempf(12.345_f);
    EXPECT_EQ(12.345e0, (double)tempf);

    Quantity<UNIT::Kelvin> tempk(12.345_k);
    EXPECT_EQ(12.345e0, (double)tempk);
}

TEST(TempTst, equal)
{
    Quantity<UNIT::Celsius> tempc1(12.345_deg);
    Quantity<UNIT::Celsius> tempc2(12.345_deg);
    EXPECT_TRUE(tempc1 == tempc2);
}

TEST(TempTst, greater)
{
    Quantity<UNIT::Celsius> tempc1(1.345_deg);
    Quantity<UNIT::Celsius> tempc2(12.345_deg);
    EXPECT_TRUE(tempc1 <= tempc2);
}

TEST(TempTst, less)
{
    Quantity<UNIT::Celsius> tempc1(1.345_deg);
    Quantity<UNIT::Celsius> tempc2(12.345_deg);
    EXPECT_FALSE(tempc1 >= tempc2);
}

TEST(TempTst, convCtoF)
{
    Quantity<UNIT::Celsius> tempc(1.345_deg);
    auto f = ctof(tempc);
    
    EXPECT_EQ(34.421e0, (double)f);
}

TEST(TempTst, convCtoK)
{
    Quantity<UNIT::Celsius> tempc(1.345_deg);
    auto k = ctok(tempc);
    
    EXPECT_EQ(274.495e0, (double)k);
}

// 浮動小数点で表現出来ない部分で誤差が発生
// [  FAILED  ] TempTst.convFtoC
// [  FAILED  ] TempTst.convFtoK
// [  FAILED  ] TempTst.convKtoC
// [  FAILED  ] TempTst.convKtoF

TEST(TempTst, convFtoC) 
{
    Quantity<UNIT::Fahrenheit> tempf(12.345_f);
    auto c = ftoc(tempf);
    
    EXPECT_EQ(-10.91944e0, (double)c);
    // EXPECT_TRUE(c == -10.91944e0);
}
TEST(TempTst, convFtoK) 
{
    Quantity<UNIT::Fahrenheit> tempf(12.345_f);
    auto k = ftok(tempf);
    
    EXPECT_EQ(262.2306e0, (double)k);
}

TEST(TempTst, convKtoC) 
{
    Quantity<UNIT::Kelvin> tempf(12.345_k);
    auto c = ktoc(tempf);
    
    EXPECT_EQ(-260.805e0, (double)c);
}
TEST(TempTst, convKtoF)
{
    Quantity<UNIT::Kelvin> tempf(12.345_k);
    auto f = ktof(tempf);
    
    EXPECT_EQ(-437.449e0, (double)f);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
