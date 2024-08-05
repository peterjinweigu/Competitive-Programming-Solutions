// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;

/*
ID: petergu1
TASK: castle
LANG: C++14          
*/

// This is going to be messy
// DFS flood fill, mark each node by number of room
// Seperate array to store the final size of the room
// Iterate on all the walls later and connect the two rooms to find the best one
// Actually when you are doing this, iterate from n -> 1 (weird priority)
// To represent the walls honestly just use a protocol with bitwise operations

int m, n;
int adj[55][55];
int sz[300];
int vis[55][55];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
string dirOut[4] = {"W", "N", "E", "S"};

int fld(int x, int y, int idx) {
    vis[x][y] = idx;
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        if (!(adj[x][y] & (1 << i))) {
            int curX = x + dx[i];
            int curY = y + dy[i];
            if (curX >= 1 && curX <= n && curY >= 1 && curY <= m && !vis[curX][curY]) {
                ret += fld(curX, curY, idx);
            }
        }
    }
    return ret + 1;
}


int main() {
	ofstream cout ("castle.out");
    ifstream cin ("castle.in");
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> adj[i][j];
            vis[i][j] = 0;
        }
    }
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j]) {
                sz[idx] = fld(i, j, idx);
                idx++;
            }
        }
    }
    int mx = 1;
    for (int i = 1; i < idx; i++) mx = max(mx, sz[i]);
    cout << idx-1 << "\n";
    cout << mx << "\n";
    int bestX = 0;
    int bestY = 0;
    int dir = 0;
    int ans = 0;
    for (int y = 1; y <= m; y++) {
        for (int x = n; x >= 1; x--) {
            for (int i = 0; i < 4; i++) {
                int curX = x + dx[i];
                int curY = y + dy[i];
                if (curX >= 1 && curX <= n && curY >= 1 && curY <= m) {
                    int temp = sz[vis[x][y]];
                    if (vis[x][y] != vis[curX][curY]) temp += sz[vis[curX][curY]];
                    if (temp > ans) {
                        ans = temp;
                        bestX = x;
                        bestY = y;
                        dir = i;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    cout << bestX << " " << bestY << " " << dirOut[dir] << "\n";
}

