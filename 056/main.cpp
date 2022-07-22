/* 56.  */

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
#include "select_alg.h"

struct book {
  int id;
  std::string title;
  std::string auther;
};

int main()
{
  std::vector<book> books{

    {101, "The C++ Programming Language", "Bjarne Stroustrup"},
    {203, "Effective Modern C++", "Scott Meyers"},
    {404, "The Modern C++ Programming Cookbook", "Marius Bancila"} };

  auto titles = select(books, [](book const& b) {return b.title; });
  auto ids = select(books, [](book const& b) {return b.id; });

  for (auto const& title : titles)
  {
    std::cout << title << std::endl;
  }

  for (auto const& id : ids)
  {
    std::cout << id << std::endl;
  }
}
