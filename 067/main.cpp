/* 67. Customable password validation*/

/*
 * Rule
 *  - validate the given password by chosen rules
 */

#include "validator.h"

#include <string>

// 長さの検証
// 少なくとも一つの記号
// 数字
// 大文字
// 小文字

int main(int argc, char const* argv[])
{
  std::string password = "aaa";

  // バリデータを構築
  auto p = std::make_unique<length_validator>();
  number_validator nv(p.get());

  
  // パスワードを検証
  nv.validate();


  return 0;
}
