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
#define MAXN 110
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
string a[MAXN], b[MAXN];
map<string, string> mp;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    bool pos = true;
    for (int i = 0; i < n; i++){
        if (a[i] == b[i]) pos = false;
        else if (mp[b[i]] != a[i] && mp[b[i]].size() > 0) pos = false;
        if (!pos) break;
        mp[a[i]] = b[i];
    }
    if (pos) cout << "good" << "\n";
    else cout << "bad" << "\n";
}
