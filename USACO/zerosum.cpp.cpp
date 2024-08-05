// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: zerosum
LANG: C++14          
*/

// just generate all the possible cases
// honestly its just a bit annoying to handle the cases
// but otherwise handle the cases and print ans

set<string> ans;

bool check(vector<string> &cur) {
    int last = stoi(cur[0]);
    for (int i = 1; i < cur.size(); i+=2) {
        int j = stoi(cur[i+1]);
        if (cur[i] == "+") last += j;
        else last -= j;
    }
    return (last == 0);
}

void solve(string &cur, int idx, vector<string> &cnt, string fin) {
    if (idx == cur.size()) {
        if (check(cnt)) {
            ans.insert(fin);
        }
        return;
    }
    string tmp = "";
    tmp += cur[idx];
    cnt.push_back("+");
    cnt.push_back(tmp);
    solve(cur, idx+1, cnt, fin + "+" + cur[idx]);
    cnt.pop_back();
    cnt.pop_back();
    cnt.push_back("-");
    cnt.push_back(tmp);
    solve(cur, idx+1, cnt, fin + "-" + cur[idx]);
    cnt.pop_back();
    cnt.pop_back();
    string nxt = cnt[cnt.size() - 1];
    cnt.pop_back();
    cnt.push_back(nxt + cur[idx]);
    solve(cur, idx+1, cnt, fin + " " + cur[idx]);
    cnt.pop_back();
    cnt.push_back(nxt);
}

int main() {
	ofstream cout ("zerosum.out");
    ifstream cin ("zerosum.in"); 
    
    int n; cin >> n;

    string s = "";
    for (int i = 1; i <= n; i++) s += (char)(i + '0');
    vector<string> cnt;
    cnt.push_back("1");
    solve(s, 1, cnt, "1");
    for (auto j : ans) cout << j << "\n";
}

