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
#define MAXN 250010

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<pi> vi;
const int MM = 3e4+4;
int w[MM], v[MM], dp[51]; set<pi, greater<pi>> card[51];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int B, N, D; cin >> B >> N >> D;
    for (int i = 1; i <= N; i++){
        cin >> w[i] >> v[i];
        card[w[i]].insert({v[i], i});
    }
    for (int i = 1; i <= D; i++){
        int a, b, x, y; cin >> a >> b >> x >> y;
        card[w[a]].erase({v[a], a}); w[a] = b;
        card[w[a]].insert({v[a], a});
        MEM(dp, 0);
        for (int j = 1; j <= B; j++){
            int cnt = 0;
            for (auto it = card[j].begin(); it != card[j].end() && cnt < B/j; it++){
                if (it->second >= x && it->second <=y){
                    cnt++;
                    for (int k = B; k >=j; k--){
                        dp[k] = max(dp[k], dp[k-j] + it->first);
                    }
                }
            }
        }
        cout << dp[B] << "\n";
    }

}