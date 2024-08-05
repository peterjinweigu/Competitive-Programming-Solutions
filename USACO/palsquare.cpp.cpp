// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
typedef long long ll;

/*
ID: petergu1
TASK: palsquare
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
	ofstream cout ("palsquare.out");
    ifstream cin ("palsquare.in");
	int n; cin >> n;
	for (int j = 1; j<= 300; j++) {
		string cur = evil(j*j, n);
		string idx = evil(j, n);
		reverse(idx.begin(), idx.end());
		if (pal(cur)) {
			cout << idx << " " << cur << "\n";
		}
	}
}