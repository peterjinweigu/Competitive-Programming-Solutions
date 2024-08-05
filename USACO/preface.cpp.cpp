// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: preface
LANG: C++14          
*/

int num[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
vector<vector<int>> cost{{1, 0, 0, 0, 0, 0, 0}, {1, 1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0},
{1, 0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, 
{0, 0, 1, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 0}, {0, 0, 0, 0, 0, 1, 0}, 
{0, 0, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 0, 0, 1}};
char bagel[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

int main() {
	ofstream cout ("preface.out");
    ifstream cin ("preface.in"); 
    
    int n; cin >> n;
	vector<int> dp(n+1);
	vector<int> cnt[n+1];
	for (int i = 0; i <= n; i++) {
		cnt[i].resize(7);
		for (int j = 0; j < 7; j++) cnt[i][j] = 0;
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 13; j++) {
			if (i + num[j] <= n && !dp[i+num[j]]) {
				dp[i+num[j]] = 1;
				for (int k = 0; k < 7; k++) {
					cnt[i+num[j]][k] = cost[j][k] + cnt[i][k];
				}
			}
		}
	}
	vector<int> ans(7);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 7; j++) {
			ans[j] += cnt[i][j];
		}
	}
	for (int i = 0; i < 7; i++) {
		if (ans[i] != 0) cout << bagel[i] << " " << ans[i] << "\n";
	}
}

