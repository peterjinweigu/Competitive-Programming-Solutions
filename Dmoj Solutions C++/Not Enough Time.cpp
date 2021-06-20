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
#define MAXN 10010
#define mod 1000000007

// :/
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
int dp[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, t; cin >> n >> t;
    for (int i = 0; i <= t; i++) dp[i] = -1;
    dp[0] = 0;
    while (n--){
        int p, v, a, b, c, d; cin >> p >> v >> a >> b >> c >> d;
        for (int i = t; i >= 0; i--){
            if (dp[i] != -1 && i+p <= t) dp[i+p] = max(dp[i+p], dp[i] + v);
            if (dp[i] != -1 && i+a <= t) dp[i+a] = max(dp[i+a], dp[i] + b);
            if (dp[i] != -1 && i+c <= t) dp[i+c] = max(dp[i+c], dp[i] + d);
        }
    }
    int ans = 0;
    for (int i = 0; i <= t; i++) ans = max(ans, dp[i]);
    cout << ans << "\n";
}