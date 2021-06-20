#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>

struct part{
    int cost, value;
};

using namespace std;
typedef long long bigNum;
typedef pair<int, int> pi;
int t, n, a, b, c, bud;
part item;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    cin >> n;
    vector <part> all[t+1];
    for (int i = 0; i < n; i++){
        cin >> a >> b >> c;
        all[c].push_back(part{a,b});
    }
    cin >> bud;
    int dp[t+1][bud+1];
    for (int j = 0; j <= bud; j++){
        dp[0][j] = 0;
    }
    for (int i = 1; i <= t; i++){
        for (int j = 0; j <= bud; j++){
            dp[i][j] = -1;
        }
    }
    for (int i = 1; i <= t; i++){
        for (int j = 0; j < all[i].size(); j++){
            item = all[i][j];
            for (int h = item.cost; h <= bud; h++){
                if (dp[i-1][h-item.cost] != -1){
                    dp[i][h] = max(dp[i][h], item.value + dp[i-1][h-item.cost]);
                }
            }
        }
    }
    cout << dp[t][bud] << endl;

}