// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: frac1
LANG: C++14          
*/

struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {	
		return a.first*b.second < b.first*a.second;
    }
};


int main() {
	ofstream cout ("frac1.out");
    ifstream cin ("frac1.in");

	int n; cin >> n;
	vector<pair<int, int>> v;
	v.push_back({0, 1});
	v.push_back({1, 1});
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if ((j == 1) || (__gcd(j, i) == 1)) v.push_back({j, i});
		}
	}
	sort(v.begin(), v.end(), cmp());

	for (auto j : v) cout << j.first << "/" << j.second << "\n";
}
