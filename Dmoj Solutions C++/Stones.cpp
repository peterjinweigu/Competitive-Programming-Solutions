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
typedef vector<pi> vi;
int a[101], dp[MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    MEM(dp, 0);
    for (int j = 0; j <= k; j++){
        for (int i = 0; i < n; i++){
            if (dp[j] == 0) dp[j+a[i]] = 1;
        }
    }
    if (dp[k] == 1) cout << "First" << "\n";
    else cout << "Second" << "\n";
}