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
#define MAXN 1000010
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
int a[MAXN], b[MAXN], c[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    for (int i = 1; i <= n; i++){
        a[i] += a[i-1], b[i] += b[i-1], c[i] += c[i-1];
        if (s[i-1] == 'A') a[i]++;
        else if (s[i-1] == 'B') b[i]++;
        else if (s[i-1] == 'C') c[i]++;
    }
    int ans = 1e9;
    int l, ml, smA, smB, inter;
    // a b
    for (int i = 1; i <= n; i++){
        if (a[n] + b[n] <= i){
            l = i - a[n];
            ml = i - b[n] - a[n];
            smA = a[n] - (a[i] - a[l]);
            smB = b[n] - (b[l] - b[ml]);
            inter = min(a[l] - a[ml], b[i] - b[l]);
            ans = min(ans, smA + smB - inter);
            l = i - b[n];
            ml = i - b[n] - a[n];
            smA = a[n] - (a[l] - a[ml]);
            smB = b[n] - (b[i] - b[l]);
            inter = min(a[i] - a[l], b[l] - b[ml]);
            ans = min(ans, smA + smB - inter);
        }
    }
    // a c
    for (int i = 1; i <= n; i++){
        if (a[n] + c[n] <= i){
            l = i - a[n];
            ml = i - c[n] - a[n];
            smA = a[n] - (a[i] - a[l]);
            smB = c[n] - (c[l] - c[ml]);
            inter = min(a[l] - a[ml], c[i] - c[l]);
            ans = min(ans, smA + smB - inter);
            l = i - c[n];
            ml = i - c[n] - a[n];
            smA = a[n] - (a[l] - a[ml]);
            smB = c[n] - (c[i] - c[l]);
            inter = min(a[i] - a[l], c[l] - c[ml]);
            ans = min(ans, smA + smB - inter);
        }
    }
    // b c
    for (int i = 1; i <= n; i++){
        if (c[n] + b[n] <= i){
            l = i - c[n];
            ml = i - b[n] - c[n];
            smA = c[n] - (c[i] - c[l]);
            smB = b[n] - (b[l] - b[ml]);
            inter = min(c[l] - c[ml], b[i] - b[l]);
            ans = min(ans, smA + smB - inter);
            l = i - b[n];
            ml = i - b[n] - c[n];
            smA = c[n] - (c[l] - c[ml]);
            smB = b[n] - (b[i] - b[l]);
            inter = min(c[i] - c[l], b[l] - b[ml]);
            ans = min(ans, smA + smB - inter);
        }
    }
    cout << ans << "\n";
}
