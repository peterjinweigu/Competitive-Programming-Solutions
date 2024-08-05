// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000010
#define MOD 1000000007
typedef long long ll;
typedef pair<ll, ll> pi;

ll exp(ll x, ll n) {
	ll y = 1;
    while (n > 0) {
        if (n % 2 == 1) y = y*x % MOD;
        n /= 2;
        x = x*x % MOD;
	}
    return y % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream cin("help.in");
	ofstream cout("help.out");
	int tt; tt = 1;
	while (tt--) {
		int n; cin >> n;
		vector<int> psa(2*n+2, 0);
		// see n <= 1e5 immediatrly means counting inclusion
		// pretty much the only linear solution with 2^n and n <= 1e5
		ll ans = 0;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			int x, y; cin >> x >> y;
			psa[x]++;
			psa[y+1]--;
			a[i] = x;
		}
		for (int i = 1; i <= 2*n; i++) psa[i] += psa[i-1];
		sort(a.begin(), a.end());
		for (auto &u : a) {
			ans += exp(2, n-psa[u]);
			ans %= MOD;
		}
		cout << ans << "\n";
	}
}