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

ll bit[MAXN];


ll sum(int k) {
    ll s = 0;
    while (k >= 1) {
        s += bit[k];
        k -= k&-k;
    }
    return s;
}

void add(int k, ll x) {
    while (k <= MAXN) {
        bit[k] += x;
        k += k&-k;
    }
}

struct tree{
    int pos, cost;
};

bool cmp(tree a, tree b){
    return a.cost > b.cost;
}

struct query{
    int l, r, q, idx;
};

bool cmp2(query a, query b){
    return a.q > b.q;
}

vector <tree> trees;
vector <query> queries;
ll ans[MAXN];


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        int m; cin >> m;
        trees.PB(tree{i, m});
    }
    sort(trees.begin(), trees.end(), cmp);
    int q; cin >> q;
    for (int i = 0; i < q; i++){
        int a, b, c; cin >> a >> b >> c;
        queries.PB(query{a, b, c, i});
    }
    sort(queries.begin(), queries.end(), cmp2);
    int cur = 0;
    for (query i : queries){
        while (cur < n && i.q <= trees[cur].cost){
            add(trees[cur].pos, trees[cur].cost);
            cur++;
        }
        ans[i.idx] = sum(i.r+1) - sum(i.l);
    }
    for (int i = 0; i < q; i++){
        cout << ans[i] << "\n";
    }
}