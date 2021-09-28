#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;
int n; int c; int r; int l; int counter;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int m[n];
    int h[n];
    for (int i = 0; i < n; i++){
        cin >> m[i];
    }
    sort(m,m+n);
    counter = 0;
    c = ceil((n-1)/2);
    h[0] = m[c];
    l = c-1;
    r = c+1;
    bool up = false;
    bool down = false;
    while (true){
        if (r < n){
            h[counter + 1] = m[r];
        }
        if (l >= 0){
            h[counter + 2] = m[l];
        }
        if (down == true && up == true){
            break;
        }
        if (l < 0){
            down = true;
        }
        if (r >= n){
            up = true;
        }
        counter += 2;
        l -= 1;
        r += 1;
    }
    for (int w = 0; w < n; w++){
        cout << h[w] << ' ';
    }
    return 0;
}
