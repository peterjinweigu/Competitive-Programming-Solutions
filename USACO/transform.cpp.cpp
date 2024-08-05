// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
typedef long long ll;

/*
ID: petergu1
TASK: transform
LANG: C++14          
*/

// 90 rotate n-i col, row = prev col
// 180 rotate, reverse everyting
// 270 rotate, 90 rotate and then 180

void r90(vector<string> &ret, int n) {
	vector<string> temp(n);
	for (int i = 0; i < n; i++) temp[i] = ret[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[j][n-i-1] = ret[i][j];
		}
	}
	for (int i = 0; i < n; i++) ret[i] = temp[i];
}

void flip(vector<string> &ret, int n) {
	vector<string> temp(n);
	for (int i = 0; i < n; i++) temp[i] = ret[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][n-j-1] = ret[i][j];
		}
	}
	for (int i = 0; i < n; i++) ret[i] = temp[i];
}

bool check(vector<string> &a, vector<string> &b, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != b[i][j]) return false;
		}
	}
	return true;
}

 
int main() {
	ofstream cout ("transform.out");
    ifstream cin ("transform.in");
	int n; cin >> n;
	vector<string> a(n);
	vector<string> b(n);
	vector<string> c(n);
	for (int i = 0; i < n; i++) {cin >> a[i]; c[i] = a[i];}
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 1; i <= 3; i++) {
		r90(c, n);
		if (check(b, c, n)) {
			cout << i << "\n";
			return 0;
		}
	}
	for (int i = 0; i < n; i++) c[i] = a[i];
	flip(c, n);
	if (check(b, c, n)) {
		cout << "4" << "\n";
		return 0;
	}
	for (int i = 1; i <= 3; i++) {
		r90(c, n);
		if (check(b, c, n)) {
			cout << 5 << "\n";
			return 0;
		}
	}
	if (check(a, b, n)) cout << 6 << "\n";
	else cout << 7 << "\n";
}