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
#define MAXN 200010
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
vector<int> adj[MAXN];
string s;
int val[MAXN];
int dp[MAXN][2][2];
const int mx = 0x3f3f3f3f;

void dfs(int u, int par){
    dp[u][1][0] = 0; dp[u][1][1] = val[u];
    if (s[u-1] == 'Y'){
        dp[u][0][0] = 0;
        dp[u][0][1] = val[u];
    }
    for (int k : adj[u]){
        if (par == k) continue;
        dfs(k, u);
        dp[u][0][0] = min(mx, min(dp[u][0][0] + min(dp[k][0][0], dp[k][0][1]), dp[u][1][0] + dp[k][0][1]));
        dp[u][0][1] = min(mx, min(dp[u][0][1] + min(dp[k][1][1], min(dp[k][0][0], min(dp[k][1][0], dp[k][0][1]))), dp[u][1][1] + dp[k][0][1]));
        dp[u][1][0] = min(mx, dp[u][1][0] + dp[k][0][0]);
        dp[u][1][1] = min(mx, dp[u][1][1] + min(dp[k][1][1], min(dp[k][0][0], min(dp[k][0][1], dp[k][1][0]))));
    }
}

//dp[i][2][2] // dp[node][0 = influenced, 1 = not influenced][0 = not influencing, 1 = influencing]

// for every child subtree:
// dp[u][0][0] = min(dp[u][0][0] + min(dp[k][0][0], dp[k][0][1]), dp[u][1][0] + dp[k][0][1]));
// dp[u][0][1] = min(dp[u][0][1] + min(dp[k][1][1], min(dp[k][0][0], min(dp[k][1][0], dp[k][0][1]))), dp[u][1][1] + dp[k][0][1]));
// dp[u][1][0] = dp[u][1][0] + dp[k][0][0]);
// dp[u][1][1] = dp[u][1][1] + min(dp[k][1][1], min(dp[k][0][0], min(dp[k][0][1], dp[k][1][0]))));

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    cin >> s;
    for (int i = 1; i <= n; i++) cin >> val[i];
    MEM(dp, 0x3f);
    dfs(1, 1);
    cout << min(dp[1][0][0], dp[1][0][1]) << "\n";
}
