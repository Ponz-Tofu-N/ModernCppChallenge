#include <algorithm>
#include <cmath>
#include <iostream>
#include <thread>

template <typename Func>
void print_erapsedtime(Func&& f, std::string message = "")
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

template <typename RandomAccessIterator, typename F>
void ptransform(RandomAccessIterator begin, RandomAccessIterator end, F&& f)
{
  auto size = std::distance(begin, end);
  if (size <= 10000)
  {
    std::transform(begin, end, begin, std::forward<F>(f));
  }
  else
  {
    std::vector<std::thread> threads;
    int thread_count = 10;
    auto first       = begin;
    auto last        = first;
    size /= thread_count;
    for (int i = 0; i < thread_count; ++i)
    {
      first = last;
      if (i == thread_count - 1)
        last = end;
      else
        std::advance(last, size);

      threads.emplace_back(
          [first, last, &f]()
          { std::transform(first, last, first, std::forward<F>(f)); });
    }

    for (auto& t : threads) t.join();
  }
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