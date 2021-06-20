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
ll dp[5010];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++){
        ll a, b, c; cin >> a >> b >> c;
        int temp = 1;
        while (temp <= a){
            if (temp * b > 5000) break;
            for (int j = 5000; j >= temp*b; j--){
                dp[j] = max(dp[j], dp[j-(temp*b)] + (temp*c));
            }
            a -= temp;
            temp *= 2;
        }
        if (a != 0){
            if (a * b <= 5000){
                for (int j = 5000; j >= a*b; j--){
                    dp[j] = max(dp[j], dp[j-(a*b)] + (a*c));
                }
            }
        }
    }
    ll ans = INF * -1;
    for (int i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        ans = max(dp[a] - b, ans);
    }
    cout << ans << "\n";

}