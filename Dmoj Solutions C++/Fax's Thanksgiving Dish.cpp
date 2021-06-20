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
#define MAXN 300100

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<ll> vi;
bool in[MAXN], v[MAXN];
ll n, m, a[MAXN], dist[MAXN];
vi adj[MAXN];

void dfs(ll cur){
    for (ll node : adj[cur]){
        if (!v[node]){
            v[node] = true;
            dist[node] = dist[cur] + a[node];
            dfs(node);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; MEM(dist, 0), MEM(in, false), MEM(v, false);
    for (int i = 0, x, y; i < m; i++){
        cin >> x >> y; in[x] = true;
        for (int i = 0, z; i < y; i++){
            cin >> z; adj[x].push_back(z);
        }
    }
    for (int i = 1; i <= n; i++)cin >> a[i];
    dist[1] = a[1];
    v[1] = true;
    dfs(1);
    ll best = 1e18;
    for (int i = 1; i <= n; i++){
        if (!in[i] && v[i]) best = min(best, dist[i]);
    }
    cout << best << "\n";

}