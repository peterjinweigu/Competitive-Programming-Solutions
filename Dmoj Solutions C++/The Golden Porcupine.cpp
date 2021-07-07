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
#define mod 2021
#define MAXN 100100
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<pi> vi;
ll psa[3][MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, t; cin >> n >> t;
    for (int i = 0; i < n; i++){
        ll l, r, a, b, c; cin >> l >> r >> a >> b >> c;
        psa[0][l] += (a*l*l) + c - (b*l);
        psa[0][r+1] -= (a*l*l) + c - (b*l);
        psa[1][l] += b - (2*a*l);
        psa[1][r+1] -= b - (2*a*l);
        psa[2][l] += a;
        psa[2][r+1] -= a;
    }
    for (int i = 1; i <= t; i++){
        for (int j = 0; j < 3; j++) psa[j][i] += psa[j][i-1];
        cout << psa[0][i] + (psa[1][i] * i) + (psa[2][i] * i * i) << " ";
    }
    cout << "\n";
}
