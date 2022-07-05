/* 46. Ring Buffer */

/*
 * Features:
 * priority queue.
 * - push()
 * - pop()
 * - top()
 * - size()
 * - empty()
 */

#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <mutex>
#include <thread>
#include <vector>

#include "double_buffer.h"
int main()
{
  alg::double_buffer<int> buf(10);

  std::thread t([&buf]() {
    for (int i = 1; i < 1000; i += 10)
    {
      int* data = new int[10];
      for (size_t j = 0; j < 10; j++)
      {
        data[j] = i + j;
      }

      buf.write(data, 10);

      using namespace std::chrono_literals;
      std::this_thread::sleep_for(100ms);

      delete[] data;
    }
  });

  auto start = std::chrono::system_clock::now();
  do
  {
    alg::print_buffer(buf);

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(150ms);
  } while (std::chrono::duration_cast<std::chrono::seconds>(
               std::chrono::system_clock::now() - start)
               .count() < 10);

  t.join();
}