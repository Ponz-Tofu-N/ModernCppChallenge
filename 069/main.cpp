/* 69. Social Security Number Generator*/

/*
 * Rule
 * - generator a SSN by appropriate rules
 * - for Northeria
 *   - S -> sex, female->9, male->7
 *   - YYYYMMDD -> Birthday
 *   - NNNNN -> ramdom and exclusive number in the day
 *   - C -> check sum that has to be multiple of 11
 *
 * - for Sourtheria
 *   - S -> sex, female->1, male->2
 *   - YYYYMMDD -> Birthday
 *   - NNNN -> ramdom and exclusive number in the day
 *   - C -> check sum that has to be multiple of 10
 */

#include <iostream>

#include "ssn_generator.h"

int main(int argc, char const* argv[])
{
  northeria_generator g_north;
  southeria_generator g_south;
  std::cout << g_north.generate(ssn_generator::sex_type::Female, 2017, 4, 5)
            << std::endl;
  std::cout << g_south.generate(ssn_generator::sex_type::Female, 2017, 4, 5)
            << std::endl;
}
