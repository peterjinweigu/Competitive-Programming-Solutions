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
#define MAXN 3100
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
ll eBit[MAXN][MAXN], oBit[MAXN][MAXN], old[MAXN][MAXN];

// update
void update(int r, int c, ll val, int par) {
    for(int i = r; i < MAXN; i += i & -i){
        for(int j = c; j < MAXN; j += j & -j){
            if (par == 1) oBit[i][j] += val;
            else eBit[i][j] += val;
        }
    }
}

// query (rectangle query)
ll query (int r, int c, int par) {
	ll sum = 0;
	for(int i = r; i > 0; i -= i & -i){
		for(int j = c; j > 0; j -= j&-j){
            if (par == 1) sum += oBit[i][j];
            else sum += eBit[i][j];
		}
	}
	return sum;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m, n; cin >> m >> n;
    while (true){
        int x; cin >> x;
        if (x == 0) break;
        if (x == 1){
            ll r, c, x; cin >> r >> c >> x;
            if ((r+c) % 2 == 0) {update(r, c, -old[r][c], 2), update(r, c, x, 2); old[r][c] = x;}
            else {update(r, c, -old[r][c], 1), update(r, c, x, 1); old[r][c] = x;}
        } else {
            ll a, b, c, d; cin >> a >> b >> c >> d;
            ll od = query(c, d, 1) - query(c, b-1, 1) - query(a-1, d, 1) + query(a-1, b-1, 1);
            ll ev = query(c, d, 2) - query(c, b-1, 2) - query(a-1, d, 2) + query(a-1, b-1, 2);
            if ((a+b) % 2 == 0) cout << ev - od << "\n";
            else cout << od - ev << "\n";
        }
    }
}
