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
#include <iomanip>

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
#define mod 1000000007
#define MAXN 10000001

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef vector<string> vs;
ll a[100001];
ll bit[100001];
ll sBit[100001];
ll n, m;

void add(int x, int k, bool g) {
    while (k <= 100000) {
        if (g) bit[k] += x;
        else sBit[k] += x;
        k += k&-k;
    }
}
ll sum(int k, bool g) {
    ll s = 0;
    while (k >= 1) {
        if (g) s += bit[k];
        else s += sBit[k];
        k -= k&-k;
    }
    return s;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1, y; i <= n; i++){
        cin >> y;
        a[i] = y;
        add(y, i, 1);
        add(1, y, 0);
    }
    for (int i = 0; i < m; i++) {
        char c; int x, y;
        cin >> c;
        if (c == 'C') {
            cin >> x >> y;
            ll dif = y-a[x];
            add(-1, a[x], 0);
            add(1, y, 0);
            add(dif, x, 1);
            a[x] = y;
        }
        else if (c == 'S') {
            cin >> x >> y;
            ll l = sum(x-1, 1), r = sum(y, 1);
            cout << r-l << "\n";
        }
        else if (c == 'Q') {
            cin >> x;
            ll l = sum(x, 0);
            cout << l << "\n";
        }
    }

}