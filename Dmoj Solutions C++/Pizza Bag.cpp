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
ll a[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {cin >> a[i]; a[i+n] = a[i];}
    for (int i = 1; i <= n*2; i++) a[i] += a[i-1];
    ll ans = 0;
    deque<pair<ll, int>> d;
    d.push_front({0, 0});
    for (int i = 1; i <= n*2; i++){
        while (!d.empty() && i - d.front().second > k) d.pop_front();
        ll cur = a[i];
        ans = max(ans, cur - d.front().first);
        while (!d.empty() && d.back().first >= cur){
            d.pop_back();
        }
        d.push_back({cur, i});
    }
    cout << ans << "\n";
    return 0;
}
