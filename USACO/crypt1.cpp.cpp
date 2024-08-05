// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: crypt1
LANG: C++14          
*/

set<int> s;
int ans;

bool check(string &x) {
	string temp = "";
	for (int i = 0; i < 3; i++) temp += x[i];
	int a = (x[3] - '0');
	int b = (x[4] - '0');
	a *= 10;
	int c = stoi(temp);
	int n1 = a * c;
	int n2 = b * c;
	int n3 = n1 + n2;
	string fin = "";
	fin += to_string(n1/10);
	fin += to_string(n2);
	fin += to_string(n3);
	if (fin.size() > 10) return false;
	for (auto c : fin) {
		if (s.find((int)(c - '0')) == s.end()) return false;
	}
	return true;
}

void solve(string x, vector<int> &temp) {
	if (x.size() == 5) {
		if (check(x)) ans++;
	} else {
		for (int i = 0; i < temp.size(); i++) {
			solve(x + (char)(temp[i] + '0'), temp);
		}
	}
}

int main() {
	ofstream cout ("crypt1.out");
    ifstream cin ("crypt1.in");
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	ans = 0;
	solve("", a);
	cout << ans << "\n";
}

	