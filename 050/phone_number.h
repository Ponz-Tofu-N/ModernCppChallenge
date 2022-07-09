#include <algorithm>
#include <string>
#include <vector>

std::vector<std::string> filter_numbers(std::vector<std::string> const& numbers,
                                        std::string const& key)
{
  std::vector<std::string> result;

  std::copy_if(numbers.begin(), numbers.end(),
               std::back_insert_iterator<std::vector<std::string>>(result),
               [&key](auto const n) {
                 int range = std::isdigit(n[0]) ? 2 : 3;
                 return std::includes(n.begin(), n.begin() + range, key.begin(),
                                      key.end());
               });

  return result;
}