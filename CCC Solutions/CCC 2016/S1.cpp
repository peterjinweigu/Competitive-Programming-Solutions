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
#define MAXN 20100
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
map<char, int> mp;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, t; cin >> s >> t;
    int n = s.size();
    for (int i = 0; i < n; i++) mp[t[i]]++;
    for (int i = 0; i < n; i++){
        char c = s[i];
        if (mp[c] == 0 && mp['*'] == 0) {cout << "N" << "\n"; return 0;}
        else {
            if (mp[c] > 0) mp[c]--;
            else mp['*']--;
        }
    }
    cout << "A" << "\n";
}
