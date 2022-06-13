/* 42. Time zone */

/*
 * Features:
 * output local time per user.
 */

#include <iostream>
#include <thread>

#include "cctz/time_zone.h"
#include "day.h"

int main(int argc, char const* argv[])
{
  std::vector<myday::user> tz_list{{"kazu", "Asia/Tokyo"},
                                   {"kevin", "America/Los_Angeles"}};

  auto list = myday::timezone_list(tz_list);

  for (auto&& u : list)
  {
    std::cout << u << std::endl;
  }

  // std::cout << tz_us.name() << std::endl;
  // std::cout << tz_jp.name() << std::endl;

  // auto lookup_us = tz_us.lookup(now);
  // auto lookup_jp = tz_jp.lookup(now);

  // std::cout << lookup_us.cs << std::endl;
  // std::cout << lookup_jp.cs << std::endl;

  // // 日本のタイムゾーン
  // タイムゾーンクラスはサポートしているコンパイラがまだないらしい。
  // const std::chrono::time_zone* tz = chrono::locate_zone("Asia/Tokyo");

  return 0;
}