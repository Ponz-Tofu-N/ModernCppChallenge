/* 60. Conway's Game of Life */

/*
 * features
 * https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
 */

#include <vector>

#include "parallel.h"

int main(int argc, char const* argv[])
{
  std::vector<int> items = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  print(items);

  thread_transform(std::begin(items),
                   std::end(items),
                   [](auto& a)
                   {
                     using namespace std::chrono_literals;
                     std::this_thread::sleep_for(1000ms);
                     return a * 2;
                   });

  print(items);

  return 0;
}
