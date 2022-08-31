/* 64. Async quick sort*/

/*
 * features
 *  Sort the elements in a given range by async Quick-sort
 */

#include <cstdlib>
#include <random>
#include <vector>

#include "parallel.h"
#include "sort_alg.h"

int main(int argc, char const *argv[])
{
  constexpr size_t SIZE = 10000000;

  std::cout << "generating...." << std::endl;
  std::vector<int> items1(SIZE);

  std::random_device seed_gen;
  std::default_random_engine engine(seed_gen());
  std::uniform_int_distribution<> generator(1, SIZE);
  std::generate_n(items1.begin(), SIZE, [&]() { return generator(engine); });

  std::vector<int> items2(SIZE);
  std::copy(std::begin(items1), std::end(items1), std::begin(items2));
  std::cout << "done." << std::endl;

  const auto threaded1 = [&items1]()
  {
    // int (*f)(const void *, const void *) = [](const void *a, const void *b)
    // { return *(int *)a - *(int *)b; };
    // std::qsort(
    //     items1.data(), items1.size(), sizeof(std::vector<int>::value_type),
    //     f);

    quicksort(std::begin(items1), std::end(items1));

    std::cout << "is_sorted: " << std::boolalpha
              << std::is_sorted(std::begin(items1), std::end(items1))
              << std::endl;
  };
  print_erapsedtime(threaded1, "non_async_qsort");

  const auto threaded2 = [&items2]()
  {
    async_qsort(std::begin(items2), std::end(items2), std::greater<>());

    std::cout << "is_sorted: " << std::boolalpha
              << std::is_sorted(
                     std::begin(items2), std::end(items2), std::greater<>())
              << std::endl;
  };
  print_erapsedtime(threaded2, "async_qsort");

  return 0;
}
