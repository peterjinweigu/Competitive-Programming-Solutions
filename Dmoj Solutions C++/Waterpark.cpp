#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
int n, x, y; int cur;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector <int> adj[n+1];
    while (true){
        cin >> x; cin >> y;
        if (x == 0 && y == 0){
            break;
        }
        adj[x].push_back(y);
    }
    int dp[n+1];
    for (int i = 0; i < n+1; i++){
        dp[i] = 0;
    }
    dp[1] = 1;
    for (int i = 0; i < n+1; i++){
        for (int k = 0; k < adj[i].size(); k++){
            dp[adj[i][k]] += dp[i];
        }
    }

    cout << dp[n] << endl;
}