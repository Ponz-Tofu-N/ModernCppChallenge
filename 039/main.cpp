/* 39. Elapsed time */

/*
 * Features:
 * Count Elapsed time.
 */

#include <iostream>
#include <thread>

#include "time_count.h"
int main(int argc, char const* argv[])
{
  auto f = std::function([](int a, int b) {
    std::cout << "function called." << std::endl;
    std::cout << "processing..." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << "done." << std::endl;
  });

  time_count<std::chrono::milliseconds> tc;
  tc.count(f, 1, 2);

  return 0;
}