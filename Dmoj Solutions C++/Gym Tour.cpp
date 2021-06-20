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
#define MAXN 100100

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<ll> vi;
bool v[MAXN], gym[MAXN], gymm[MAXN];
vi adj[MAXN];
ll edges, diam, dis[MAXN], small;

void dfs1(ll last, ll cur){
    for (ll node: adj[cur]){
        if (node != last){
            dis[node] = dis[cur] + 1;
            if (dis[node] > dis[diam] && gym[node]) diam = node;
            dfs1(cur, node);
            if (gym[node]) gym[cur] = true;
        }
    }
    if (!gym[cur] && !v[cur]){
        v[cur] = true;
        edges -= 1;
    }
}

void dfs2(ll last, ll cur){
    if (!v[cur]) small = min(small, dis[cur]);
    for (ll node : adj[cur]){
        if (node != last){
            dis[node] = dis[cur] + 1;
            dfs2(cur, node);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, k, f; cin >> n >> k >> f; edges = 0, diam = 0; MEM(gym, false), MEM(v, false), MEM(dis, 0);
    for (int i = 0, p; i < k; i++) {cin >> p; gym[p] = true;}
    for (int i = 0, a, b; i < n-1; i++){cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);}
    edges = n-1;
    dfs1(-1, 1);
    ll best = edges*2-dis[diam];
    small = 1e9;
    MEM(dis, 0);
    dfs2(-1, f);
    cout << min(best, edges + dis[1] - (dis[1] - small)) << "\n";


}