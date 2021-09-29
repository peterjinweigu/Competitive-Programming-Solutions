#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>

struct dest{
    int cost, x, y;
};
struct compare{
    bool operator()(dest const&a, dest const&b){
        return a.cost < b.cost;
    }
};

using namespace std;
typedef long long bigNum;
typedef pair<int, int> pi;
int n, a, b, temp, tempp, xx, yy, dd;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector <pi> v;
    vector <dest> pairs;
    int dist[n+1];
    int dp[2][n+1];
    memset(dist, 0, sizeof dist);
    for (int i = 0; i < 2; i++){
        for (int j = 0; j <= n; j++){
            dp[i][j] = 0;
        }
    }
    v.push_back(make_pair(0,0));
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    for (int i = 0; i < v.size(); i++){
        for (int j = i+1; j < v.size(); j++){
            temp = v[i].first - v[j].first;
            tempp = v[i].second - v[j].second;
            pairs.push_back(dest{abs(temp) * abs(temp) + abs(tempp) * abs(tempp), i, j});
        }
    }
    sort(pairs.begin(), pairs.end(), compare());
    for (int i = 0; i < pairs.size(); i++){
        xx = pairs[i].x;
        yy = pairs[i].y;
        dd = pairs[i].cost;
        if(dd != dist[xx]){
            dist[xx] = dd;
            dp[1][xx] = dp[0][xx];
        }
        if(dd != dist[yy]){
            dist[yy] = dd;
            dp[1][yy] = dp[0][yy];
        }
        if (xx == 0){
            dp[0][xx] = max(dp[0][xx], dp[1][yy]);
        }else{
            dp[0][xx] = max(dp[0][xx], dp[1][yy] + 1);
            dp[0][yy] = max(dp[0][yy], dp[1][xx] + 1);
        }
    }
    cout << dp[0][0] + 1 << endl;
}
