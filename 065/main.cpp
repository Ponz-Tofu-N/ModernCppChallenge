/* 65. Thead-safe Logger*/

/*
 * features
 *  a class that can log thread-safe.
 */

#include <random>
#include <vector>

#include "logger.h"
int main(int argc, char const *argv[])
{
  // コピーコンストラクタとなるため変数に入れることはできない。
  // auto log = Logger::instance();

  std::vector<std::thread> threads;
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<> dist(0, 100);

  for (size_t i = 0; i < 5; i++)
  {
    auto number   = dist(mt);
    auto function = [&number, &i](auto first, auto second)
    { Logger::instance().log(first, second); };

    threads.emplace_back(function, number, i);
  }

  for (auto &&t : threads)
  {
    t.join();
  }

  return 0;
}
