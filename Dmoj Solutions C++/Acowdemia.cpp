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
#define MAXN 100010
#define mod 1000000007

// :/
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
ll a[MAXN];
ll n, k, l;

bool check (ll x){
    ll area = 0;
    for (int i = n-1; i >= n-x; i--){
        if (a[i] < x) area += x-a[i];
        if (a[i] + k < x) return false;
    }
    return area <= k*l;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> l;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    ll lo = 0, hi = n, ans = 0;
    while (lo <= hi){
        ll mid = (lo+hi)/2;
        if (check(mid)) {
            lo = mid+1;
            ans = mid;
        }else hi = mid-1;
    }
    cout << ans << "\n";
}