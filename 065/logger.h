#include <iostream>
#include <thread>

class Logger
{
 public:
  static Logger& instance()
  {
    static Logger log;
    return log;
  }
  Logger(const Logger& other)         = delete;
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