#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>

struct path{
    int t, dis, dam;
};
struct compare{
    bool operator()(path const&a, path const&b){
        return a.dis > b.dis;
    }
};

using namespace std;
typedef long long bigNum;
typedef pair<int, int> pi;
int s, n, e, a, b, c, d, cur, ww;
priority_queue<path, vector<path>, compare> q;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    cin >> n >> e;
    int dist[s+1][n];
    vector <path> adj[n];
    for (int i = 0; i < e; i++){
        cin >> a >> b >> c >> d;
        if (d == 0){
            d = 0;
        }else{
            d = c;
        }
        adj[a].push_back(path{b,c,d});
        adj[b].push_back(path{a,c,d});
    }
    q.push(path{0,0,0});
    memset(dist, 0x3f3f3f, sizeof dist);
    for (int j = 0; j <= s; j++){
        dist[j][0] = 0;
    }
    while (q.size() > 0){
        cur = q.top().t;
        ww = q.top().dam;
        q.pop();
        for (int j = 0; j < adj[cur].size(); j++){
            int sec = adj[cur][j].dam;
            int w = adj[cur][j].dis;
            int node = adj[cur][j].t;
            if (sec + ww <= s){
                if (dist[sec+ww][node] > dist[ww][cur] + w){
                    dist[sec+ww][node] = dist[ww][cur] + w;
                    q.push(path{node,  dist[ww][cur] + w, sec+ww});
                }
            }
        }
    }


    int minn = 0x3f3f3f;
    for (int j = 0; j <= s; j++){
        if (dist[j][n-1] < minn){
            minn = dist[j][n-1];
        }
    }
    if (minn < 0x3f3f3f){
        cout << minn << endl;
    }else{
        cout << -1 << endl;
    }
}