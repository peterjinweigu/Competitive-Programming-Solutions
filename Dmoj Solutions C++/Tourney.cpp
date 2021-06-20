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
#define MAXN 1000010
#define mod 1000000007

// :/
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
int n, m, k;
pi t[1<<21];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    n = 1<<n; k = n-1;
    for (int i = k+1; i<=k+n; i++){
        cin >> t[i].first; t[i].second = i-k;
    }
    for (int i = k; i >= 1; i--){
        t[i] = max(t[2*i], t[2*i+1]);
    }
    char op;
    for (int i = 1, x, y; i<=m; i++){
        cin >> op;
        if (op == 'W') cout << t[1].second << "\n";
        else if (op == 'S'){
            cin >> x; int cnt = 0;
            for (int i = (k+x)/2; i >= 1; i >>= 1){
                if(t[i].second == x) cnt++;
                else break;
            }
            cout << cnt << "\n";
        } else {
            cin >> x >> y; x += k;
            t[x].first = y;
            for (int i = x/2; i>=1; i >>= 1){
                t[i] = max(t[2*i], t[2*i+1]);
            }
        }
    }
}