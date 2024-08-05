// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 500010
#define MOD 1000000007
typedef long long ll;
typedef pair<ll, ll> pi;

void chs(map<vector<int>, ll> &mp, vector<int> &v) {
	for (int mask = 1; mask < (1 << 5); mask++) {
		vector<int> temp;
		for (int j = 0; j < 5; j++) {
			if ((1 << j) & mask) temp.push_back(v[j]);
		}
		mp[temp]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt; tt = 1;
	ifstream cin("cowpatibility.in");
	ofstream cout("cowpatibility.out");
	while (tt--) {
		ll n; cin >> n;
		// pie was hard for me to see
		vector<int> a[n];
		for (int i = 0; i < n; i++) {
			a[i].resize(5);
			for (int j = 0; j < 5; j++) cin >> a[i][j];
			sort(a[i].begin(), a[i].end());
		}
		ll rem = 0;
		map<vector<int>, ll> mp;
		for (int i = 0; i < n; i++) chs(mp, a[i]);
		for (auto &u : mp) {
			if ((int)(u.first.size()) % 2 == 1) rem += ((u.second)*(u.second-1))/2;
			else rem -= ((u.second)*(u.second-1))/2;
		}
		cout << (n*(n-1))/2 - rem << "\n";
	}
}