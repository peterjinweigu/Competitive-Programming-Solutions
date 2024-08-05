// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: pprime
LANG: C++14          
*/

int a, b;
set<int> ans;

bool prime(int &num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void check(string &temp) {
	int num = stoi(temp);
	if (num >= a && num <= b && prime(num)) ans.insert(num);
}

void solve(int idx, string cur) {
	if (idx == cur.size()) {
		string temp = cur;
		reverse(cur.begin(), cur.end());
		temp += cur;
		check(temp);
	} else {
		for (int i = 0; i <= 9; i++) {
			solve(idx, cur + (char)(i + '0'));
		}
	}
}

void kill(int idx, string cur) {
	if (idx == cur.size()) {
		string temp = cur;
		reverse(cur.begin(), cur.end());
		for (int i = 0; i <= 9; i++) {
			string wtf = temp + (char)(i +'0') + cur;
			check(wtf);
		}
	} else {
		for (int i = 0; i <= 9; i++) {
			kill(idx, cur + (char)(i + '0'));
		}
	}
}

int main() {
	ofstream cout ("pprime.out");
    ifstream cin ("pprime.in");
	cin >> a >> b;

	for (int i = 1; i <= 4; i++) {
		solve(i, "");
		kill(i, "");
	}

	for (int i = 2; i <= 9; i++) {
		string temp = to_string(i);
		check(temp);
	}

	for (auto j : ans) cout << j << '\n';
}

	