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
typedef pair<ll, ll> pi;
typedef vector<pi> vi;
vi adj[MAXN];
vector<ll> rad;
ll dist[MAXN], idx, rr;

void dfs(ll cur, ll last){
    for (pi node : adj[cur]){
        if (node.first != last){
            dist[node.first] = dist[cur] + node.second;
            if (dist[node.first] > dist[idx]) idx = node.first;
            dfs(node.first, cur);
        }
    }
}

void dfs2(ll cur, ll last, ll len){
    for (pi node : adj[cur]){
        if (node.first != last){
            rr = min(rr, max(dist[node.first], len+node.second));
            dfs2(node.first, cur, len+node.second);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M, Q; cin >> N >> M >> Q;
    for (int i = 0; i < M; i++){
        ll a, b, t; cin >> a >> b >> t;
        adj[a].PB(MP(b, t));
        adj[b].PB(MP(a, t));
    }
    MEM(dist, -1);
    ll ans = -1;
    for (int i = 1; i <= N; i++){
        if (dist[i] == -1){
            idx = N+1;
            rr = 1e12;
            dist[i] = 0;
            dfs(i, i);
            dist[idx] = 0;
            dfs(idx, idx);
            if (Q == 1) ans += dist[idx] + 1;
            dfs2(idx, idx, 0);
            if (rr == 1e12) rr = 0;
            if (Q == 2){
                if (ans == rr) ans = rr+1;
                else ans = max(ans, rr);
            }
        }
    }
    cout << ans << "\n";
}