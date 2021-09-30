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
#define MAXN 3010
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int ans = 0;
    while (n > 1){
        for (int i = n/2; i >= 1; i--){
            if (n % i == 0){
                n -= i;
                ans += (n / i);
                break;
            }
        }
    }
    cout << ans << "\n";
}
