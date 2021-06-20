#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;
typedef long long bigNum;
typedef pair<int, int> pi;
int n, m;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int t[n];
    int dp[n];
    for (int i = 0; i < n; i++){
        dp[i] = 0;
    }
    for (int i = 0; i < n; i++){
        cin >> m;
        t[i] = m;
    }
    for (int i = 0; i < n; i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++){
            if (t[i] > t[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int maxx = 0;
    for (int i = 0; i < n; i++){
        maxx = max(maxx, dp[i]);
    }
    cout << maxx << endl;
}