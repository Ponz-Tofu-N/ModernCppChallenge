#include <chrono>

// std::chrono::hours
namespace myday
{
std::chrono::weekday what_weekday(const int y, const int m, const int d)
{
  using namespace std::chrono_literals;
  using namespace std::chrono;

  // std::chrono::sys_daysは日付を表現するクラス
  // コンストラクタでyear/month/dayを与える。
  // yearがstd::chrono::year型ならoperator/の後に整数で月日を指定できる。
  sys_days date{year{y} / m / d};

  return weekday(date);
}

void today(int& y, int& m, int& d)
{
  auto today = std::chrono::system_clock::now();

  // std::chrono::year_month_dayで日付を表現できる
  // std::chrono::floorで単位を日に丸めることができる
  std::chrono::year_month_day ymd{std::chrono::floor<std::chrono::days>(today)};

  // 年月日を整数値にキャストする
  y = static_cast<int>(ymd.year());
  m = static_cast<unsigned int>(ymd.month());
  d = static_cast<unsigned int>(ymd.day());

  std::cout << y << "/" << m << "/" << d << std::endl;
}
}  // namespace myday