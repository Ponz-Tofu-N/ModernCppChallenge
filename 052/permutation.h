#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// m a i n
// m + p(a i n)
// m + (a + p(i n))
// m + (a + (i + p(n)))

void permuration(std::string in, std::string pre)
{
  if (in.size() == 1)
  {
    std::cout << pre + in << std::endl;
    return;
  }

  for (size_t j = 0; j < in.size(); j++)
  {
    // indexの文字を抜いた文字列を取得する。
    std::string rest;
    std::copy_if(in.begin(), in.end(), std::back_insert_iterator(rest),
                 [&](auto c) { return in[j] != c; });

    // 順序が決定済みの文字列と残りの文字列を引数に再帰実行
    permuration(rest, pre + in[j]);
  }
}

void print_permutations_recursive(std::string const& target)
{
  permuration(target, "");
}

void print_permutations() {}