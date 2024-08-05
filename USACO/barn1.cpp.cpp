// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: barn1
LANG: C++14          
*/

int main() {
	ofstream cout ("barn1.out");
    ifstream cin ("barn1.in");
	int m, s, c; cin >> m >> s >> c;
	vector<int> v(c);
	for (int i = 0; i < c; i++) cin >> v[i];
	sort(v.begin(), v.end());
	vector<int> gap;
	for (int i = 1; i < c; i++) gap.push_back(v[i] - v[i-1] - 1);
	sort(gap.begin(), gap.end());
	int ans = c;
	for (int i = 0; i < min(c-1, c-m); i++) {
		ans += gap[i];
	}
	cout << ans << "\n";
}