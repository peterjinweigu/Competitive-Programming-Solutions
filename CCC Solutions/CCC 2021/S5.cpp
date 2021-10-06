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
#define mod 1000000007
#define MAXN 150100
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
int dif[MAXN][17], ans[MAXN];
int sgt[4*MAXN];

struct event{
    int l, r, val;
};

vector<event> queries;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

void build(int left, int right, int x){
	if (left == right){
		sgt[x] = ans[left];
		return;
	}
	int mid = ((left + right) >> 1);
	build(left, mid, 2 * x);
	build(mid + 1, right, 2 * x + 1);
	sgt[x] = gcd(sgt[2 * x], sgt[2 * x + 1]);
}

int query(int left, int right, int l, int r, int x){
	if (right<l || left>r){
		return -1;
	}
	if (left >= l && right <= r){
		return sgt[x];
	}
	int mid = ((left + right) >> 1);
	ll r1 = query(left, mid, l, r, 2 * x), r2 = query(mid + 1, right, l, r, 2 * x + 1);
	if (r1 != -1 && r2 != -1){
		return gcd(r1, r2);
	}
	else if (r1 == -1){
		return r2;
	}
	else{
		return r1;
	}
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y, z; cin >> x >> y >> z;
        queries.PB({x, y, z});
        dif[x][z] += 1;
        dif[y+1][z] -= 1;
    }
    for (int i = 1; i <= n; i++){
        int cur = 1;
        for (int j = 1; j <= 16; j++){
            dif[i][j] += dif[i-1][j];
            if (dif[i][j] != 0) cur = (cur * j) / gcd(cur, j);
        }
        ans[i] = cur;
    }
    bool pos = true;
    build(1, n, 1);
    for (event e : queries){
        if (query(1, n, e.l, e.r, 1) != e.val) {pos = false; break;}
    }
    if (!pos) cout << "Impossible" << "\n";
    else{
        for (int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
