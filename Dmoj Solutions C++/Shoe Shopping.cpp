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
typedef pair<int, int> pi;
typedef vector<int> vi;
double a[10010], dp[10010];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 10010; i++) dp[i] = (double)1e9;
    dp[0] = 0;
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector <double> v;
    for (int i = 0; i < n; i++){
        if (i+2 <= n) dp[i+2] = min(dp[i] + max(a[i], a[i+1]) + ((min(a[i], a[i+1]))/2), dp[i+2]);
        v.PB(a[i]), v.PB(a[i+1]), v.PB(a[i+2]);
        sort(v.begin(), v.end());
        if (i+3 <= n) dp[i+3] = min(dp[i] + max(a[i], max(a[i+1], a[i+2])) + v[1], dp[i+3]);
        v.clear();
        dp[i+1] = min(dp[i+1], dp[i] + a[i]);
    }
    cout << fixed << setprecision(1) << dp[n] << "\n";
}