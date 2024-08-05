// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
typedef long long ll;

/*
ID: petergu1
TASK: dualpal
LANG: C++14          
*/

bool pal(string &a) {
	int n = a.size();
	for (int i = 0; i < n/2; i++) {
		if (a[i] != a[n-i-1]) return false;
	}
	return true;
}

string evil(int a, int b) {
	string temp;
	while (a > 0) {
		int k = (a % b);
		if (k > 9) temp += (char)(k-10 + 'A');
		else temp += (char)(k + '0');
		a /= b;
	}
	return temp;
}
 
int main() {
	ofstream cout ("dualpal.out");
    ifstream cin ("dualpal.in");
	int n, s; cin >> n >> s;
	for (int j = s+1; j <= 1e6; j++) {
		int cnt = 0;
		for (int i = 2; i <= 10; i++) {
			string idx = evil(j, i);
			if (pal(idx)) cnt++;
		}
		if (cnt >= 2) {
			n--;
			cout << j << "\n";
		}
		if (!n) break;
	}
}