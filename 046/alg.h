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

template <class T>
class ring_buffer;

template <typename T>
class ring_buffer_iterator
{
  using self_type = ring_buffer<T>;
  using value_type = T;
  using pointer = T*;
  using reference = T&;
  using const_reference = const T&;

private:
  self_type* rb;
  size_t pos;
  bool last;

public:
  ring_buffer_iterator(self_type* _v, size_t _pos, bool _last = false)
      : rb(_v), pos(_pos), last(_last){};
  ~ring_buffer_iterator(){};

  const_reference operator*() const { return rb->buf.at(pos); };
  reference operator*() { return rb->buf.at(pos); };

  ring_buffer_iterator& operator++()
  {
    if (last) throw std::out_of_range("out of range");
    pos = pos++ % rb->capacity();
    return *this;
  };
  // iterator operator++(int){};
  ring_buffer_iterator& operator--()
  {
    int index = pos - 1;
    if (index < 0) pos = index + rb->capacity();
    return *this;
  };

  ring_buffer_iterator operator+(size_t n)
  {
    // if (last) throw std::out_of_range("out of range");
    pos = (pos + n) % rb->capacity();
    return *this;
  };
  ring_buffer_iterator operator-(const size_t n)
  {  // 2 - 4 % 5
    int index = pos - (n % rb->capacity());
    if (index < 0) index += rb->capacity();

    return ring_buffer_iterator(this->rb, index);
  };

  bool operator==(const ring_buffer_iterator& it) const
  {
    return pos == it.pos;
  };
  bool operator!=(const ring_buffer_iterator& it) const
  {
    return pos != it.pos;
  };
  bool operator>(const ring_buffer_iterator& it) const { return pos > it.pos; };
  bool operator<(const ring_buffer_iterator& it) const { return pos < it.pos; };
  bool operator>=(const ring_buffer_iterator& it) const
  {
    return pos >= it.pos;
  };
  bool operator<=(const ring_buffer_iterator& it) const
  {
    return pos <= it.pos;
  };
};

template <class T>
class ring_buffer
{
  using iterator = ring_buffer_iterator<T>;

private:
  std::vector<T> buf;
  size_t max_size;
  size_t pos = 0;

public:
  ring_buffer(/* args */) = delete;
  ring_buffer(const size_t n) : buf(n), max_size(n) {}

  ~ring_buffer(){};

  void push(const T& element)
  {
    if (pos == max_size) pos = 0;

    buf[pos] = element;
    pos++;
  };

  bool full() { return max_size == buf.size(); };
  bool empty() { return buf.empty(); };
  size_t size() { return buf.size(); };
  size_t capacity() { return max_size; };

  iterator begin() { return iterator(this, 0); }
  iterator end() { return iterator(this, max_size - 1, true); }

  T& operator[](const size_t& index) { return buf.at(index); };

  friend class ring_buffer_iterator<T>;
};

}  // namespace alg
