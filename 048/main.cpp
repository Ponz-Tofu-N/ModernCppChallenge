/* 47. Most Frequent */

/*
 * keywords:
 * {Number, Times}.
 * - {1, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5} -> {5,3}, {8,3}
 */
#include <iostream>

#include "most_frequent.h"

int main()
{
  auto range = std::vector<int>{1, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5};
  auto result = find_most_frequent(range);

  for (auto const& e : result)
  {
    std::cout << e.first << " : " << e.second << std::endl;
  }
}