#include <bits/stdc++.h>
using namespace std;

int calc(int n, int m){
    if(m == 1){return 1;}
    vector<vector<int>> Table(n + 1, vector<int>(m + 1, 0));
    Table[0][0] = 1;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (i - j >= 0) {
                Table[i][j] = (Table[i - 1][j - 1] + Table[i - j][j]);
            } else {
                Table[i][j] = Table[i - 1][j - 1];
            }
        }
    }
    return Table[n][m] + calc(n, m-1);
}

int main(){
    int n, m;
    cin >> n >> m;
    int ans = calc(n, m);
    cout << ans << endl;
}