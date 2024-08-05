// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;
#define MOD 9901

/*
ID: petergu1
TASK: nocows
LANG: C++14          
*/

int dp[110][210];

int solve(int k, int n) {
    if (dp[k][n] != -1) return dp[k][n];
    if (k == 0 && n != 0) return 0;
    if (k != 0 && n == 0) return 0;
    
    dp[k][n] = 0;
    int temp = 0;
    for (int i = 2*k; i <= n; i+=2) {
        int cnt = 0;
        for (int j = min((n-i)/2, k-2); j >= 0; j--) cnt = (cnt + solve(j, n - i)) % MOD;
        dp[k][n] += cnt * solve(k-1, i-2);
        dp[k][n] %= MOD;
        temp += solve(k-1, i-2) * solve(k-1, n-i);
        temp %= MOD;
    }

    dp[k][n] *= 2;
    dp[k][n] %= MOD;
    dp[k][n] += temp;
    dp[k][n] %= MOD;

    return dp[k][n];
}

int main() {
	ofstream cout ("nocows.out");
    ifstream cin ("nocows.in"); 

    int n, k; cin >> n >> k;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) dp[i][j] = -1;
    }
    dp[0][0] = 1;
    cout << solve(k-1, n-1) << "\n";
}

