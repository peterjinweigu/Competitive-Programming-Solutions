// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: lamps
LANG: C++14          
*/

set<string> all;
string cmp;

bool check(string &tmp) {
    for (int i = 0; i < cmp.size(); i++) {
        if (cmp[i] == '2') continue;
        else {
            if (cmp[i] != tmp[i]) return false;
        }
    }
    return true;
}

char sw(char c) {
    if (c == '0') return '1';
    else return '0';
}

void solve(string &cur, int cnt) {
    if (cnt == 0) {
        if (check(cur)) all.insert(cur);
        return;
    }
    int n = cur.size();
    for (int i = 0; i < n; i++) cur[i] = sw(cur[i]);
    solve(cur, cnt-1);
    for (int i = 0; i < n; i++) cur[i] = sw(cur[i]);
    for (int i = 0; i < n; i+=2) cur[i] = sw(cur[i]);
    solve(cur, cnt-1);
    for (int i = 0; i < n; i+=2) cur[i] = sw(cur[i]);
    for (int i = 1; i < n; i+=2) cur[i] = sw(cur[i]);
    solve(cur, cnt-1);
    for (int i = 1; i < n; i+=2) cur[i] = sw(cur[i]);
    for (int i = 0; i < n; i+=3) cur[i] = sw(cur[i]);
    solve(cur, cnt-1);
    for (int i = 0; i < n; i+=3) cur[i] = sw(cur[i]);
}

int main() {
	ofstream cout ("lamps.out");
    ifstream cin ("lamps.in");
    int n; cin >> n;
	int c; cin >> c;
    string temp;
    for (int i = 0; i < n; i++) temp += "1", cmp += "2";
    int x; cin >> x;
    while (x != -1) {
        cmp[x-1] = '1';
        cin >> x;
    }
    cin >> x;
    while (x != -1) {
        cmp[x-1] = '0';
        cin >> x;
    }
    solve(temp, min(c, 4));
    if (all.size() == 0) cout << "IMPOSSIBLE" << "\n";
    else {
        for (auto j : all) cout << j << "\n";
    }
}

