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

template <typename RandomAI, typename Compare>
auto part_range(RandomAI begin, RandomAI end, Compare compare)
{
  // ピボットを決定（インデックスが先頭の値）
  auto pivot = *begin;

  // ピボットを除外した範囲の左端をleft、右端をrightとする
  // 5 3 8 6 2 9 7 4 1ならleft=3, right=1(endは最後の次の位置のため-1する)
  auto left  = begin + 1;
  auto right = end - 1;
  // 比較関数を用いてpivotとleft/rightを大小比較
  // left<rightであることを確認して入れ替える。(イテレータがはみ出していないか)
  // この繰り返しが終わると、pivotより小さい値が前に、pivotより大きな値が右側に来る
  // while終了後5 3 1 4 2 9 7 6 8
  while (left <= right)
  {
    while (left <= right && compare(*left, pivot)) left++;
    while (left <= right && !compare(*right, pivot)) right--;

    if (left < right)
    {
      std::iter_swap(left, right);
    }
  }
  // pivot(begin)とpivotより小さい値の一番右(left - 1)と入れ替える。
  // 5 3 1 4 2 9 7 6 8 -> 2 3 1 4 5 9 7 6 8
  // std::swap(*begin, *(left - 1));
  std::iter_swap(left - 1, begin);

  return left - 1;
}

template <typename RandomAI, typename Compare>
void async_qsort(RandomAI begin, RandomAI end, Compare compare)
{
  auto distance = std::distance(begin, end);
  auto pos      = part_range(begin, end, compare);

  // 2 3 1 4 5 9 7 6 8
  // 2 3 1 4 5 | 9 7 6 8 で再度ソートを行う
  // std::function<auto(RandomAI, RandomAI)> f = &async_qsort;

  // 要素が少なすぎると、ソートを行うコストより、スレッドを生成するコストの方が大きくなるため遅かった。
  if (distance == 0) return;
  // 残りの要素数に応じて非同期するかどうかを決定する
  // あまり少なすぎると逆に遅い（スレッドを複数生成するため？）
  if (distance < 10000)
  {
    async_qsort(begin, pos, compare);
    async_qsort(pos + 1, end, compare);

    return;
  }

  auto p1 = std::async(std::launch::async,
                       [begin, pos, &compare]()
                       { async_qsort(begin, pos, compare); });
  auto p2 = std::async(std::launch::async,
                       [pos, end, &compare]()
                       { async_qsort(pos + 1, end, compare); });
  p1.wait();
  p2.wait();

  // async_qsort(begin, parted_pos - 1, compare);
  // async_qsort(parted_pos, end, compare);
}

template <typename Iterator>
auto async_max(Iterator begin, Iterator end)
{
  return async_transform(begin,
                         end,
                         [](auto first, auto last)
                         { return *std::max_element(first, last); });
}

template <typename Iterator>
auto async_min(Iterator begin, Iterator end)
{
  return async_transform(begin,
                         end,
                         [](auto first, auto last)
                         { return *std::min_element(first, last); });
}