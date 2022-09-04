/* 65. Thead-safe Logger*/

/*
 * features
 *  a class that can log thread-safe.
 */

#include "logger.h"

int main(int argc, char const *argv[])
{
  // コピーコンストラクタとなるため変数に入れることはできない。
  // auto log = Logger::instance();
  Logger::instance().log();
  Logger::instance().log();
  Logger::instance().log();
  Logger::instance().log();
  Logger::instance().log();
  Logger::instance().log();
  return 0;
}
