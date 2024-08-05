// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;
#define MOD 1e9 + 7;
typedef pair<long, long> pi;

/*
ID: petergu1
TASK: ttwo
LANG: C++14          
*/

// I have a feeling brute forcing on like 100,000 will work
// An actual solution is to DFS on Farmer
// Keep going until you reach a previously visited tile, this creates a loop
// Now when you DFS for COW you will also run into a cycle. Just compare overalapping cycles

int dX[4] = {-1, 0, 1, 0};
int dY[4] = {0, 1, 0, -1};

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return (a.first == b.first) && (a.second == b.second);
}

int main() {
	ofstream cout ("ttwo.out");
    ifstream cin ("ttwo.in"); 

    vector<string> grid(11);
    vector<pair<int, int>> start(2);
    vector<int> dir(2);
    dir[0] = 0;
    dir[1] = 0;

	for (int i = 0; i < 10; i++) {
        cin >> grid[i];
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] == 'F') {
                start[0] = {i, j};
            } else if (grid[i][j] == 'C') {
                start[1] = {i, j};
            }
        }
    }

    for (int t = 1; t <= 160000; t++) {
        for (int i = 0; i < 2; i++) {
            int x = start[i].first + dX[dir[i]];
            int y = start[i].second + dY[dir[i]];
            if (x >= 0 && x < 10 && y >= 0 && y < 10 && grid[x][y] != '*') start[i] = {x, y};
            else dir[i] = (dir[i] + 1) % 4;
        }
        if (cmp(start[0], start[1])) {
            cout << t << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
}

