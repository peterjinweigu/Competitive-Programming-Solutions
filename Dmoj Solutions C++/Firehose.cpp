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
#include <bits/stdc++.h>

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
vi a;
int h, k;

bool sendHelp(int len){
    for (int j = 0; j < h; j++){
        bool work = true;
        int total = 1;
        int last = (a[j]+len)%1000000;
        int cnt = j+1;
        while (cnt < h+j){
            int i = cnt;
            if (cnt >= h) i -= h;
            if (abs(last-a[i]) > len && abs(last-1000000)+a[i] > len){
                total += 1;
                last = (a[i]+len)%1000000;
            }
            if (total > k)work = false;
            cnt ++;
        }
        if (work) return true;
    }
    return false;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> h;
    for (int i = 0, p; i < h; i++){cin >> p; a.push_back(p);}
    sort(a.begin(), a.end());
    cin >> k;
    if (k >= h) {cout << 0 << "\n"; return 0;}
    int lo = 1, hi = 1000000, ans = 0;
    while (lo <= hi){
        int mid = (lo+hi)/2;
        if (sendHelp(mid)){hi = mid-1; ans = mid;}
        else lo = mid+1;
    }
    cout << ans << "\n";

}