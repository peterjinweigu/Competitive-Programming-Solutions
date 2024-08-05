// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: prefix
LANG: C++14          
*/

// ok im going to assume best case, might need to hash for O(n)

bool check(string &s, int idx, int len, string &temp) {
    for (int i = idx; i < idx + len; i++) {
        if (s[i] != temp[i - idx]) return false;
    }
    return true;
}


int main() {
	ofstream cout ("prefix.out");
    ifstream cin ("prefix.in"); 
    
    vector<string> v;
    string s; cin >> s;
    while (s != ".") {
        v.push_back(s);
        cin >> s;
    }
    s = "";
    string x;
    while (getline(cin, x)) {
        s += x;
    }
    int n = s.size();
    vector<int> dp(n, -1);
    dp[0] = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] != -1) {
            for (string j : v) {
                int m = j.size();
                if (i + m <= n && dp[i] + m > dp[i + m]) {
                    if (check(s, i, m, j)) dp[i + m] = dp[i] + m;
                    ans = max(ans, dp[i + m]);
                }
            }
        }
    }
    cout << ans << "\n";
}

