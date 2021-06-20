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

// :/
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
ll arr[MAXN]; int sz[MAXN], link[MAXN];

struct ed{
    ll x, y, len;
};

struct cmp{
    bool operator()(ed const&a, ed const&b){
        return a.len < b.len;
    }
};

int fd(int x) {
    while (x != link[x]) x = link[x];
    return x;
}

void unite(int a, int b) {
    a = fd(a);
    b = fd(b);
    if (sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
}

vector <ed> edge;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) link[i] = i;
    for (int i = 1; i <= n; i++) sz[i] = 1;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        if (fd(a) != fd(b)) unite(a, b);
    }
    for (int i = 1;i < n; i++)edge.PB(ed{i, i+1, abs(arr[i] - arr[i+1])});
    sort(edge.begin(), edge.end(), cmp());
    ll ans = 0;
    for (ed u : edge){
        if (fd(u.x) != fd(u.y)){
            unite(u.x, u.y);
            ans += u.len;
        }
    }
    cout << ans << "\n";
}