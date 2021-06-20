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
#define MAXN 500100

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
vi adj[MAXN];
int ans;

void dfs(int cur, int last){
    int cnt = 0;
    for (int node : adj[cur]){
        if (node != last){
            cnt += 1;
            dfs(node, cur);
        }
    }
    ans += cnt;
    int idx = 1;
    int mut = 0;
    while (idx <= cnt){
        idx*=2;
        mut += 1;
    }
    ans += mut;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0, a, b; i < n-1; i++){
        cin >> a >> b;
        adj[a].PB(b), adj[b].PB(a);
    }
    dfs(1, 1);
    cout << ans << "\n";
}