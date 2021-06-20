#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;
typedef long long bigNum;
typedef pair<int, int> pi;
int n, m, a, b, xx, yy;

vector <int> al;
int dij[100001];
int s[100001];

int look(int x) {
    while (x != dij[x]){
        x = dij[x];
    }
    return x;
}

void unite(int a, int b, int yy) {
    a = look(a);
    b = look(b);
    if (a != b){
        if (s[a] < s[b]){
            swap(a,b);
        }
        s[a] += s[b];
        dij[b] = a;
        al.push_back(yy);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        dij[i] = i;
        s[i] = 1;
    }
    for (int i = 1; i <= m; i++){
        cin >> a >> b;
        unite(a, b, i);
    }
    if (al.size() != n-1){
        cout << "Disconnected Graph" << endl;
    }
    else{
        for (int j = 0; j < al.size(); j++){
            cout << al[j] << endl;
        }
    }
}
