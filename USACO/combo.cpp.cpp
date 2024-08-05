// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: combo
LANG: C++14          
*/

bool check(int a, int b, int x) {
	if (abs(a - b) <= 2) return true;
	else {
		if (min(a, b) + x - max(a, b) <= 2) return true;
	}
	return false;
}

int main() {
	ofstream cout ("combo.out");
    ifstream cin ("combo.in");
	int n; cin >> n;
	vector<int> a(3);
	vector<int> b(3);
	for (int i = 0; i < 3; i++) cin >> a[i];
	for (int i = 0; i < 3; i++) cin >> b[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (check(i, a[0], n) && check(j, a[1], n) && check(k, a[2], n)) ans++;
				else if (check(i, b[0], n) && check(j, b[1], n) && check(k, b[2], n)) ans++;
			}
		}
	}
	cout << ans << "\n";
}

	