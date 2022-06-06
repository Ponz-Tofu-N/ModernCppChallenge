/* 42. Day of year */

/*
 * Features:
 * calculate day distance between first and second day.
 */

#include <iostream>
#include <thread>

#include "day.h"

int main(int argc, char const* argv[])
{
  int y, m, d;

  myday::today(y, m, d);

  auto date = myday::day_of_year(y, m, d);
  auto date220130 = myday::day_of_year(2022, 1, 30);

  std::cout << "today(" << y << "/" << m << "/" << d << "): " << date
            << std::endl;
  std::cout << "2022/1/30: " << date220130 << std::endl;

  return 0;
}