/* 45. Priority queue */

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
  alg::priority_queue<int> pq{1, 3, 4, 6, 2, 5};

  pq.push(10);
  pq.push(24);

  const auto size = pq.size();
  while (!pq.empty())
  {
    std::cout << "top: " << pq.top() << std::endl;
    pq.pop();
  }

  return 0;
}