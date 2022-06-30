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

#include <iostream>

#include "alg.h"
int main(int argc, char const* argv[])
{
  alg::ring_buffer<int> ring(5);

  for (size_t i = 0; i < 5; i++)
  {
    ring.push(i);
  }
  std::cout << "first: ";
  for (size_t i = 0; i < 5; i++)
  {
    std::cout << ring[i];
  }
  std::cout << std::endl;

  for (size_t i = 5; i < 10; i++)
  {
    ring.push(i);
  }
  std::cout << "second: ";
  for (size_t i = 0; i < 5; i++)
  {
    std::cout << ring[i];
  }
  std::cout << std::endl;

  auto itr_b = ring.begin();
  std::cout << "itr(begin): " << *itr_b << std::endl;

  auto itr_e = ring.end();
  std::cout << "it(end-2): " << *(itr_e + 2) << std::endl;

  for (size_t i = 1; i < 30; i++)
  {
    std::cout << *(itr_b - i);
  }
  std::cout << std::endl;

  return 0;
}