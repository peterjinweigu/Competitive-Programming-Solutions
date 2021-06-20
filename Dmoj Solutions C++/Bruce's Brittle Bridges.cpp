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
#define MAXN 200010
#define mod 1000000007

// :/
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
ll val[MAXN], link[MAXN], sz[MAXN];
vector<pair<ll, ll>> edge;
vector<ll> adj[MAXN];

ll fd(ll x) {
    while (x != link[x]) x = link[x];
    return x;
}

void unite(ll a, ll b) {
    a = fd(a);
    b = fd(b);
    if (sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
    val[a] += val[b];
}

void unite2(ll a, ll b) {
    a = fd(a);
    b = fd(b);
    if (sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) link[i] = i;
    for (int i = 1; i <= n; i++) sz[i] = 1;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 0; i < n-1; i++){
        ll a, b, t; cin >> a >> b >> t;
        if (t >= 2) unite(a, b);
        else edge.PB(MP(a, b));
    }
    for (auto i : edge){
        adj[fd(i.first)].PB(i.second);
        adj[fd(i.second)].PB(i.first);
    }
    queue <ll> q;
    ll ans = 0;
    q.push(fd(1));
    while (q.size() > 0){
        ll cur = q.front();
        ans = max(ans, val[cur]);
        q.pop();
        for (auto j : adj[cur]){
            ll k = fd(j);
            if (k != fd(cur)){
                val[k] += val[cur];
                q.push(k);
                unite2(cur, j);
            }
        }
    }
    cout << ans << "\n";
}