/* 60. Conway's Game of Life */

/*
 * features
 * https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
 */

#include <chrono>
#include <iostream>
#include <thread>

#include "life.h"

int main(int argc, char const* argv[])
{
  auto life = Life(50, 20);

  life.explorer();

  for (size_t i = 0; i < 100; i++)
  {
    life.display();
    life.iterate();

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(100ms);
  }

  return 0;
}
