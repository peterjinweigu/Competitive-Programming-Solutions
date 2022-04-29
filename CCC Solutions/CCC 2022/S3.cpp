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
ll a[MAXN];
ll last[MAXN];

int main(){
    ll n, m, k; cin >> n >> m >> k;
    ll idx = 1;
    for (int i = 1; i <= n; i++){
        if (idx > m) idx -= m;
        if (k - (i - last[idx]) >= (n-i)){
            k -= (i - last[idx]);
            last[idx] = i;
            a[i] = idx;
            idx++;
        } else if (k == (n-i)+1){
            for (int j = i; j <= n; j++) a[j] = a[j-1];
            k = 0;
            break;
        } else {
            ll temp = k - (n-i);
            if (temp < 1) break;
            a[i] = a[i - temp];
            k = (n-i);
        }
    }
    if (k != 0) {cout << -1 << "\n"; return 0;}
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
}
