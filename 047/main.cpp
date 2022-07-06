/* 47. Double Buffer */

/*
 * keywords:
 * Double Buffer.
 * - write()
 * - read()
 * - Mutual exclusion
 * - Multi Thread
 * - std::mutex
 * - std::thread
 */

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

      using namespace std::chrono_literals;
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