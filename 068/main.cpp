/* 68. Customable password Generator*/

/*
 * Rule
 *  - generator a password by chosen rules
 */

#include <string>

#include "generator.h"

// 長さの検証
// 少なくとも一つの記号
// 数字
// 大文字
// 小文字

int main(int argc, char const* argv[]) {
  password_generators gen;

  gen.add(std::make_unique<number_generator>(4));
  gen.add(std::make_unique<symbol_generator>(1));
  gen.add(std::make_unique<uppercase_generator>(5));

  auto password = gen.generate();

  std::cout << "pw: " << password << std::endl;

  return 0;
}
