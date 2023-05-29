/*
正整数n,mが与えられたとき，nをm個以下の正整数の和で表す方法が何通りあるかを，
動的計画法を用いて求めるアルゴリズムとその計算量を示せ．
考え方の説明，動作例をつけること．
※和をとる順番が違っても同じものとみなす
　(1+1+2 と 1+2+1 は同じ)
ヒント:m個の正整数の和になる場合と，m-1個以下の正整数の和になる場合で分ける
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> Table(n, vector<int>(k, 0));

    Table[0][0] = 1;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (i - j >= 0) {
                Table[i][j] = (Table[i - 1][j - 1] + Table[i - j][j]) % MOD;
            } else {
                Table[i][j] = Table[i - 1][j - 1];
            }
        }
    }
    cout << p[n][m] << endl;
}