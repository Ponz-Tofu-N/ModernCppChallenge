#include <algorithm>
#include <numeric>

template <typename RamdomAI>
void quicksort(RamdomAI begin, RamdomAI end)
{
  if (begin == end)
    return;

  // ピボットを決定（インデックスが先頭の値）
  auto pivot = *begin;
  // std::cout << "pivot: " << pivot << std::endl;

  // ピボットを除外した範囲の左端をleft、右端をrightとする
  // 5 3 8 6 2 9 7 4 1ならleft=3, right=1(endは最後の次の位置のため-1する)
  auto left = begin + 1;
  auto right = end - 1;

  // leftは左からpivotよりも大きな値を見つける
  // rightは右からpivotよりも小さな値を見つける
  // left<rightであることを確認して入れ替える。(イテレータがはみ出していないか)
  // この繰り返しが終わると、pivotより小さい値が前に、pivotより大きな値が右側に来る
  // while終了後5 3 1 4 2 9 7 6 8
  while (left <= right)
  {
    while (left <= right && *left < pivot) left++;
    while (left <= right && *right >= pivot) right--;

    if (left < right)
    {
      std::swap(*left, *right);
    }
  }

  // pivot(begin)とpivotより小さい値の一番右(left - 1)と入れ替える。
  // 2 3 1 4 5 9 7 6 8
  std::swap(*begin, *(left - 1));

  // std::cout << "left: " << *left << " "
  //           << "right: " << *right << " "
  //           << "begin: " << *begin << " "
  //           << "end: " << *end << std::endl;
  // for (auto i = begin; i != end; i++)
  // {
  //   std::cout << *i << " ";
  // }
  // std::cout << std::endl;

  // 2 3 1 4 5 9 7 6 8
  // 2 3 1 4 5 | 9 7 6 8 で再度ソートを行う
  quicksort(begin, left - 1);
  quicksort(left, end);
}

template <typename RamdomAI, typename Compare>
void quicksort(RamdomAI begin, RamdomAI end, Compare compare)
{
  if (begin == end)
    return;

  // ピボットを決定（インデックスが先頭の値）
  auto pivot = *begin;

  // ピボットを除外した範囲の左端をleft、右端をrightとする
  // 5 3 8 6 2 9 7 4 1ならleft=3, right=1(endは最後の次の位置のため-1する)
  auto left = begin + 1;
  auto right = end - 1;

  // 比較関数を用いてpivotとleft/rightを大小比較
  // left<rightであることを確認して入れ替える。(イテレータがはみ出していないか)
  // この繰り返しが終わると、pivotより小さい値が前に、pivotより大きな値が右側に来る
  // while終了後5 3 1 4 2 9 7 6 8
  while (left <= right)
  {
    while (left <= right && !compare(*left, pivot)) left++;
    while (left <= right && compare(*right, pivot)) right--;

    if (left < right)
    {
      std::swap(*left, *right);
    }
  }

  // pivot(begin)とpivotより小さい値の一番右(left - 1)と入れ替える。
  // 2 3 1 4 5 9 7 6 8
  std::swap(*begin, *(left - 1));

  // 2 3 1 4 5 9 7 6 8
  // 2 3 1 4 5 | 9 7 6 8 で再度ソートを行う
  quicksort(begin, left - 1);
  quicksort(left, end);
}