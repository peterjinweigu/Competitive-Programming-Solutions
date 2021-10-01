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
#define MAXN 200010
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<pi> vi;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (true){
        int n; cin >> n;
        if (n == 0) break;
        ll total = 0;
        for (int i = 0; i <= n; i++){
            total += (int)sqrt(n*n-i*i);
        }
        cout << total*4 + 1 << "\n";
    }
}
