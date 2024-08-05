// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: wormhole
LANG: C++14          
*/

vector<pair<int, int>> v;
vector<int> nxt;
int n;
int ans;

void check(vector<int> &a) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		int j = a[i];
		int u = 1;
		while (true) {
			if (nxt[j] == -1) {
				u = 0;
				break;
			}
			j = nxt[j];
			if (j == i) break;
			j = a[j];
		}
		ret = max(ret, u);
	}
	ans += ret;
}

void solve(vector<int> a, int cnt, int idx) {
	if (cnt == n) {
		check(a);
		return;
	}
	if (a[idx] != -1) {
		solve(a, cnt, idx+1);
		return;
	}
	for (int j = idx+1; j < n; j++){
		if (a[j] == -1) {
			a[idx] = j;
			a[j] = idx;
			solve(a, cnt+2, idx+1);
			a[j] = -1;
			a[idx] = -1;
		}
	}
} 

int main() {
	ofstream cout ("wormhole.out");
    ifstream cin ("wormhole.in");
	cin >> n;
	v.resize(n);
	nxt.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) nxt[i] = -1;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (v[i].second == v[j].second) {
				nxt[i] = j;
				break;
			}
		}
	}
	// ok this may be the dumbest problem so far
	vector<int> temp(n);
	for (int i = 0; i < n; i++) temp[i] = -1;
	ans = 0;
	solve(temp, 0, 0);
	cout << ans << "\n";
}

	