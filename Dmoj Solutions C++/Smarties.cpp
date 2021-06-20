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
#define MAXN 1000010
#define mod 1000000007

// :/
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
ll v[MAXN], a[100100];


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll lo = 0, hi = 0, num = 1, ans = 0;
    v[a[0]] = 1;
    while (hi < n){
        if (num >= k){
            ans += n-hi;
            v[a[lo]] -= 1;
            if (v[a[lo]] == 0) num -= 1;
            lo++;
        }
        else{
            hi++;
            if (hi == n) break;
            v[a[hi]] += 1;
            if (v[a[hi]] == 1) num += 1;
        }
    }
    cout << ans << "\n";
}