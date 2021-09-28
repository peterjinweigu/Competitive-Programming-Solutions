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
int psa[401];
bool dp[401][401];

bool checkD(int l, int r){
    for(int mid = l; mid < r; mid++){
        if(dp[l][mid] && dp[mid+1][r] && psa[mid]-psa[l-1] == psa[r]-psa[mid])return true;
    }
    return false;
}

bool checkT(int l, int r){
    for(int ms = l+1; ms < r; ms++){
        if(!dp[l][ms-1])continue;
        for(int me = ms; me < r; me++){
            if(dp[ms][me] && dp[me+1][r] && psa[r]-psa[me] == psa[ms-1]-psa[l-1])return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i <= 400; i++){
        for (int j = 0; j <= 400; j++){
            dp[i][j] = false;
        }
    }
    psa[0] = 0;
    int n, mx = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> psa[i];
        psa[i] += psa[i-1];
        dp[i][i] = true;
    }
    for (int k = 1; k < n; k++){
        for (int i = 1; i <= n-k; i++){
            int j = k+i;
            if (j-i <= 2 && psa[i]-psa[i-1] == psa[j]-psa[j-1] && dp[i][i] && dp[j][j]) dp[i][j] = true;
            else if(checkD(i,j))dp[i][j] = true;
            else if(checkT(i,j))dp[i][j] = true;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            if (dp[i][j]){
                mx = max(mx, psa[j] - psa[i-1]);
            }
        }
    }
    cout << mx << endl;
}
