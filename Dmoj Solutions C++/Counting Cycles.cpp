#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
vector <int> adj[10];
bool v[10];
int ans;

void dfs(int cur, int top){
    v[cur] = true;
    for (int node : adj[cur]){
        if (node < top) continue;
        if (!v[node]) dfs(node, top);
        else if (node == top) ans += 1;
    }
    v[cur] = false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0, x; j < n; j++){
            cin >> x;
            if (x == 0) {continue; adj[i].push_back(j);}
        }
    }
    for(int i = 0; i < n; i++) dfs(i, i);
    cout << ans << "\n";
}
