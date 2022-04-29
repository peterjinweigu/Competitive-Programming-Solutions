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
#define MAXN 1001000
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
vector<pair<string, string>> xA, yA;
map<string, set<string>> adj;

int main(){
    int x; cin >> x;
    for (int i = 0; i < x; i++){
        string a, b; cin >> a >> b;
        xA.PB({a, b});
    }
    int y; cin >> y;
    for (int i = 0; i < y; i++){
        string a, b; cin >> a >> b;
        yA.PB({a, b});
    }
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        string a, b, c; cin >> a >> b >> c;
        adj[a].insert(b), adj[a].insert(c);
        adj[b].insert(c), adj[b].insert(a);
        adj[c].insert(a), adj[c].insert(b);
    }
    int ans = 0;
    for (int i = 0; i < x; i++){
        string a = xA[i].first;
        string b = xA[i].second;
        if (adj[a].find(b) == adj[a].end())ans++;
    }
    for (int i = 0; i < y; i++){
        string a = yA[i].first;
        string b = yA[i].second;
        if (adj[a].find(b) != adj[a].end())ans++;
    }
    cout << ans << "\n";
}
