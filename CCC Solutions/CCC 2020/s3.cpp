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
#define MAXN 200100
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
ll hsh[MAXN], pw[MAXN], hsh2[MAXN], pw2[MAXN];
const int base = 131, base2 = 139;
unordered_set<ll> st;
ll getSubHash(int l, int r){
    ll v1 = (hsh[r] - hsh[l-1] * pw[r-l+1] % mod + mod) % mod;
    ll v2 = (hsh2[r] - hsh2[l-1] * pw2[r-l+1] % mod + mod) % mod;
    return (v1 << 31) | v2;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> fs(26), ft(26);
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    for (int i = 0; i < n; i++) fs[s[i] - 'a']++;
    hsh[0] = 0; pw[0] = 1, hsh2[0] = 0, pw2[0] = 1;
    for (int i = 0; i < m; i++){
        hsh[i+1] = (hsh[i]*base + t[i]) % mod;
        pw[i+1] = pw[i] * base % mod;
        hsh2[i+1] = (hsh2[i]*base2 + t[i]) % mod;
        pw2[i+1] = pw2[i] * base2 % mod;
    }
    for (int i = 1; i <= m; i++){
        ft[t[i-1] - 'a']++;
        if(i > n) ft[t[i-n-1] - 'a']--;
        if (i >= n && fs == ft) st.insert(getSubHash(i - n  + 1, i));
    }
    cout << st.size() << "\n";
}