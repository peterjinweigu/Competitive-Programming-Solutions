#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
priority_queue<pair<int, int> > q;
int c,r,d; int a,b,e; int cur; int maxt;
int main(){
    cin >> c >> r >> d;
    int dest[d];
    vector <pair<int,int>> adj[c+1];
    int dist[c+1];
    int v[c+1];
    for (int j = 0; j < c+1; j++){
        v[j] = false;
        dist[j] = 0;

    }
    for (int i = 0; i < r; i++){
        cin >> a; cin >> b; cin >> e;
        adj[a].push_back({b,e});
        adj[b].push_back({a,e});
        }
    for (int i = 0; i < d; i++){
        cin >> dest[i];
    }
    v[0] = true;
    dist[1] = 100001;
    q.push(make_pair(0,1));
    while (q.size() > 0){
        cur = q.top().second;
        v[cur] = true;
        q.pop();
        for (int i = 0; i < adj[cur].size(); i++){
            if (v[adj[cur][i].first] == false){
                q.push(make_pair(adj[cur][i].second, adj[cur][i].first));
                dist[adj[cur][i].first] = max(dist[adj[cur][i].first],min(dist[cur], adj[cur][i].second));
                }
            }
        }
    int small = 100001;
    for (int i = 0; i < d; i++){
        small = min(small, dist[dest[i]]);
    }
    cout << small << endl;
}