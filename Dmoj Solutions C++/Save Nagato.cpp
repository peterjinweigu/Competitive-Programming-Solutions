#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define s(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define MAXN 500001

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
int dist[MAXN], dist1[MAXN], dist2[MAXN];
vi adj[MAXN];
queue <int> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < MAXN; i++){
        dist[i] = -1, dist1[i] = -1, dist2[i] = -1;
    }
    int n;
    cin >> n;
    for (int i = 0, a, b; i < n-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    q.push(1);
    dist[1] = 1;
    while (q.size() > 0){
        int cur = q.front();
        q.pop();
        for (int node : adj[cur]){
            if (dist[node] == -1 || dist[cur] + 1 < dist[node]){
                dist[node] = dist[cur] + 1;
                q.push(node);
            }
        }
    }
    int mex = 0;
    for (int i = 1; i <=n; i++){
        if (dist[i] > dist[mex]) mex = i;
    }
    q.push(mex);
    dist1[mex] = 1;
    while (q.size() > 0){
        int cur = q.front();
        q.pop();
        for (int node : adj[cur]){
            if (dist1[node] == -1 || dist1[cur] + 1 < dist1[node]){
                dist1[node] = dist1[cur] + 1;
                q.push(node);
            }
        }
    }
    mex = 0;
    for (int i = 1; i <= n; i++){
        if (dist1[i] > dist1[mex]) mex = i;
    }
    q.push(mex);
    dist2[mex] = 1;
    while (q.size() > 0){
        int cur = q.front();
        q.pop();
        for (int node : adj[cur]){
            if (dist2[node] == -1 || dist2[cur] + 1 < dist2[node]){
                dist2[node] = dist2[cur] + 1;
                q.push(node);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        cout << max(dist1[i], dist2[i]) << endl;
    }
}