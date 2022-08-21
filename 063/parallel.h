#include <algorithm>
#include <cmath>
#include <future>
#include <iostream>
#include <thread>

template <typename Func>
void print_erapsedtime(Func&& f, std::string message)
{
  auto start = std::chrono::system_clock::now();

  f();

  auto end = std::chrono::system_clock::now();

  auto erapsed_time =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << message + ": " << erapsed_time.count() << " ms" << std::endl;
}

template <typename Container>
void print(const Container c)
{
  for (auto&& i : c)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

template <typename RandomAI>
auto async_transform(RandomAI begin, RandomAI end)
{
  const float size        = std::distance(begin, end);
  const auto thread_count = std::thread::hardware_concurrency();
  const size_t lots       = std::ceil(size / thread_count);

  auto first = begin;
  auto last  = begin;

  //  std::iterator_traits<Iterator>::value_typeを使うと、イテレータでもポインタでも受け取れる
  using value_type = typename std::iterator_traits<RandomAI>::value_type;
  std::vector<std::future<value_type>> asyncs;
  std::vector<value_type> maxs;

  for (size_t i = 0; i < thread_count; i++)
  {
    first = last;
    last  = (i == thread_count - 1) ? end : first + lots;

    const auto threaded = [](auto first, auto last)
    { return *std::max_element(first, last); };

    // 一度変数に格納すると、push_backがエラーになる
    //　std::futureのコピーコンストラクタがデリートされているため？
    asyncs.push_back(std::async(std::launch::async, threaded, first, last));
  }

  for (auto&& i : asyncs)
  {
    maxs.push_back(i.get());
  }

  return *std::max_element(std::begin(maxs), std::end(maxs));
}
