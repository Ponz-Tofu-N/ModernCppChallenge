#include <gtest/gtest.h>
#include <list>
#include <array>

#include "../contrainerutil.h"

class MyLibraryTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        vec = {1, 2, 3, 3};
        str = {"aho", "hoge", "foo", "bar"};
        for (auto &&c : "string")
        {
            str_list.push_back(c);
        }
    }

    std::vector<int> vec;
    std::array<std::string, 4> str;
    std::list<char> str_list;
};

TEST_F(MyLibraryTest, allTrue)
{
    EXPECT_TRUE(all(vec, 1, 2, 3, 3));
    EXPECT_TRUE(all(str, "aho", "hoge", "foo", "bar"));
    EXPECT_TRUE(all(str_list, 's', 't', 'r', 'i', 'n', 'g', '\0'));
}

TEST_F(MyLibraryTest, allFalse)
{
    EXPECT_FALSE(all(vec, 1, 2, 3, 4));
    EXPECT_FALSE(all(str, "aho", "hogi", "foo", "bar"));
    EXPECT_FALSE(all(str_list, 's', 't', 'r', 'a', 'n', 'g'));
}

TEST_F(MyLibraryTest, anyTrue)
{
    EXPECT_TRUE(any(vec, 1, 2));
    EXPECT_TRUE(any(str, "foo", "bar"));
    EXPECT_TRUE(any(str_list, 's', 't'));
}

TEST_F(MyLibraryTest, anyFalse)
{
    EXPECT_FALSE(any(vec, 0, 10));
    EXPECT_FALSE(any(str, "for", "ber"));
    EXPECT_FALSE(any(str_list, 'b', 'a'));
}

TEST_F(MyLibraryTest, noneTrue)
{
    EXPECT_TRUE(none(vec, 0, 10));
    EXPECT_TRUE(none(str, "for", "ber"));
    EXPECT_TRUE(none(str_list, 'b', 'a'));
}

TEST_F(MyLibraryTest, noneFalse)
{
    EXPECT_FALSE(none(vec, 1, 2));
    EXPECT_FALSE(none(str, "foo", "bar"));
    EXPECT_FALSE(none(str_list, 's', 't'));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
