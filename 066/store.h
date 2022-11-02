#include "context.h"

class machine
{
private:
  unsigned int last_ticket_number = 100;

public:
  unsigned int ticketing() { return last_ticket_number; }
  void next() { last_ticket_number++; }

  machine(/* args */);
  ~machine();
};

machine::machine(/* args */) {}

machine::~machine() {}

// デスクは対応中かどうかが分かる
// 対応が終わると通知する？
// 一人当たりの対応時間は乱数で決定する
// デスクに顧客を割り当てるのは誰の仕事？
class desk
{
private:
  bool occupied = false;

public:
  void process();
  desk(/* args */);
  ~desk();
};

desk::desk(/* args */) {}
desk::~desk() {}

void desk::process()
{
  occupied = true;
  context::instance().interval();
  occupied = false;
}