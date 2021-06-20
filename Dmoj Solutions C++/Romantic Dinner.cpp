#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
struct res{
    int v, t, f;
};

using namespace std;
typedef long long bigNum;
typedef pair<int, int> pi;
int m, u, r, a, b, c;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> u >> r;
    res arr[r];
    int dp[u+1][m+1];
    for (int i = 0; i <= u; i++){
        for (int j = 0; j <= m; j++){
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < r; i++){
        cin >> a >> b >> c;
        if (b > m || c > u){
            continue;
        }
        arr[i] = res{a,b,c};
    }
    res cur;
    for (int i = 0; i < r; i++){
        cur = arr[i];
        for (int h = u; h >= cur.f; h--){
            for (int j = m; j >= cur.t; j--){
                if (dp[h][j] < cur.v + dp[h-cur.f][j-cur.t]){
                    dp[h][j] = max(dp[h][j], cur.v + dp[h-cur.f][j-cur.t]);
                }
            }
        }
    }
    cout << dp[u][m] << endl;
}