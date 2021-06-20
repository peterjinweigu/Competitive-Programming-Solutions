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
int n, m, k, c[MAXN], t[MAXN];

bool check(int cnt){
    int a = 0, b = 0, idx = 0;
    while (a < n && b < m){
        if (c[a] >= t[b] && c[a]-k <= t[b]){
            idx++;
            a++;
        }else{
            idx = 0;
            b++;
        }
        if (idx == cnt){
            idx = 0;
            b++;
        }
    }
    if (a == n) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < m; i++) cin >> t[i];
    sort(c, c+n);
    sort(t, t+m);
    int lo = 1, hi = n, ans = -1;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if (check(mid)) {ans = mid; hi = mid - 1;}
        else lo = mid + 1;
    }
    cout << ans << "\n";
}