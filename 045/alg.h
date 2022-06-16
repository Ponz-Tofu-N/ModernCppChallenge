#include <functional>
#include <vector>

namespace alg
{
// ヒープ構造を使用する。
// 標準ライブラリのヒープ構造を操作する関数を採用する。
template <typename T,
          typename Compare = std::less<typename std::vector<T>::value_type>>
class priority_queue
{
private:
  std::vector<T> queue;
  // value_type
  // vector が維持する要素に関連付けられた型
  using value_type = typename std::vector<T>::value_type;
  // const_reference
  // 要素が変更されることを許可しない配下要素への参照
  using const_reference = typename std::vector<T>::const_reference;
  // size_type
  // 符号なし整数型、コンテナのサイズを示すために使用される
  using size_type = typename std::vector<T>::size_type;

public:
  priority_queue(const std::initializer_list<T>& init)
      : queue(init.begin(), init.end())
  {
    std::make_heap(queue.begin(), queue.end(), Compare());
  };
  ~priority_queue(){};

  void push(const_reference e)
  {
    queue.push_back(e);
    std::push_heap(queue.begin(), queue.end(), Compare());
  };
  void pop()
  {
    std::pop_heap(queue.begin(), queue.end(), Compare());
    queue.pop_back();
  };
  const_reference top() { return queue.front(); }
  size_type size() const { return queue.size(); }
  bool empty() const { return queue.empty(); }
};

}  // namespace alg
