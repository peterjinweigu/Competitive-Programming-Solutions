// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: money
LANG: C++14          
*/


int main() {
	ofstream cout ("money.out");
    ifstream cin ("money.in"); 
    
    int v, n; cin >> v >> n;
    vector<ll> dp(n+1);
    vector<ll> cost(v);
    for (int i = 0; i < v; i++) cin >> cost[i];
    for (int i = 0; i <= n; i++) dp[i] = 0;
    dp[0] = 1;
    for (auto j : cost) {
        for (int i = 0; i <= n; i++) {
            if (j + i <= n) dp[j+i] += dp[i];
        }
    }
    cout << dp[n] << "\n";
}

