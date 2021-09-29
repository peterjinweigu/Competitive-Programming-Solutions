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
#define MAXN 1050
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
int bit[MAXN][MAXN];
int n;

// update
void update(int r, int c, int val ) {
    for(int i = r; i <= n; i += i & -i){
        for(int j = c; j <= n; j += j & -j){
            bit[i][j] += val;
        }
    }
}

// query (rectangle query)
ll query (int r, int c) {
	int sum = 0;
	for(int i = r; i > 0; i -= i & -i){
		for(int j = c; j > 0; j -= j&-j){
			sum += bit[i][j];
		}
	}
	return sum;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (true){
        int x; cin >> x;
        if (x == 0) cin >> n;
        else if (x == 1){
            int a, b, c; cin >> a >> b >> c;
            a++, b++;
            update(a, b, c);
        } else if (x == 2){
            int a, b, c, d; cin >> a >> b >> c >> d;
            c++, d++, a++, b++;
            cout << query(c, d) - query(c, b-1) - query(a-1, d) + query(a-1, b-1) << "\n";
        } else {
            break;
        }
    }
    return 0;
}
