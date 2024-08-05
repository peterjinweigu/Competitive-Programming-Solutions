// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;
#define MOD 1e9 + 7;
typedef pair<long, long> pi;

/*
ID: petergu1
TASK: cowtour
LANG: C++14          
*/

// Floyd Warshall
// Run floyd
// For each node, find the longest 
// Then for every dis[i][j] that dosent exist
// Connect the two, plus longest
// Last part, run dsu on all edges and get parents
// Every merge, also store longest shortest path
//

double dist[160][160]; 
int par[160]; // dont need size merge, n is very small
double dim[160];

int fd(int a) {
    while (par[a] != a) a = par[a];
    return a;
}

void merge(int a, int b) {
    par[fd(a)] = par[fd(b)];
}

double euclid(double a, double b, double c, double d) {
    return sqrt(abs(a - c) * abs(a - c) + abs(b - d) * abs(b - d));
}

int main() {
	ofstream cout ("cowtour.out");
    ifstream cin ("cowtour.in"); 
    int n; cin >> n;
    vector<pair<double, double>> v(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i].first >> v[i].second;
    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int j = 1; j <= n; j++) {
            dist[i][j] = 1e18;
            if (s[j-1] == '1') {
                merge(i, j);
                dist[i][j] = euclid(v[i].first, v[i].second,
                                    v[j].first, v[j].second);
            }
            if (j == i) dist[i][j] = 0;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
            }
        }
    }
    vector<double> worst(n+1);
    for (int i = 1; i <= n; i++) {
        worst[i] = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] != 1e18) worst[i] = max(worst[i], dist[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        dim[fd(i)] = max(dim[fd(i)], worst[i]);
    }
    double ans = 1e18;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == 1e18) {
                double cur = euclid(v[i].first, v[i].second,
                                    v[j].first, v[j].second);
                double temp = max(worst[i] + worst[j] + cur, max(dim[fd(i)], dim[fd(j)]));
                ans = min(ans, temp);
            }
        }
    }
    cout << fixed << setprecision(6);
    cout << ans << "\n";

}

