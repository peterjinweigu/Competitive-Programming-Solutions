// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: numtri
LANG: C++14          
*/

int dp[1001][1001];

int main() {
	ofstream cout ("numtri.out");
    ifstream cin ("numtri.in");
	int ans = 0;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			int x; cin >> x;
			dp[i+1][j] = max(dp[i+1][j], dp[i][j] + x);
			dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + x);
			ans = max(ans, max(dp[i+1][j], dp[i+1][j+1]));
		}
	}
	cout << ans << "\n";
}

	