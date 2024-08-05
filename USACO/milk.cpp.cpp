// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: milk
LANG: C++14          
*/

int main() {
	ofstream cout ("milk.out");
    ifstream cin ("milk.in");
	int n, m; cin >> n >> m;
	vector<pair<int, int>> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (auto u : v) {
		if (n <= u.second) {
			ans += n*u.first;
			break;
		} else {
			ans += u.second*u.first;
			n -= u.second;
		}
	}
	cout << ans << "\n";
}