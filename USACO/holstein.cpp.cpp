// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: holstein
LANG: C++14          
*/

int ans;
int temp;
vector<int> v[15];
set<int> wow;

// no way brute force passes, im stupid
void solve(int cur, int cnt, int k, int n, vector<int> &my, int bagel) {
	if (wow.find(cur) != wow.end()) return;
	wow.insert(cur);
	if (bagel == n && cnt < ans) {
		ans = cnt;
		temp = cur;
	}
	if (bagel == n || cnt >= ans) return;
	for (int j = 0; j < k; j++) {
		int idx = (1 << j);
		if (!(idx & cur)) {
			int x = 0;
			for (int i = 0; i < n; i++) {
				my[i] -= v[j][i];
				if (my[i] <= 0) x++;
			}
			solve(idx ^ cur, cnt + 1, k, n, my, x);
			for (int i = 0; i < n; i++) my[i] += v[j][i];
		}
	}
}

int main() {
	ofstream cout ("holstein.out");
    ifstream cin ("holstein.in");
    
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int k; cin >> k;
	for (int i = 0; i < k; i++) {
		v[i].resize(n);
		for (int j = 0; j < n; j++) cin >> v[i][j];
	}
	ans = n+1;
	temp = 0;
	vector<int> my;
	my.resize(n);
	for (int i = 0; i < n; i++) my[i] = a[i];
	solve(0, 0, k, n, my, 0);
	vector<int> fin;
	fin.push_back(ans);
	for (int i = 0; i < k; i++) {
		int idx = (1 << i);
		if (idx & temp) fin.push_back(i+1);
	}
	for (int j = 0; j < fin.size() - 1; j++) cout << fin[j] << " ";
	cout << fin[fin.size() - 1] << "\n";
}

