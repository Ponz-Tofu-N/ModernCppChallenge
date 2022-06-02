#include <chrono>
#include <functional>
#include <iostream>

template <typename Duration = std::chrono::milliseconds,
          typename Clock = std::chrono::high_resolution_clock>
struct time_count
{
  template <typename Func, typename... Args>
  void count(Func &&f, Args &&... args)
  {
    auto start = Clock::now().time_since_epoch();

    std::invoke(f, args...);

    auto finish = Clock::now().time_since_epoch();

    auto duration = std::chrono::duration_cast<Duration>(finish - start);
    std::cout << "elapsed time: " << duration.count() << std::endl;
  };
};
