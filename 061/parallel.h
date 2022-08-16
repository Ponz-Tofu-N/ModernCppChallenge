#include <algorithm>
#include <cmath>
#include <iostream>
#include <thread>

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
template <typename RamdomAI, typename Func>
void thread_transform(RamdomAI begin, RamdomAI end, Func&& f)
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

template <typename RamdomAI, typename Func>
void thread_transform_ver2(RamdomAI begin, RamdomAI end, Func&& f)
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