#ifndef CONTEXT_H
#define CONTEXT_H

#include <chrono>
#include <random>
#include <thread>

// デスクの対応時間
// 顧客追加のインターバル
//

class context
{
private:
  context();

public:
  context(const context&) = delete;
  context(context&&) = delete;
  void operator=(const context&) = delete;

  ~context();

  static context& instance()
  {
    static context ctxt;
    return ctxt;
  }

  void interval()
  {
    std::random_device seet_gen;
    std::mt19937 mt(seet_gen());
    std::uniform_int_distribution dist(2000, 3000);

    std::this_thread::sleep_for(std::chrono::milliseconds(dist(mt)));
  }

  void coming()
  {
    std::random_device seet_gen;
    std::mt19937 mt(seet_gen());
    std::uniform_int_distribution dist(300, 800);

    std::this_thread::sleep_for(std::chrono::milliseconds(dist(mt)));
  }
};

context::context() {}

context::~context() {}

#endif