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
#define MAXN 2010
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<pi> vi;
ll a[MAXN];
ll ans[MAXN*2];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ifstream input("test.txt");
    int n; cin >> n;
    for (int i = 0; i < n; i++){int c; cin >> c; a[c] += 1;}
    for (int i = 1; i < 2001; i++){
        if (a[i] != 0){
            for (int j = i; j < 2001; j++){
                if (i == j) ans[i+j] += a[i] / 2;
                else ans[i+j] += min(a[i], a[j]);
            }
        }
    }
    ll idx = 0, total = 0;
    for (int i = 1; i < 4001; i++){
        if (ans[i] > ans[idx]){
            idx = i;
            total = 1;
        } else if (ans[i] == ans[idx]) total += 1;
    }
    cout << ans[idx] << " " << total << "\n";
}
