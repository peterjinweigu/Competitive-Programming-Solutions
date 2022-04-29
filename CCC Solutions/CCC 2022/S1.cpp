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
int dp[MAXN];

int main(){
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i <= n/4; i++){
        if ((n - i*4) % 5 == 0) ans++;
    }
    cout << ans << "\n";
}
