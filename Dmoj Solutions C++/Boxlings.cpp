#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MAXN 200100
#define mod 1000000007

// Stop stalking me
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<int> vi;


int N, M, cnt, ans, bit[3*MAXN];

struct event{
    int x, yl, yh, val;
};

bool cmp(event a, event b){
    if (a.x != b.x) return a.x < b.x;
    else return a.val > b.val;
}

void update(int pos, int val){
    for (int i = pos; i<= cnt; i+=i&-i) bit[i] += val;
}

int query(int pos){
    int sum = 0;
    for (int i = pos; i > 0; i-=i&-i) sum += bit[i];
    return sum;
}

vector <event> v;
map<int, int> mp;


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++){
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        if (r1 <= r2 && c1 <= c2){
            v.PB(event{r1, c1, c2, 1});
            v.PB(event{r2, c1, c2, -1});
            mp[c1] = 0; mp[c2] = 0;
        }
    }
    for (int i = 1; i <= M; i++){
        int x, y; cin >> x >> y;
        v.push_back(event{x, y, y, 0});
        mp[y] = 0;
    }
    for (auto &e : mp) e.second = ++cnt;
    sort(v.begin(), v.end(), cmp);
    for (event e : v){
        if(e.val != 0){
            int lo = mp[e.yl], hi = mp[e.yh];
            update(lo, e.val); update(hi+1, -e.val);
        }
        else{
            int pos = mp[e.yl];
            if(query(pos) > 0) ans ++;
        }
    }
    cout << ans << "\n";
}