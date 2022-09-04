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

  void log() { std::cout << "logging..." << std::endl; }

 private:
  constexpr Logger() {}
};