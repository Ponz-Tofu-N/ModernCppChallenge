/* 57. Sort Algorithm */

/*
 * features
 * quick sort
 * Input
 * - {1, 8, 4, 5, 6, 2, 3, 7, 9, 10};
 *
 * Output
 * - {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
 */

#include <iomanip>
#include <iostream>
#include <vector>
#include <array>

#include "weasel.h"

int main(int argc, char const* argv[])
{
  auto str = make_random_string();
  auto s = score(str);

  std::vector<std::pair<std::string, size_t>> childs(30, std::make_pair(str, s));

  int count = 0;
  while (1)
  {
    for (auto child = std::begin(childs); child != std::end(childs); child++)
    {
      make_mutatable_string((*child).first);
      (*child).second = score((*child).first);

    }
    auto highest_score = std::max_element(childs.begin(), childs.end(), [](auto a, auto b) {
      std::cout << (a).first << ": " << (b).second << std::endl;
      return a.second < b.second;
      });
    std::cout << count << "highest: " << (*highest_score).first << ": " << (*highest_score).second << std::endl;

    std::vector<std::pair<std::string, size_t>> new_childs(30, *highest_score);
    childs.swap(new_childs);

    if (is_match((*highest_score).first))
      break;

    count++;

  }

  return 0;
}
