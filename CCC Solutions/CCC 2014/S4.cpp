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
#define mod 2021
#define MAXN 2500
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<pi> vi;

struct rect{
    ll x, y, xx, yy, t;
};

vector<rect> v;
set<ll> xTemp, yTemp;
map<ll, ll> xPt, yPt, xVal, yVal;
ll psa[2500][2500];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, t; cin >> n >> t;
    for (int i = 0; i < n; i++){
        ll a, b, c, d, e; cin >> a >> b >> c >> d >> e;
        v.PB({a, b, c, d, e});
        xTemp.insert(a); xTemp.insert(c);
        yTemp.insert(b); yTemp.insert(d);
    }
    int idx = 1;
    for (auto i : xTemp){
        xPt.insert(MP(i, idx));
        xVal.insert(MP(idx, i));
        idx++;
    }
    idx = 1;
    for (auto i : yTemp){
        yPt.insert(MP(i, idx));
        yVal.insert(MP(idx, i));
        idx++;
    }
    for (int i = 0; i < n; i++){
        for (int j = yPt[v[i].y]; j < yPt[v[i].yy]; j++){
            psa[j][xPt[v[i].x]] += v[i].t;
            psa[j][xPt[v[i].xx]] -= v[i].t;
        }
    }
    ll total = 0;

    for (int i = 1; i < yPt.size(); i++){
        for (int j = 1; j < xPt.size(); j++){
            psa[i][j+1] += psa[i][j];
            if (psa[i][j] >= t){
                total += (xVal[j+1] - xVal[j])*(yVal[i+1] - yVal[i]);
            }
        }
    }
    cout << total << "\n";
}
