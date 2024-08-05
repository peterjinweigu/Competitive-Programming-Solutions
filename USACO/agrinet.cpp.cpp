// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;
#define MOD 1e9 + 7;
typedef pair<long, long> pi;

/*
ID: petergu1
TASK: agrinet
LANG: C++14          
*/

int lk[110];
int sz[110];

int fd(int a) {
    while (lk[a] != a) a = lk[a];
    return a;
}

void unite(int x, int y) {
    int a = fd(x);
    int b = fd(y);
    if (sz[b] > sz[a]) swap(a, b);
    lk[b] = a;
    sz[a] += sz[b];
}

struct edge {
    int a, b, c;
};

bool cmp(const edge& x, const edge& y) {
    return x.c < y.c;
} 


int main() {
	ofstream cout ("agrinet.out");
    ifstream cin ("agrinet.in"); 

    vector<edge> v;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) lk[i] = i, sz[i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            if (i != j) v.push_back({i, j, x});
        }
    }
    sort(v.begin(), v.end(), cmp);

    int ans = 0;
    for (edge u : v) {
        if (fd(u.a) != fd(u.b)) {
            unite(u.a, u.b);
            ans += u.c;
        }
    }

    cout << ans << "\n";
}

