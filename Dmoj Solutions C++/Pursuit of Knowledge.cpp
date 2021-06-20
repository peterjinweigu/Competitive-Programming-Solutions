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
#define MAXN 0

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
int d[1001][1001];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 1001; i++){
        for(int j = 0; j < 1001; j++){
            d[i][j] = 1e9;
        }
    }
    int n, m, t, q;
    cin >> n >> m >> t;
    for (int i = 0, a, b; i < m; i++){
        cin >> a >> b;
        d[a][b] = 1;
    }
    // floyd warshall
    for (int k = 0; k <= n; ++k) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    cin >> q;
    for (int i = 0, a, b; i < q; i++){
        cin >> a >> b;
        if (d[a][b] == 1e9) cout << "Not enough hallways!" << endl;
        else cout << d[a][b]*t << endl;
    }

}