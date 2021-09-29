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
typedef pair<ll, ll> pi;

struct event{
    ll val, left, pos;
};

struct compare{
    bool operator()(event const&a, event const&b){
        if (a.left == b.left) return a.pos > b.pos;
        else return a.left > b.left;
    }
};

ll a[MAXN], ans[MAXN], ed[MAXN];
vector<event> line;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= q; i++){
        ll v, l, r; cin >> v >> l >> r;
        line.PB({v, l, i});
        ed[i] = r;
    }
    sort(line.begin(), line.end(), compare());
    set<pi> sweep;
    for (int i = 1; i <= n; i++){
        while (line.size() > 0 && line.back().left == i){
            sweep.insert({line.back().val, line.back().pos});
            line.pop_back();
        }
        while (sweep.size() > 0 && (*sweep.rbegin()).first >= a[i]){
            pi temp = *sweep.rbegin();
            if (ed[temp.second] < i) ans[temp.second] = temp.first;
            else{
                sweep.insert({temp.first % a[i], temp.second});
            }
            sweep.erase(*sweep.rbegin());
        }
    }
    for (auto e: sweep){
        ans[e.second] = e.first;
    }
    for (int i = 1; i <= q; i++){
        cout << ans[i] << "\n";
    }
}
