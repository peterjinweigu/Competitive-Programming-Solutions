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
#define MAXN 1001000
#define mod 1000000007

// Stop stalking me
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
vi ans;
bool all[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    ll temp = 0;
    ans.PB(n);
    for (int i = 1; i <= n-2; i++){
        if (temp + (n-1) - i <= k){
            temp += (n-1) - i;
            ans.PB(i);
            all[i] = true;
        }
    }
    ans.PB(n-1);
    if (temp != k) cout << -1 << "\n";
    else{
        for (int j = n-2; j > 0; j--){
            if (!all[j]) ans.PB(j);
        }
        for (auto j : ans){
            cout << j << " ";
        }
        cout << "\n";
    }
}