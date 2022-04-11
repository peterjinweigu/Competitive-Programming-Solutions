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
#define MAXN 1001000
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
ll a[MAXN], b[MAXN], psa[MAXN];
vector<pair<ll, ll>> bagel;

int main(){
    ll n, c; cin >> n >> c;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a[x]++;
    }
    for (ll i = 0; i < c; i++){
        if (a[i] > 0) bagel.PB({i, a[i]});
    }
    for (ll i = 0; i < c; i++){
        psa[i] = a[i];
        if (i > 0) psa[i] += psa[i-1];
    }
    for (ll i = 0; i < c; i++){
        if (c % 2 == 0) b[i] = a[i] * psa[min(c-1, i + c/2 - 1)];
        else b[i] = a[i] * psa[min(c-1, i + c/2)];
        if (i > 0) b[i] += b[i-1];
    }
    sort(bagel.begin(), bagel.end());
    ll ans = 0;
    for (pair<ll, ll> e : bagel){
        if (e.first + c/2 >= c) break;
        if (c % 2 == 0){
            ll rsum = (b[e.first + c/2 - 1] - b[e.first]);
            ll lsum = psa[e.first + c/2] * (psa[e.first + c/2 - 1] - psa[e.first]);
            ans += e.second*(rsum - lsum);
        } else {
            ll rsum = (b[e.first + c/2] - b[e.first]);
            ll lsum = psa[e.first + c/2] * (psa[e.first + c/2] - psa[e.first]);
            ans += e.second*(rsum - lsum);
        }
    }
    cout << ans << "\n";
}

