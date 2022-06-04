#include <chrono>

// std::chrono::hours

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