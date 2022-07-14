/* 54. Creating pairs algorithm */

/*
 * features
 * - {1, 1, 3, 5, 8, 13, 21} -> {1, 1},{3, 5},{8, 13}.
 * - ignore last number if list size is odd.
 */

#include <iostream>

#include "make_pair.h"

int main()
{
  std::vector<int> v{1, 1, 3, 5, 8, 13};  //, 21

  auto result = pairwise(v);

  for (auto const& p : result)
  {
    std::cout << '{' << p.first << ',' << p.second << '}' << std::endl;
  }
}
