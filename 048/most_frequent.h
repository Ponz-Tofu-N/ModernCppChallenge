#include <map>
#include <vector>

template <typename T>
std::vector<std::pair<T, size_t>> find_most_frequent(const std::vector<T>& set)
{
  std::map<T, size_t /*, std::greater<T>*/> map;
  size_t max = 0;

  for (auto&& i : set)
  {
    // mapの要素をキーに登場した要素の回数をカウントしていく
    map[i] += 1;

    if (max < map[i])
      max = map[i];
  }

  std::vector<std::pair<T, size_t>> result;
  for (auto i = map.begin(); i != map.end(); i++)
  {
    if (i->second == max)
      result.push_back(std::make_pair(i->first, i->second));
  }

  return result;
}