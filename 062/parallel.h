#include <algorithm>
#include <cmath>
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

/*コンテナのサイズを並列可能数で割り、ロットの数を決める*/
/*上からスレッド数分取り出し、各スレッドで計算する*/
/*全てのスレッドが完了したら、次のロットに移行する*/
/*これは失敗作*/
/*これだと計算コストよりもthreadオブジェクトの構築の方が時間がかかっている感じがする*/
/*総タスクを並列可能な数に分割する方針の方が速い*/
template <typename RandomAI, typename Func>
void thread_transform(RandomAI begin, RandomAI end, Func&& f)
{
  const float size        = std::distance(begin, end);
  const auto thread_count = std::thread::hardware_concurrency();
  const size_t lots       = std::ceil(size / thread_count);

  auto first = begin;
  auto last  = begin;

  for (size_t i = 0; i < lots; i++)
  {
    first = last;
    last  = size < (1 + i) * thread_count ? first + thread_count : end;

    std::vector<std::thread> threads;
    for (auto itrator = first; itrator != last; itrator++)
    {
      threads.emplace_back([itrator, f]() { *itrator = f(*itrator); });
    }

    for (auto& t : threads)
    {
      t.join();
    }
  }
}

template <typename RandomAI, typename Func>
void thread_transform_ver2(RandomAI begin, RandomAI end, Func&& f)
{
  const float size        = std::distance(begin, end);
  const auto thread_count = std::thread::hardware_concurrency();
  const size_t lots       = std::ceil(size / thread_count);

  auto first = begin;
  auto last  = begin;

  std::vector<std::thread> threads;
  for (size_t i = 0; i < thread_count; i++)
  {
    first = last;
    last  = (i == thread_count - 1) ? end : first + lots;

    const auto threaded = [first, last, &f]()
    { std::transform(first, last, first, std::forward<Func>(f)); };

    threads.emplace_back(threaded);
  }

  for (auto& t : threads)
  {
    t.join();
  }
}

template <typename RandomAI>
auto threaded_max_element(RandomAI begin, RandomAI end)
{
  const float size        = std::distance(begin, end);
  const auto thread_count = std::thread::hardware_concurrency();
  const size_t lots       = std::ceil(size / thread_count);

  auto first = begin;
  auto last  = begin;

  std::vector<std::thread> threads;
  std::vector<typename RandomAI::value_type> maxs;
  for (size_t i = 0; i < thread_count; i++)
  {
    first = last;
    last  = (i == thread_count - 1) ? end : first + lots;

    const auto threaded = [first, last, &maxs]()
    {
      auto max_iterator = std::max_element(first, last);
      maxs.push_back(*max_iterator);
    };

    threads.emplace_back(threaded);
  }

  for (auto& t : threads)
  {
    t.join();
  }

  return *std::max_element(maxs.begin(), maxs.end());
}

template <typename RandomAI>
auto threaded_min_element(RandomAI begin, RandomAI end)
{
  const float size        = std::distance(begin, end);
  const auto thread_count = std::thread::hardware_concurrency();
  const size_t lots       = std::ceil(size / thread_count);

  auto first = begin;
  auto last  = begin;

  std::vector<std::thread> threads;
  std::vector<typename RandomAI::value_type> maxs;
  for (size_t i = 0; i < thread_count; i++)
  {
    first = last;
    last  = (i == thread_count - 1) ? end : first + lots;

    const auto threaded = [first, last, &maxs]()
    {
      auto max_iterator = std::max_element(first, last);
      maxs.push_back(*max_iterator);
    };

    threads.emplace_back(threaded);
  }

  for (auto& t : threads)
  {
    t.join();
  }

  return *std::max_element(maxs.begin(), maxs.end());
}

template <typename RandomAI, typename Func>
auto threaded_invoke(RandomAI begin, RandomAI end, Func&& f)
{
  const float size        = std::distance(begin, end);
  const auto thread_count = std::thread::hardware_concurrency();
  const size_t lots       = std::ceil(size / thread_count);

  auto first = begin;
  auto last  = begin;

  std::vector<std::thread> threads;

  // 型定義に三項演算子は使えない？
  // using typename value_type = std::is_pointer<RandomAI>::type
  //                                 ? std::decay<RandomAI>::type
  //                                 : RandomAI::value_type;

  // 変数から型を推測しているが、RandomAIから推測できないものか
  std::vector<typename std::remove_reference<decltype(*begin)>::type> maxs;
  for (size_t i = 1; i <= thread_count; i++)
  {
    first = last;
    last  = (i == thread_count) ? end : first + lots;

    const auto threaded = [first, last, &maxs, &f]()
    {
      auto max_iterator = f(first, last);
      maxs.push_back(max_iterator);
    };

    threads.emplace_back(threaded);
  }

  for (auto& t : threads)
  {
    t.join();
  }

  return f(maxs.begin(), maxs.end());
}

template <typename RandomAI>
auto threaded_max_element_2(RandomAI begin, RandomAI end)
{
  return threaded_invoke(begin,
                         end,
                         [](auto first, auto last)
                         { return *std::max_element(first, last); });
}

template <typename RandomAI>
auto threaded_min_element_2(RandomAI begin, RandomAI end)
{
  return threaded_invoke(begin,
                         end,
                         [](auto first, auto last)
                         { return *std::min_element(first, last); });
}
