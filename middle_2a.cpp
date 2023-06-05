/*
PRAM上での並列ソーティングアルゴリズムを設計・評価せよ．
並列クイックソート
*/

#include <bits/stdc++.h>
using namespace std;

template < class RandomIter >
//! A template function.
/*!
    指定された範囲の要素をクイックソートでソートする（`std::thread`で並列化）
    \param first 範囲の下限
    \param last 範囲の上限
*/
inline void quick_sort_thread(RandomIter first, RandomIter last)
{
    // 再帰ありの並列クイックソートの関数を呼び出す
    quick_sort_thread(first, last, 0);
}

template < class RandomIter >
//! A template function.
/*!
    指定された範囲の要素をクイックソートでソートする（`std::thread`で並列化）
    \param first 範囲の下限
    \param last 範囲の上限
    \param reci 現在の再帰の深さ
*/
void quick_sort_thread(RandomIter first, RandomIter last, std::int32_t reci)
{
    // 部分ソートの要素数
    auto const num = std::distance(first, last);

    if (num <= 1) {
        // 部分ソートの要素数が1個以下なら何もすることはない
        return;
    }

    // 再帰の深さ + 1
    reci++;

        // 部分ソートが小さくなりすぎるとシリアル実行のほうが効率が良くなるため
        // 部分ソートの要素数が閾値以上の時だけ再帰させる
        // かつ、現在の再帰の深さがSTDTHREADRECMAX( = 7)以下のときだけ再帰させる
        if (num >= THRESHOLD && reci <= STDTHREADRECMAX) {
            // 交点まで左右から入れ替えして交点を探す
            auto const middle = std::partition(first + 1, last, [first](auto n) { return n < *first; });

            // 交点 - 1の位置
            auto const mid = middle - 1;

            // 交点を移動
            std::iter_swap(first, mid);

            // 下部をソート（別スレッドで実行）
            auto th1 = std::thread([first, mid, reci]() { quick_sort_thread(first, mid, reci); });

            // 上部をソート（別スレッドで実行）
            auto th2 = std::thread([middle, last, reci]() { quick_sort_thread(middle, last, reci); });

        // 二つのスレッドの終了を待機
        th1.join();
        th2.join();
    }
    else {
        // 再帰なしのクイックソートの関数を呼び出す
        quick_sort(first, last);
    }
}