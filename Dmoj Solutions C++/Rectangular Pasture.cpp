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
#define MAXN 2510

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<pi> vi;
int psa[MAXN][MAXN];
vi a;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        a.push_back(make_pair(x, y));
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j == 0){
                if (a[i].second < a[j].second) psa[i][j] = 1;
            }
            else if (a[i].second < a[j].second) psa[i][j] += psa[i][j-1]+ 1;
            else psa[i][j] = psa[i][j-1];
        }
    }
    ll ans = 0;
    for (int i = 0; i < n-1; i++){
        int small = 0;
        int big = 0;
        for (int j = i+1; j < n; j++){
            if (a[j].second > a[i].second){
                ans += small;
                ans += (psa[j][j] - psa[j][i]);
                ans += small*(psa[j][j] - psa[j][i]);
                big += 1;
            }
            else {
                ans += big;
                ans += ((j-i-1) - (psa[j][j] - psa[j][i]));
                ans += big*((j-i-1) - (psa[j][j] - psa[j][i]));
                small += 1;
            }
            ans += 1;

        }
    }
    cout << ans + n + 1 << "\n";
}