/* 62. Threaded transform algorithm 2*/

/*
 * features
 *  find the max/min element from a range in paralell by a given function.
 */

#include <random>
#include <vector>

#include "parallel.h"

int main(int argc, char const* argv[])
{
  std::cout << "generating...." << std::endl;
  std::vector<int> items(100000000);

  std::random_device seed_gen;
  std::default_random_engine engine(seed_gen());
  std::uniform_int_distribution<> generator(1, items.capacity());
  std::generate_n(
      items.begin(), items.capacity(), [&]() { return generator(engine); });

  std::cout << "done." << std::endl;

  const auto threaded1 = [&items]()
  {
    auto max_i = std::max_element(std::begin(items), std::end(items));
    std::cout << "max: " << *max_i << std::endl;
  };
  print_erapsedtime(threaded1, "std::max_element");

  const auto threaded2 = [&items]()
  {
    auto max = async_max(std::begin(items), std::end(items));
    std::cout << "max: " << max << std::endl;
  };
  print_erapsedtime(threaded2, "async max_element");

  const auto threaded3 = [&items]()
  {
    auto max_i = std::min_element(std::begin(items), std::end(items));
    std::cout << "max: " << *max_i << std::endl;
  };
  print_erapsedtime(threaded3, "std::min_element");

  const auto threaded4 = [&items]()
  {
    auto max = async_min(std::begin(items), std::end(items));
    std::cout << "max: " << max << std::endl;
  };
  print_erapsedtime(threaded4, "async min_element");

  return 0;
}
