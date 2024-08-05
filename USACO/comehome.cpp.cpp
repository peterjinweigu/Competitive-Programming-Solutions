// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;
#define MOD 1e9 + 7;
typedef pair<long, long> pi;

/*
ID: petergu1
TASK: comehome
LANG: C++14          
*/

vector<pair<int, ll>> adj[100];

int main() {
	ofstream cout ("comehome.out");
    ifstream cin ("comehome.in"); 

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        char x, y; cin >> x >> y;
        int a = (int)(x - 'A');
        int b = (int)(y - 'A');
        ll c; cin >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    int ans = -1;
    ll cnt = 1e12;
    vector<ll> dist(100);
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j <= 100; j++) dist[j] = 1e12;
        dist[i] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> pq; 
        while (pq.size() > 0) pq.pop();
        pq.push({0, i});
        while (pq.size() > 0) {
            pi cur = pq.top();
            pq.pop();
            for (auto j : adj[cur.second]) {
                if (dist[cur.second] + j.second < dist[j.first]) {
                    dist[j.first] = dist[cur.second] + j.second;
                    pq.push({dist[j.first], j.first});
                }
            }
        }
        if (dist[25] < cnt) {
            cnt = dist[25];
            ans = i;
        }
    }
    cout << (char)(ans + 'A') << " " << cnt << "\n";
}

