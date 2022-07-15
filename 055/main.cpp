/* 55. Zip algorithm */

/*
 * features
 * Input
 * - {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 * - {1, 1, 3, 5, 8, 13, 21};
 *
 * Output
 * - {1,1},{2,1},{3,3},{4,5},{5,8},{6,13},{7,21}
 */

#include <iostream>

#include "zip.h"

int main()
{
  std::vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> v2{1, 1, 3, 5, 8, 13, 21};

  auto result = zip(v1, v2);

  for (auto const& p : result)
  {
    std::cout << '{' << p.first << ',' << p.second << '}' << std::endl;
  }
}
