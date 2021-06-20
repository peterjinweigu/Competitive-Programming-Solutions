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
#define MAXN 200100

struct path{
    int node, cost, level;
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
vector <path> adj[100100];
ll dist[100100];
priority_queue<path, vector<path>, compare> q;
bool v[100100];

bool check(int here, int to, ll total, int best){
    for (int i = 0; i < 100100; i++)dist[i] = 1e13;
    MEM(v, false);
    v[here] = 0;
    dist[here] = 0;
    q.push(path{here, 0, 0});
    while (q.size() > 0){
        auto cur = q.top().node; q.pop();
        if (v[cur]) continue;
        v[cur] = true;
        for (path u : adj[cur]){
            if (u.level > best) continue;
            if (dist[cur] + u.cost < dist[u.node]){
                dist[u.node] = dist[cur] + u.cost;
                q.push(path{u.node, dist[u.node], u.level});
            }
        }
    }
    if (dist[to] <= total) return true;
    else return false;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= M; i++){
        int a, b, l; cin >> a >> b >> l;
        adj[a].PB(path{b, l, i});
        adj[b].PB(path{a, l, i});
    }
    int A, B, C; cin >> A >> B >> C;
    int lo = 0, hi = M;
    while (lo <= hi){
        int mid = (lo+hi)/2;
        if (check(A, B, C, mid)) hi = mid-1;
        else lo = mid + 1;
    }
    if (lo <= M) cout << lo << "\n";
    else cout << -1 << "\n";
}