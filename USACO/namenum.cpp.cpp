// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
typedef long long ll;

/*
ID: petergu1
TASK: namenum
LANG: C++14          
*/

set<string> names;
vector<string> ans;
string arr[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};

void check(string &s, int idx, string ret) {
	if (idx == s.size()) {
		if (names.find(ret) != names.end()) ans.push_back(ret);
		return;
	}
	int i = s[idx] - '0';
	for (int j = 0; j < 3; j++) {
		check(s, idx+1, ret + arr[i][j]);
	}
}

 
int main() {
	ifstream dic("dict.txt");
	string str;
	while (getline(dic, str)) {
		names.insert(str);
	}

	ofstream cout ("namenum.out");
    ifstream cin ("namenum.in");
	string num; cin >> num;
	check(num, 0, "");
	for (auto j : ans) cout << j << "\n";
	if (ans.size() == 0) cout << "NONE" << "\n";
}