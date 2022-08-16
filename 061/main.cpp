/* 61. Threaded transform algorithm */

/*
 * features
 *  transform the elements of a range in paralell by a given function.
 */

#include <vector>

#include "parallel.h"

int main(int argc, char const* argv[])
{
  std::vector<int> items(100000000, 2);

  auto start1 = std::chrono::system_clock::now();
  std::transform(std::begin(items),
                 std::end(items),
                 items.begin(),
                 [](auto& a) { return a * 2; });

  auto end1 = std::chrono::system_clock::now();
  auto erapsed_time1 =
      std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
  std::cout << "std::transform: " << erapsed_time1.count() << " ms"
            << std::endl;

  auto start = std::chrono::system_clock::now();
  thread_transform_ver2(std::begin(items),
                        std::end(items),
                        [](auto& a)
                        {
                          //  using namespace std::chrono_literals;
                          //  std::this_thread::sleep_for(1000ms);
                          return a * 2;
                        });
  auto end = std::chrono::system_clock::now();

  auto erapsed_time =
      std::chrono::duration_cast<std::chrono::seconds>(end - start);
  std::cout << "threaded transform: " << erapsed_time.count() << " ms"
            << std::endl;

  return 0;
}
