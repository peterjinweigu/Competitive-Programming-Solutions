// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: subset
LANG: C++14          
*/


int main() {
	ofstream cout ("subset.out");
    ifstream cin ("subset.in");
    
	ll n; cin >> n;
	ll k = n*(n+1)/2;
	vector<ll> dp(k+1);
	for (int i = 0; i <= k; i++) dp[i] = 0;
	dp[0] = 1;
	for (ll i = 1; i <= n; i++) {
		for (ll j = k; j >= i; j--) {
			dp[j] += dp[j - i];
		}
	}
	if (k % 2 == 0) cout << dp[k/2]/2 << "\n";
	else cout << 0 << "\n";
}

