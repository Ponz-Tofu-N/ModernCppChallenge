#include <vector>

template <typename T>
std::vector<std::pair<T, T>> pairwise(std::vector<T> const& v)
{
  std::vector<std::pair<T, T>> pairs;
  auto v_itr = v.begin() + 1;

  while (std::distance(v_itr, v.cend()) > 0)
  {
    pairs.push_back(std::make_pair(*(v_itr - 1), *v_itr));
    v_itr += 2;
  }

  return pairs;
}