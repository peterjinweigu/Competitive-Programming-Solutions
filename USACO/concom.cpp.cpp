// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: concom
LANG: C++14          
*/

vector<pair<int, int>> adj[110];
int val[110];
int vis[110];

void dfs(int u) {
    vis[u] = true;
    for (auto j : adj[u]) {
        val[j.first] += j.second;
        if (val[j.first] > 50 && !vis[j.first]) dfs(j.first);
    }
}


int main() {
	ofstream cout ("concom.out");
    ifstream cin ("concom.in"); 
    
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<pair<int, int>> ans;

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) val[j] = 0, vis[j] = false;
        dfs(i);
        for (int j = 1; j <= 100; j++) {
            if (val[j] > 50 && j != i) ans.push_back({i, j});
        }
    }

    for (auto j : ans) {
        cout << j.first << " " << j.second << "\n";
    }

}

