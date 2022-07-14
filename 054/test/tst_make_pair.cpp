#include <gtest/gtest.h>

#include <vector>

#include "../make_pair.h"

TEST(Pair, odd)
{
  std::vector<int> v1{1, 1, 3, 5, 8, 13, 21};
  std::vector<std::pair<int, int>> expected1({{1, 1}, {3, 5}, {8, 13}});

  auto result1 = pairwise(v1);

  EXPECT_EQ(result1, expected1);
}

TEST(Pair, odd_size1)
{
  std::vector<int> v1{1};
  std::vector<std::pair<int, int>> expected1;

  auto result1 = pairwise(v1);

  EXPECT_EQ(result1, expected1);
}

TEST(Pair, even)
{
  std::vector<int> v2{1, 1, 3, 5, 8, 13, 21, 34};
  std::vector<std::pair<int, int>> expected2(
      {{1, 1}, {3, 5}, {8, 13}, {21, 34}});

  auto result2 = pairwise(v2);

  EXPECT_EQ(result2, expected2);
}

TEST(Pair, even_size2)
{
  std::vector<int> v2{1, 1};
  std::vector<std::pair<int, int>> expected2({{1, 1}});

  auto result2 = pairwise(v2);

  EXPECT_EQ(result2, expected2);
}
