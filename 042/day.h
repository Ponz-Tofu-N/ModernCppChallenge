#include <chrono>

namespace myday
{
std::chrono::days day_distance(const int y1, const int m1, const int d1,
                               const int y2, const int m2, const int d2)
{
  using namespace std::chrono_literals;
  using namespace std::chrono;

  auto day1 = years{y1} + months{m1} + days{d1};
  auto day2 = years{y2} + months{m2} + days{d2};

  auto distance = time_point<system_clock>(day1 - day2).time_since_epoch();

  return duration_cast<days>(distance);
}

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
}

int day_of_year(int y, int m, int d)
{
  using namespace std::chrono_literals;
  using namespace std::chrono;

  sys_days date{year{y} / m / d};

  return (date - sys_days{year{y} / January / 1}).count() + 1;
}

int week_of_year(int y, int m, int d)
{
  using namespace std::chrono_literals;
  using namespace std::chrono;

  sys_days date{year{y} / m / d};

  return duration_cast<weeks>(date - sys_days{year{y} / January / 1}).count() +
         1;
}
}  // namespace myday