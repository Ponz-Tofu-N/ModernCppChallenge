#include <iostream>
#include <mutex>
#include <thread>

class Logger
{
public:
  static Logger& instance()
  {
    static Logger log;
    return log;
  }
  Logger(const Logger& other) = delete;
  void operator=(const Logger& other) = delete;

  template <typename... T>
  void log(T&... t)
  {
    lock.lock();

    std::cout << "[Log]: ";
    (std::cout << ... << t);
    std::cout << "\n";

    lock.unlock();
  }

private:
  constexpr Logger() {}
  std::mutex lock;
};

// mutexロックがないときは出力の間に他の出力が発生する場合がある。
// [log] 1: 0 2: 1
// [log] 1: 1 2: 0
// [log] 1: 2 2: 9
// [log] 1: 4 2: 8
// [log] 1: 5 2: 2
// [log] 1: 6 2: 7
// [log] [log] 1: 8 2: 5
// [log] 1: 9 2: 3
// [log] 1: 7 2: 10
// 1: 3 2: 1