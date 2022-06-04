/* 38. Temp log file */

/*
 * Features:
 * Output temp text log file.
 */

#include <iostream>
#include <thread>

#include "day_distance.h"
int main(int argc, char const* argv[])
{
  auto distance = day_distance(1998, 5, 28, 1998, 3, 24);

  std::cout << distance.count() << std::endl;

  return 0;
}