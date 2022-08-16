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

  const auto threaded1 = [&items]()
  {
    std::transform(std::begin(items),
                   std::end(items),
                   items.begin(),
                   [](auto& a) { return a * 2; });
  };

  print_erapsedtime(threaded1, "std::transform");

  const auto threaded2 = [&items]()
  {
    thread_transform_ver2(std::begin(items),
                          std::end(items),
                          [](auto& a)
                          {
                            //  using namespace std::chrono_literals;
                            //  std::this_thread::sleep_for(1000ms);
                            return a * 2;
                          });
  };

  print_erapsedtime(threaded2, "threaded transform");

  const auto threaded3 = [&items]()
  {
    ptransform(std::begin(items),
               std::end(items),
               [](auto& a)
               {
                 //  using namespace std::chrono_literals;
                 //  std::this_thread::sleep_for(1000ms);
                 return a * 2;
               });
  };

  print_erapsedtime(threaded3, "threaded transform");
}
