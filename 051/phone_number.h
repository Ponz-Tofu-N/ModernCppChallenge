#include <algorithm>
#include <string>
#include <vector>

std::vector<std::string> filter_numbers(std::vector<std::string> const& numbers,
                                        std::string const& key)
{
  std::vector<std::string> result;

  std::copy_if(numbers.begin(), numbers.end(),
               std::back_insert_iterator<std::vector<std::string>>(result),
               [&key](auto const n) {
                 int range = std::isdigit(n[0]) ? 2 : 3;
                 return std::includes(n.begin(), n.begin() + range, key.begin(),
                                      key.end());
               });

  return result;
}

std::vector<std::string> normalize_phone_numbers(
    std::vector<std::string> const& list, std::string const& key)
{
  std::vector<std::string> result;
  std::transform(
      list.begin(), list.end(), std::back_insert_iterator(result),
      [&key](auto n) {
        /* スペースを削除 */
        std::remove_if(n.begin(), n.end(), [](auto c) { return c == ' '; });

        switch (n[0])
        {
            /* 先頭が０だったら国番号に置き換え */
          case '0':
            n.erase(0, 1);
            break;
            /* +だったら何もしない */
          case '+':
            return n;

            /*先頭が国番号だったら削除*/
          default:
            if (std::includes(n.begin(), n.begin() + 2, key.begin(), key.end()))
              n.erase(0, 2);

            break;
        }

        //先頭に国番号を結合
        n = '+' + key + n;

        return n;
      });

  return result;
}