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
  int y, m, d;

  myday::today(y, m, d);

  auto wd = myday::what_weekday(y, m, d);

  std::cout << "today: " << wd.iso_encoding() << std::endl;

  return 0;
}