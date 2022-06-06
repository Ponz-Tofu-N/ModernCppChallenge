/* 40. day distance */

/*
 * Features:
 * calculate day distance between first and second day.
 */

#include <iostream>
#include <thread>

#include "day.h"
int main(int argc, char const* argv[])
{
  auto distance = myday::day_distance(1998, 5, 28, 1998, 3, 24);

  std::cout << distance.count() << std::endl;

  return 0;
}