#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 2021
#define MAXN 200010
using namespace std;

typedef long long ll;
vector<int> adj[MAXN];
int path[MAXN], dist[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, w, d; cin >> n >> w >> d;
    for (int i = 0; i <= n; i++) dist[i] = 1e6;
    for (int i = 0; i < w; i++){
        int a, b; cin >> a >> b;
        adj[b].PB(a);
    }
    dist[n] = 0;
    queue<int> q;
    q.push(n);
    while (q.size() > 0){
        int cur = q.front(); q.pop();
        for (auto i : adj[cur]){
            if (dist[i] > dist[cur] + 1){
                dist[i] = dist[cur] + 1;
                q.push(i);
            }
        }
    }
    multiset<pair<int, int>> m;
    for (int i = 0; i < n; i++){
        cin >> path[i];
        m.insert({dist[path[i]] + i, i});
    }
    while (d--){
        int x, y; cin >> x >> y; x--; y--;
        m.erase({dist[path[x]] + x, x});
        m.erase({dist[path[y]]+ y, y});
        swap(path[x], path[y]);
        m.insert({dist[path[x]] + x, x});
        m.insert({dist[path[y]]+ y, y});
        cout << (*m.begin()).first << "\n";
    }
}
