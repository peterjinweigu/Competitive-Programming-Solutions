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
#define MAXN 100100

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
int dp[1001][1001], a[1001], b[1001], best = 0;

int solve(int i, int j){
    if (dp[i][j] != -1){
        return dp[i][j];
    }
    else if (i == 0 || j == 0){
        return 0;
    }
    else if (a[i-1] == b[j-1]){
        dp[i][j] = 1 + solve(i-1, j-1);
        best = max(dp[i][j], best);
        return dp[i][j];
    } else{
        dp[i][j] = max(solve(i-1, j), solve(i, j-1));
        best = max(dp[i][j], best);
        return dp[i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 1001; i++){
        for (int j = 0; j < 1001; j++){
            dp[i][j] = -1;
        }
    }
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    solve(n, m);
    cout << best << endl;
}