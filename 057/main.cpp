/* 57. Sort Algorithm */

/*
 * features
 * quick sort
 * Input
 * - {1, 8, 4, 5, 6, 2, 3, 7, 9, 10};
 *
 * Output
 * - {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
 */

#include <iomanip>
#include <iostream>
#include <vector>

#include "sort_alg.h"

template <typename RamdomAI>
void print(RamdomAI begin, RamdomAI end)
{
  for (auto i = begin; i != end; i++)
  {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
}

int main()
{
  {
    std::vector<int> v{5, 3, 8, 6, 2, 9, 7, 4, 1};

    std::cout << std::left << std::setw(12) << "std-vector:";
    print(std::begin(v), std::end(v));

    quicksort(std::begin(v), std::end(v));

    std::cout << std::left << std::setw(12) << "sorted:";
    print(std::begin(v), std::end(v));

    std::cout << std::endl;
  }

  {
    std::array<int, 9> a{1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << std::left << std::setw(12) << "std-array:";
    print(std::begin(a), std::end(a));

    quicksort(std::begin(a), std::end(a));

    std::cout << std::left << std::setw(12) << "sorted:";
    print(std::begin(a), std::end(a));

    std::cout << std::endl;
  }

  {
    int a[]{9, 8, 7, 6, 5, 4, 3, 2, 1};

    std::cout << std::left << std::setw(12) << "c-array:";
    print(std::begin(a), std::end(a));

    quicksort(std::begin(a), std::end(a));

    std::cout << std::left << std::setw(12) << "sorted:";
    print(std::begin(a), std::end(a));

    std::cout << std::endl;
  }

  // {
  //   std::vector<int> v{1, 5, 3, 8, 6, 2, 9, 7, 4};

  //   quicksort(std::begin(v), std::end(v), std::greater_equal<>());

  //   print(std::begin(v), std::end(v));
  // }

  // {
  //   std::array<int, 9> a{1, 2, 3, 4, 5, 6, 7, 8, 9};

  //   quicksort(std::begin(a), std::end(a), std::greater_equal<>());

  //   print(std::begin(a), std::end(a));
  // }

  // {
  //   int a[]{9, 8, 7, 6, 5, 4, 3, 2, 1};

  //   quicksort(std::begin(a), std::end(a), std::greater_equal<>());

  //   print(std::begin(a), std::end(a));
  // }

  // {
  //   std::vector<int> v{1, 5, 3, 8, 6, 2, 9, 7, 4};

  //   quicksorti(std::begin(v), std::end(v));

  //   print(std::begin(v), std::end(v));
  // }

  // {
  //   const size_t count = 1000000;
  //   std::vector<int> data(count);

  //   std::random_device rd;
  //   std::mt19937 mt;
  //   auto seed_data = std::array<int, std::mt19937::state_size>{};
  //   std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
  //   std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
  //   mt.seed(seq);
  //   std::uniform_int_distribution<> ud(1, 1000);

  //   std::cout << "generating..." << std::endl;
  //   std::generate_n(std::begin(data), count, [&mt, &ud]() { return ud(mt);
  //   });

  //   auto d1 = data;
  //   auto d2 = data;

  //   std::cout << "sorting..." << std::endl;
  //   auto start1 = std::chrono::system_clock::now();
  //   quicksort(std::begin(d1), std::end(d1));
  //   auto end1 = std::chrono::system_clock::now();
  //   auto t1 =
  //       std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
  //   std::cout << "time: " << t1.count() << "ms" << std::endl;

  //   std::cout << "sorting..." << std::endl;
  //   auto start2 = std::chrono::system_clock::now();
  //   quicksorti(std::begin(d2), std::end(d2));
  //   auto end2 = std::chrono::system_clock::now();
  //   auto t2 =
  //       std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
  //   std::cout << "time: " << t2.count() << "ms" << std::endl;

  //   assert(d1 == d2);
  // }
}