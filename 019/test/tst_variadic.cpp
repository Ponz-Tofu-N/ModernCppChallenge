#include <gtest/gtest.h>
#include "../variadic.h"

TEST(TstVariadic, minimum)
{
    std::vector<int> vec;
    push_back_variadic(vec, 1, 2, 3, 4, 5, 6, 7);

    auto count = 1;
    for (auto && element : vec)
    {
        EXPECT_EQ(count, element);
        count++;
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
