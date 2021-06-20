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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
vi allG;
vector <pi> adj[2010];
ll dist[2010];
priority_queue<pi, vector <pi> , greater<pi> > pq;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 2010; i++) dist[i] = 1e16;
    int T, N, M, G; cin >> T >> N >> M >> G;
    for (int i = 0; i < G; i++){int p; cin >> p; allG.PB(p);}
    for (int i = 0; i < M; i++){
        int a, b, l; cin >> a >> b >> l;
        adj[a].PB(MP(b, l));
    }
    dist[0] = 0;
    pq.push(MP(0, 0));
    while (pq.size() > 0){
        int cur = pq.top().second; pq.pop();
        for (auto u : adj[cur]){
            int to = u.first, len = u.second;
            if (dist[to] > dist[cur] + len){
                dist[to] = dist[cur] + len;
                pq.push(MP(dist[to], to));
            }
        }
    }
    int total = 0;
    for (auto j : allG){
        if (dist[j] <= T) total ++;
    }
    cout << total << "\n";
}