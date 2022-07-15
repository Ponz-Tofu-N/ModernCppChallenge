#include <vector>

template <typename T>
std::vector<std::pair<T, T>> zip(std::vector<T> const& fst,
                                 std::vector<T> const& scd)
{
  std::vector<std::pair<T, T>> pairs;
  auto itr_f = fst.begin();
  auto itr_s = scd.begin();
  // サイズが大きい方を判別する

  while (itr_f != fst.cend() && itr_s != scd.cend())
  {
    // 両方から一つずつ要素を抜く
    auto pair = std::make_pair(*itr_f, *itr_s);

    // 抜いた要素を組み合わせ、結果用のバッファに入れる
    pairs.push_back(pair);

    itr_f++;
    itr_s++;
  }

  return pairs;
}