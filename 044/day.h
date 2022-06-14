#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

#include "cctz/time_zone.h"

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

struct timezone
{
  std::string name;
  cctz::time_zone::absolute_lookup lookup;
};

class user
{
public:
  user(std::string _name, std::string _tz_name)
      : name(_name), tz_name(_tz_name){};

  std::string get_name() const { return name; }
  std::string get_tz_name() const { return tz_name; }

private:
  std::string name;
  std::string tz_name;
};

std::vector<std::string> timezone_list(
    const std::vector<user>& users, std::chrono::system_clock::time_point now =
                                        std::chrono::system_clock::now())
{
  std::vector<std::string> list;

  for (auto&& user : users)
  {
    cctz::time_zone tz;
    cctz::load_time_zone(user.get_tz_name(), &tz);
    cctz::time_zone::absolute_lookup lookup = tz.lookup(now);

    cctz::time_point<cctz::seconds> tp = cctz::convert(lookup.cs, tz);

    std::string f = cctz::format("%Y-%m-%d %H:%M:%S", tp, tz);  //%H:%M:%S

    list.push_back(tz.name() + ": " + f);
  }

  return list;
}

void calender(const int& _y, const unsigned int& _m)
{
  const std::chrono::year y{_y};
  const std::chrono::month m{_m};
  std::chrono::year_month_day ymd{y / (m - std::chrono::months{1}) /
                                  std::chrono::last};
  const auto before =
      std::chrono::weekday{std::chrono::sys_days(ymd)}.iso_encoding();
  const auto last = static_cast<unsigned int>(ymd.day());

  std::cout << static_cast<unsigned int>(ymd.month()) << ','
            << static_cast<int>(ymd.year()) << std::endl;
  std::cout << "Mon Tue Wed Thu Fri Sat Sun" << std::endl;

  for (size_t i = 0; i < before; i++)
  {
    std::cout << std::setw(3) << ' ' << ' ';
  }

  for (size_t i = 1; i < last; i++)
  {
    if (!((i + before - 1) % 7)) std::cout << std::endl;

    std::cout << std::right << std::setw(3) << i << ' ';
  }

  std::cout << std::endl;
}

}  // namespace myday