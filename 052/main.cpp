/* 52. permutation of string*/

/*
 * main
 *  ↓
 * aimn
 * ainm
 * amin
 * amni
 * anim
 * anmi
 * iamn
 * ianm
 * iman
 * imna
 * inam
 * inma
 * main
 * mani
 * mian
 * mina
 * mnai
 * mnia
 * naim
 * nami
 * niam
 * nima
 * nmai
 * nmia
 *
 * 4! = 24 patterns
 */

#include <iomanip>
#include <iostream>
#include <numeric>

#include "permutation.h"

int main()
{
  std::cout << "recursive version" << std::endl;
  print_permutations_recursive("main");

  std::cout << "non-recursive version" << std::endl;
  print_permutations("main");
}
