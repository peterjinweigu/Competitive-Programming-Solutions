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
#define MAXN 200010
#define mod 1000000007

// :/
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
int p[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, a, b; cin >> n >> a >> b;
        for (int i = 0; i < a; i++) cin >> p[i];
        sort(p, p+a);
        priority_queue<pi> q; int ans = 0;
        if (p[0] > 1) q.push(MP(p[0]-1, 0));
        if (p[a-1] < n) q.push(MP(n - p[a-1], 0));
        for (int i = 1; i < a; i++){
            int gap = p[i] - p[i-1] -1;
            if (gap <= 0) continue;
            if (gap & 1) q.push(MP((gap+1)/2, 3));
            else q.push(MP(gap/2, 2));
        }
        while (!q.empty() && b > 0){
            pi val = q.top(); q.pop();
            ans += val.first; b--;
            if (val.second == 2) q.push(MP(val.first, 0));
            if (val.second == 3 && val.first >= 2) q.push(MP(val.first-2, 1));
            if (val.second == 1) q.push(MP(1, 0));
        }
        cout << ans << "\n";
    }
}