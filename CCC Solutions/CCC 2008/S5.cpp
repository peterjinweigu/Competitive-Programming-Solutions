#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <bitset>

typedef long long bigNum;
using namespace std;
int t, a, b, c, d;
int dp[31][31][31][31];
int moves[5][4] = {{2, 1, 0, 2}, {1, 1, 1, 1}, {0, 0, 2, 1}, {0, 3, 0, 0}, {1, 0, 0, 1}};

bool check(int a, int b, int c, int d){
    if (a < 0 || b < 0 || c < 0 || d < 0){
        return false;
    }
    else{
        return !dp[a][b][c][d];
    }
}

int main(){
    for (int a = 0; a <= 30; a++){
        for (int b = 0; b <= 30; b++){
            for (int c = 0; c <= 30; c++){
                for (int d = 0; d <= 30; d++){
                        dp[a][b][c][d] = false;
                }
            }
        }
    }

    for (int a = 0; a <= 30; a++){
        for (int b = 0; b <= 30; b++){
            for (int c = 0; c <= 30; c++){
                for (int d = 0; d <= 30; d++){
                    for (int j = 0; j < 5; j++){
                        if (check(a - moves[j][0], b - moves[j][1], c - moves[j][2], d - moves[j][3])) dp[a][b][c][d] = true;
                    }
                }
            }
        }
    }
    cin >> t;
    while (t--){
        cin >> a >> b >> c >> d;
        if (dp[a][b][c][d]){
            cout << "Patrick" << endl;
        }
        else {
            cout << "Roland" << endl;
        }
    }
}
