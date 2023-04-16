/* 71. Observable Vector*/

/*
 * Rule
 * - Observable vector that sends notification about its element being added,
 * deleted and cleared
 */

#include <iostream>

#include "observable_vector.h"

int main()
{
  observable_vector<int> v;
  observer o;

  v.add_observer(&o);

  v.push_back(1);
  v.push_back(2);

  v.pop_back();

  v.clear();

  v.remove_observer(&o);

  v.push_back(3);
  v.push_back(4);

  v.add_observer(&o);

  observable_vector<int> v2{1, 2, 3};
  v = v2;

  v = observable_vector<int>{7, 8, 9};
}
