// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;
#define MOD 9901

/*
ID: petergu1
TASK: fracdec
LANG: C++14          
*/


int main() {
	ofstream cout ("fracdec.out");
    ifstream cin ("fracdec.in"); 

    int n, d; cin >> n >> d;
    string pre = to_string(n/d);
    pre += '.';
    int rem = n % d;
    if (rem == 0) pre += '0';
    vector<int> vis(1e6, -1);
    vector<string> ans;
    int idx = -1;
    int cur = 0;

    while (rem != 0) {
        if (vis[rem] != -1) {
            idx = vis[rem];
            break;
        }
        vis[rem] = cur++;
        string end = "";
        rem*=10;
        while (rem < d) {
            end += '0';
            if (vis[rem] != -1) {
                idx = vis[rem];
                break;
            } 
            rem *= 10;
        }
        if (idx != -1) {
            ans.push_back(end);
            break;
        }
        ans.push_back(end + to_string(rem/d));
        rem = rem % d;
    }
    if (idx == -1) {
        for (auto j: ans) pre += j;
    } else {
        for (int i = 0; i < ans.size(); i++) {
            if (i == idx) pre += '(';
            pre += ans[i];
        }
        pre += ')';
    }
    for (int i = 0; i <= pre.size()/76; i++){
        for (int j = i*76; j < min((i+1)*76, (int)pre.size()); j++) cout << pre[j];
        cout << "\n";
    }
}

