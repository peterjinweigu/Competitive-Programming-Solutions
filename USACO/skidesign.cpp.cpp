// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: skidesign
LANG: C++14          
*/

int sqr(int x){
	return x*x;
}


int main() {
	ofstream cout ("skidesign.out");
    ifstream cin ("skidesign.in");
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int cnt = 0;
	int ans = 1e9;
	for (int i = 0; i <= 100; i++) {
		cnt = 0;
		for (int j = 0; j < n; j++) {
			if (a[j] < i) cnt += sqr(i - a[j]);
			else if (a[j] - 17 > i) cnt += sqr(a[j] - 17 - i);
		}
		ans = min(ans, cnt);
	}
	cout << ans << "\n";
}

	