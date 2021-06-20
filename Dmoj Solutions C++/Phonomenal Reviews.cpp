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
typedef vector<int> vi;
bool pho[MAXN], v[MAXN];
int n, m, diam, len, edges, dist[MAXN];
vi adj[MAXN];

void dfs1(int last, int cur){
    for (int node: adj[cur]){
        if (node != last){
            dist[node] = dist[cur] + 1;
            if (dist[node] > dist[diam] && pho[node]) diam = node;
            dfs1(cur, node);
            if (pho[node]) pho[cur] = true;
        }
    }
    if (!pho[cur] && !v[cur]){
        v[cur] = true;
        edges -= 1;
    }
}

void dfs2(int last, int cur){
    if (pho[cur]) len = max(len, dist[cur]);
    for (int node : adj[cur]){
        if (node != last && !v[cur]){
            dist[node] = dist[cur] + 1;
            dfs2(cur, node);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; MEM(pho, false), MEM(v, false), MEM(dist, 0); edges = n-1;
    int start = 0;
    for (int i = 0, p; i < m; i++){cin >> p; pho[p] = true; start = p;}
    for (int i = 0, a, b; i < n-1; i++){cin >> a >> b; adj[a].push_back(b), adj[b].push_back(a);}
    diam = start;
    dfs1(-1, start);
    len = 0;
    MEM(dist, 0);
    dfs2(-1, diam);
    cout << edges*2-len << "\n";
    return 0;
}