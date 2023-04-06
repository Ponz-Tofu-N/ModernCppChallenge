/* 67. Customable password validation*/

/*
 * Rule
 *  - validate the given password by chosen rules
 */

#include <string>

#include "validator.h"

// 長さの検証
// 少なくとも一つの記号
// 数字
// 大文字
// 小文字

int main(int argc, char const* argv[])
{
  std::string password = "aaaAAA11123";

  // バリデータを構築
  digit_validator dig_v(new uppercase_validator(new length_validator(13)));

  // パスワードを検証
  dig_v.validate(password);

  return 0;
}
