// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
typedef long long ll;
#define MOD 1e9 + 7;
typedef pair<long, long> pi;

/*
ID: petergu1
TASK: maze1
LANG: C++14          
*/

vector<pair<int, int>> adj[105][40];
int dis[105][40];


int main() {
	ofstream cout ("maze1.out");
    ifstream cin ("maze1.in"); 

	int w, h; cin >> w >> h;
    vector<string> grid(h*2 + 1);
	vector<pair<int, int>> start;
	string s; getline(cin, s);
	for (int i = 0; i < 2*h + 1; i++) getline(cin, grid[i]);
	for (int i = 1; i <= h; i++) {
		int x = i*2 - 1;
		for (int j = 1; j <= w; j++) {
			dis[i][j] = 1e9;
			int y = j*2 - 1;
			if (grid[x-1][y] == ' ') {
				adj[i][j].push_back({i-1, j});
				if (x-1 == 0) start.push_back({i, j});
			}
			if (grid[x][y-1] == ' ') {
				adj[i][j].push_back({i, j-1});
				if (y-1 == 0) start.push_back({i, j});
			}
			if (grid[x+1][y] == ' ') {
				adj[i][j].push_back({i+1, j});
				if (x+1 == 2*h) start.push_back({i, j});
			}
			if (grid[x][y+1] == ' ') {
				adj[i][j].push_back({i, j+1});
				if (y+1 == 2*w) start.push_back({i, j});
			}
		}
	}
	queue<pair<int, int>> q;
	for (auto j : start) {
		q.push({j.first, j.second});
		dis[j.first][j.second] = 1;
		while (q.size() > 0) {
			int curX = q.front().first;
			int curY = q.front().second;
			q.pop();
			for (auto u : adj[curX][curY]) {
				if (dis[u.first][u.second] > dis[curX][curY] + 1) {
					dis[u.first][u.second] = dis[curX][curY] + 1;
					q.push({u.first, u.second});
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			//cout << dis[i][j] << " ";
			ans = max(ans, dis[i][j]);
		}
		//cout << "\n";
	}
	cout << ans << "\n";
}

