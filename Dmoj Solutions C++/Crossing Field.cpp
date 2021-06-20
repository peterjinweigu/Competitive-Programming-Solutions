#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <bitset>
#include <iomanip>
#define MAXN 32000000

typedef long long ll;
using namespace std;
ll a[1520][1520];
bool b[1520][1520];
int n, h;

void solve(ll x, ll y){
    if (x+1 < n){
        if (abs(a[x+1][y] - a[x][y]) <= h && !b[x+1][y]){
            b[x+1][y] = true;
            solve(x+1,y);
        }
    }
    if (y+1 < n){
        if (abs(a[x][y+1] - a[x][y]) <= h && !b[x][y+1]){
            b[x][y+1] = true;
            solve(x,y+1);
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 1520; i++){
        for (int j = 0; j < 1520; j++){
            b[i][j] = false;
        }
    }
    cin >> n >> h;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    solve(0, 0);
    if (b[n-1][n-1]) cout << "yes" << endl;
    else cout << "no" << endl;

}