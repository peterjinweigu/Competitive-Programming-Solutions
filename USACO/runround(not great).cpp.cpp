// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: runround
LANG: C++14          
*/

ll ans;

// bro no way straight brute force works :(

bool solve(vector<bool> &vis, int idx, string cur, int cyc) {
	bool pos = true;
	for (auto j : vis) if (!j) pos = j;
	if (pos && cyc) {
		ans = stoi(cur);
		return true;
	} else if (pos) {
		cyc = 1;
		vis[0] = false;
	}
	int tmp = (int)(cur[idx] - '0');
	int nxt = (idx + tmp) % cur.size();
	if (!vis[nxt]) {
		vis[nxt] = true;
		return solve(vis, nxt, cur, cyc);
	} else return false;
}


int main() {
	ofstream cout ("runround.out");
    ifstream cin ("runround.in");
    ll x; cin >> x;
	string m;

	ans = 0;
	set<char> s;
	
	while (!ans) {
		s.clear();
		x++;
		m = to_string(x);
		vector<bool> vis(m.size());
		for (int i = 0; i < m.size(); i++) vis[i] = false;
		vis[0] = true;

		bool sendhelp = true;
		for (auto j : m) {
			if (s.find(j) != s.end()) sendhelp = false;
			s.insert(j);
		}
		if (!sendhelp) continue;
		solve(vis, 0, m, 0);
	}

	cout << ans << "\n";
}

