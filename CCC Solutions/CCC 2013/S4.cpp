#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long bigNum;
typedef pair<int, int> pi;
bigNum n, m, a, b, p, q, cur;
vector <int> adj[1000001];
queue <int> qu;

int bfs(int pp, int qq){
    int v[n+1];
    memset(v, 0, sizeof v);
    qu.push(pp);
    while (qu.size() > 0){
        cur = qu.front();
        qu.pop();

        for (int j = 0; j < adj[cur].size(); j++){
            int pt = adj[cur][j];
            if (pt == qq){
                return true;
            }
            if (v[pt] == 0){
                v[pt] = 1;
                qu.push(pt);
            }
        }
    }
    return false;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
    }
    cin >> p >> q;
    if (bfs(p, q)){
        cout << "yes" << endl;
    }
    else if (bfs(q,p)){
        cout << "no" << endl;
    }
    else{
        cout << "unknown" << endl;
    }
}
