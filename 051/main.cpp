/* 51. Normalization of International phone number*/

/*
 * {
    "07555 123456",
 *  "07555123456",
 *  "+44 7555 123456",
 *  "44 7555 123456",
 *  "7555 123456"
 * }
 *  ↓
 * {
 *   +447555123456,
 *   +447555123456
 *   +447555123456
 *   +447555123456
 *   +447555123456
 * }
 */

#include <iomanip>
#include <iostream>
#include <numeric>

#include "phone_number.h"

int main()
{
  std::vector<std::string> numbers{"07555 123456", "07555123456",
                                   "+44 7555 123456", "44 7555 123456",
                                   "7555 123456"};

  auto result = normalize_phone_numbers(numbers, "44");

  for (auto const& number : result)
  {
    std::cout << number << std::endl;
  }
}
