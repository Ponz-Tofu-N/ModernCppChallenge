/* 46. Ring Buffer */

/*
 * Features:
 * ring buffer.
 * - push()
 * - pop()
 * - top()
 * - size()
 * - empty()
 * - support Ramdom Access Iterator
 */

#include <iostream>

#include "alg.h"
int main(int argc, char const* argv[])
{
  alg::ring_buffer<int> rb(5);

  auto itr_b = rb.begin();
  std::cout << *itr_b << " " << 1 << std::endl;

  rb.push(1);
  rb.push(2);
  rb.push(3);

  itr_b = rb.begin();
  auto itr_e = rb.end();

  std::cout << *itr_b << " " << 1 << std::endl;
  std::cout << *(itr_e - 1) << " " << 3 << std::endl;

  std::cout << *(itr_b + 2) << " " << 3 << std::endl;

  rb.push(4);
  rb.push(5);
  rb.push(6);
  rb.push(7);
  rb.push(8);

  rb.pop();
  rb.pop();
  rb.pop();

  itr_b = rb.begin();
  itr_e = rb.end();

  std::cout << *itr_b << " " << 4 << std::endl;
  std::cout << *(itr_e - 1) << " " << 5 << std::endl;
}