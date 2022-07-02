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
  alg::ring_buffer<int> rb(5);

  rb.push(1);
  rb.push(2);
  rb.push(3);

  auto itr_b = rb.begin();
  auto itr_e = rb.end();

  std::cout << *itr_b << " " << 1 << std::endl;
  std::cout << *(itr_e - 1) << " " << 3 << std::endl;

  std::cout << *(itr_b + 7) << " " << 2 << std::endl;

  rb.push(4);
  rb.push(5);
  rb.push(6);

  itr_b = rb.begin();
  itr_e = rb.end();

  std::cout << *itr_b << " " << 2 << std::endl;
  std::cout << *(itr_e - 1) << " " << 6 << std::endl;
}