#include <gtest/gtest.h>
#include "../array2d.h"

TEST(Tst2d, data)
{
    /* リスト初期化子は2重に{}が必要 */
    Array2d<int, 3, 2> arr1 = 
    {{
        {1,2},
        {3,4},
        {5,6}
    }};

    EXPECT_EQ(3, arr1.data(1, 0));
}

TEST(Tst2d, size)
{
    Array2d<int, 3, 2> arr1 
    {{
        {1,2},
        {3,4},
        {5,6}
    }};

    EXPECT_EQ(6, arr1.size());
}

TEST(Tst2d, begin)
{
    Array2d<int, 3, 2> arr1 = 
    {
        {
            {1,2},
            {3,4},
            {5,6}
        }
    };

    auto itr_begin = arr1.begin();
    EXPECT_EQ(1, *itr_begin);
}

TEST(Tst2d, end)
{
    Array2d<int, 3, 2> arr1 = 
    {
        {
            {1,2},
            {3,4},
            {5,6}
        }
    };

    auto itr_end = arr1.end();
    EXPECT_EQ(6, *itr_end);
}

TEST(Tst2d, swap){
    
    Array2d<int, 3, 2> arr1 = 
    {
        {
            {1,2},
            {3,4},
            {5,6}
        }
    };

    Array2d<int, 3, 2> arr1_copy = arr1;

    Array2d<int, 3, 2> arr2 = 
    {
        {
            {7,8},
            {9,10},
            {11,12}
        }
    };

    Array2d<int, 3, 2> arr2_copy = arr2;

    arr1.swap(arr2);

    EXPECT_TRUE(arr1 == arr2_copy);
    EXPECT_TRUE(arr2 == arr1_copy);
}

TEST(Tst2d, increment){
    
    Array2d<int,3,2> arr1 =    
    {
        {
            {1,2},
            {3,4},
            {5,6}
        }
    };
    
    auto itr1 = arr1.begin();

    EXPECT_EQ(2, *(itr1 + 1));
    EXPECT_EQ(3, *(++itr1));
}

TEST(Tst2d, decrement){
    
    Array2d<int,3,2> arr1 =    
    {
        {
            {1,2},
            {3,4},
            {5,6}
        }
    };
    
    auto itr1 = arr1.end();

    EXPECT_EQ(5, *(itr1 - 1));
    EXPECT_EQ(4, *(--itr1));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
