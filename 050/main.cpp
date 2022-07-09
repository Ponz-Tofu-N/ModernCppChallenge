#include <iomanip>
#include <iostream>
#include <numeric>

#include "phone_number.h"

int main()
{
  std::vector<std::string> numbers{"+40744909080",    "44 7520 112233",
                                   "+44 7555 123456", "40 7200 123456",
                                   "7555 123456",     "+04 4555 123456"};

  // コンテナ形式で返す
  auto result = filter_numbers(numbers, "44");

  for (auto const& number : result)
  {
    std::cout << number << std::endl;
  }
}
