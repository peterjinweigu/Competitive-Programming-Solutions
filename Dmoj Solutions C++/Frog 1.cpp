#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <bitset>


typedef long long bigNum;
using namespace std;
int n;

int main(){
    cin >> n;
    int dp[n+1];
    memset(dp, 10000, sizeof dp);
    dp[0] = 0;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int j = 0; j < n-1; j++){
        dp[j+1] = min(dp[j+1], dp[j] + abs(arr[j] - arr[j+1]));
        dp[j+2] = min(dp[j+2], dp[j] + abs(arr[j] - arr[j+2]));
    }
    cout << dp[n-1] << endl;
}
