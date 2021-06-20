#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
typedef long long bigNum;
typedef pair<double, double> pi;
int d, e, a, b;
double minn, h, cur, c;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> h >> d >> e;
    pi def[d];
    double psa[2000];
    memset(psa, 0, sizeof psa);
    for (int i = 0; i < d; i++){
        cin >> def[i].first >> def[i].second;
    }
    for (int i = 0; i < e; i++){
        cin >> a >> b >> c;
        psa[a] += c;
        psa[b+a] -= c;
    }
    for (int i = 1; i < 2000; i++){
        psa[i] = psa[i] + psa[i-1];
    }
    for (int j = 0; j < 2000; j++){
        minn = psa[j];
        for (int i = 0; i < d; i++){
            cur = (psa[j] - def[i].second) * (1 - (def[i].first/100));
            if (cur < 0) cur = 0;
            minn = min(cur, minn);
        }
        h -= minn;
    }
    cout << fixed;
    cout << setprecision(2);
    if (h <= 0){
        cout << "DO A BARREL ROLL!" << endl;
    } else{
        cout << h << endl;
    }
}