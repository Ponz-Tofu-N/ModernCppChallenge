#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <mutex>
#include <thread>

namespace alg
{
template <class T>
class double_buffer
{
  using pointer = T*;
  using value_type = T;

  // 読み書き中はその面を排他制御する
  // std::mutex
  //
public:
  double_buffer(const size_t& size)
      : mSize(size),
        forRead(new value_type[size]),
        forWrite(new value_type[size])
  {
    std::fill(forRead, forRead + mSize - 1, 0);
    std::fill(forWrite, forWrite + mSize - 1, 0);
  }
  // 書き込み面にコピーする。
  // 引数は？ → vector, 配列, initializer_list？
  //   void write(const std::vector<T>&){};
  void write(pointer ptr, size_t size)
  {
    using namespace std::chrono_literals;
    auto len = std::min(mSize, size);

    std::unique_lock<std::mutex> lock(m);

    std::copy(ptr, ptr + len, forWrite);
    std::swap(forWrite, forRead);

    lock.unlock();
  };
  // 読み取り面を出力
  //コンソールへの出力もmutexを取得した状態で行う。
  template <typename Output>
  void read(Output i) const
  {
    std::unique_lock<std::mutex> lock(m);

    std::copy(forRead, forRead + mSize, i);

    lock.unlock();
    // return forRead;
  };

  size_t size() const { return mSize; }

private:
  pointer forWrite;
  pointer forRead;

  size_t mSize;

  mutable std::mutex m;
};

template <class T>
static void print_buffer(const double_buffer<T>& db)
{
  /*auto rd = */ db.read(std::ostream_iterator<T>(std::cout, ", "));
  //   for (auto i = 0; i < db.size(); i++)
  //   {
  //     std::cout << *(rd + i) << " ";
  //   }
  std::cout << std::endl;
};

}  // namespace alg