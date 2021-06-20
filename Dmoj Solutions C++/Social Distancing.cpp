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
#define MAXN 100000000000010

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
int n, m;
vector <pair<ll,ll>> a;

bool sendHelp(ll gap){
    int total = 0;
    //:^)
    ll last = -1000000000000000000;
    for (int i = 0; i < a.size(); i++){
        while(max(last+gap, a[i].first) <= a[i].second){
            last = max(last+gap, a[i].first);
            total += 1;
            if (total >= n) return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0, x, y; i < m; i++){cin >> x >> y; a.push_back(make_pair(x, y));}
    sort(a.begin(), a.end());
    ll lo = 1, hi = 1000000000000000000, ans = 0;
    while (lo <= hi){
        ll mid = (lo + hi)/2;
        if (sendHelp(mid)){ans = mid;lo = mid+1;}
        else hi = mid - 1;
    }
    cout << ans << endl;

}