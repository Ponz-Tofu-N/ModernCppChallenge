#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

namespace movie
{
class movie
{
  int id;
  std::string title;
  std::vector<int> ratings;

public:
  movie(int const _id, std::string const& _title,
        std::vector<int> const& _ratings)
      : id(_id), title(_title), ratings(_ratings)
  {
    std::sort(ratings.begin(), ratings.end());
  }

  int getId() const { return id; }
  std::string getTitled() const { return title; }
  std::vector<int> getRatings() const { return ratings; }

  size_t trimmed_sum(size_t const trim) const
  {
    return std::accumulate(ratings.begin() + trim, ratings.end() - trim, 0);
  }
};

float round_n(float number, double n)
{
  //四捨五入したい値を10の(n-1)乗倍して、小数点以下を四捨五入する。
  number = round(number * pow(10, n - 1));

  // 10の(n-1)乗で割る。
  return number / pow(10, n - 1);
}

double ratings(movie const& m)
{
  // 両端から5%に当たるデータの個数を求める
  const size_t trim = std::ceil(m.getRatings().size() * 0.05);

  // 両端から5%に当たるデータの個数をレーティングリストから削ったサイズを求める
  const size_t trimed_size = m.getRatings().size() - 2 * trim;

  // トリム済みレーティングリストの平均を求める。
  return (double)m.trimmed_sum(trim) / trimed_size;
}

void print_ratings(std::vector<movie> const& movies)
{
  for (auto&& m : movies)
  {
    std::cout << m.getTitled() << ": " << round_n(ratings(m), 2) << std::endl;
  }
}

}  // namespace movie
