#include <algorithm>
#include <map>
#include <vector>
#include <string>

template <typename T>
std::vector<std::pair<T, size_t>> find_most_frequent(const std::vector<T>& set)
{
  std::map<T, size_t /*, std::greater<T>*/> map;
  size_t max = 0;

  for (auto&& i : set)
  {
    // mapの要素をキーに登場した要素の回数をカウントしていく
    map[i] += 1;

    // if (max < map[i])
    //   max = map[i];
  }

  std::vector<std::pair<T, size_t>> result;
  // for (auto i = map.begin(); i != map.end(); i++)
  // {
  //   if (i->second == max)
  //     result.push_back(std::make_pair(i->first, i->second));
  // }

  // std::mapのAllocatorがstd::pairを標準にしているため、
  // 引数(i1,i2)はstd::pair<const Key, T>型になる。
  auto first_max = std::max_element(
      map.begin(), map.end(),
      [](const auto i1, const auto i2) { return i1.second < i2.second; });

  max = first_max->second;

  std::copy_if(map.begin(), map.end(), std::back_inserter(result),
               [&max](const auto i) { return max == i.second; });

  return result;
}


std::map<char, double> analyze_text(std::string const & input){
  std::map<char, double> counter;

  size_t max_count = 0;

  for (size_t i = 0; i < input.size(); i++)
  {
    const char target = input[i];
    if ( 'a' <=target && target <= 'z' )
    {
      counter[target] += 1e0;
      max_count++;
    } 
  }

  std::for_each(counter.begin(), counter. end(),[&max_count](auto & pair_count){
    pair_count.second *= (static_cast<double>(100) / max_count);
  });

  return counter;
}