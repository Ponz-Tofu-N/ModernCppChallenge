#include <vector>
#include <functional>

// std::decayで関数オブジェクトFuncを関数ポインタFuncPtrに変換する。←いる？
// std::invoke_result<FuncPtr, Args...>::typeで関数の返り値の型を取得できる。
// Containerクラスがvalue_typeを持っている前提？
//　typenameをつけると任意の型として定義できる
template <typename Container,
  typename Func,
  typename R = typename std::invoke_result<Func, typename Container::value_type>::type>
typename std::vector<R> select(Container c, Func&& f) {
  std::vector<R> res;
  std::transform(std::begin(c), std::end(c), std::back_insert_iterator(res), std::forward<Func>(f));

  return res;
}