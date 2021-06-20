#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MAXN 100100
#define mod 1000000007

// Stop stalking me
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<int> vi;

struct dsu{
    ll link[MAXN], sz[MAXN];
    void init(int n) {
        for (int i = 1; i <= n; i++) link[i]=i, sz[i]=1;
    }
    int find(int x) {
        while (x != link[x]) x = link[x];
        return x;
    }
    bool unite(int a, int b) {
        ll e = find(a), f = find(b);
        if (e==f) return 0;
        if (sz[e] < sz[f]) swap(e, f);
        sz[e] += sz[f];
        link[f] = e;
        return 1;
    }
}row, col;


struct edge{
    ll from, to, len; bool type;
};

bool cmp(edge a, edge b){
    return a.len < b.len;
}

vector <edge> edges;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M, P, Q; cin >> N >> M >> P >> Q;
    ll total = 0;
    row.init(M);
    col.init(N);
    for (int j = 0; j < P; j++){
        ll a, b, c; cin >> a >> b >> c;
        total += c*N;
        edges.push_back(edge{a, b, c, false});
    }
    for (int j = 0; j < Q; j++){
        ll a, b, c; cin >> a >> b >> c;
        total += c*M;
        edges.push_back(edge{a, b, c, true});
    }
    ll ans = 0;
    sort(edges.begin(), edges.end(), cmp);
    for (edge cur : edges){
        if (!cur.type){
            if (row.find(cur.from) != row.find(cur.to)){
                row.unite(cur.from, cur.to);
                ans += cur.len * N;
                if (M != 0)M--;
            }
        } else{
            if (col.find(cur.from) != col.find(cur.to)){
                col.unite(cur.from, cur.to);
                ans += cur.len * M;
                if (N != 0)N--;
            }
        }
    }
    cout << total - ans << "\n";
}