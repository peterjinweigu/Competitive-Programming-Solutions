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
#define mod 1000000007
#define MAXN 500100

struct path{
    int node, cost;
};

struct edge{
    int here, to, cost;
};

struct compare{
    bool operator()(path const&a, path const&b){
        return a.cost > b.cost;
    }
};

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
vector <path> adj[MAXN], opAdj[MAXN];
vector <edge> extra;
ll dist[MAXN], dist2[MAXN];
priority_queue<path, vector<path>, compare> q;
bool v[MAXN];


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= M; i++){
        int a, b, l; cin >> a >> b >> l;
        adj[a].PB(path{b, l});
        opAdj[b].PB(path{a, l});
    }
    int d; cin >> d;
    for (int i = 0; i < d; i++){
        int a, b, l; cin >> a >> b >> l;
        extra.PB(edge{a, b, l});
    }
    for (int i = 1; i <= N; i++)dist[i] = 1e13;
    MEM(v, false);
    dist[1] = 0;
    q.push(path{1, 0});
    while (q.size() > 0){
        auto cur = q.top().node; q.pop();
        if (v[cur]) continue;
        v[cur] = true;
        for (path u : adj[cur]){
            if (dist[cur] + u.cost < dist[u.node]){
                dist[u.node] = dist[cur] + u.cost;
                q.push(path{u.node, dist[u.node]});
            }
        }
    }
    for (int i = 1; i <= N; i++)dist2[i] = 1e13;
    MEM(v, false);
    dist2[N] = 0;
    q.push(path{N, 0});
    while (q.size() > 0){
        auto cur = q.top().node; q.pop();
        if (v[cur]) continue;
        v[cur] = true;
        for (path u : opAdj[cur]){
            if (dist2[cur] + u.cost < dist2[u.node]){
                dist2[u.node] = dist2[cur] + u.cost;
                q.push(path{u.node, dist2[u.node]});
            }
        }
    }
    ll ans = dist[N];
    for (edge j : extra){
        ans = min(dist[j.here] + dist2[j.to] + j.cost, ans);
    }
    if (ans == 1e13) cout << -1 << "\n";
    else cout << ans << "\n";
}