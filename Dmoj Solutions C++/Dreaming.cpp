#include <bits/stdc++.h>

using std::vector;
using std::pair;
using std::min;
using std::max;

#pragma GCC optimize("Ofast")
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MAXN = 100000;

vector<pair<int, int>> adj[MAXN];
bool vis[MAXN];
int dist[MAXN];
int parent[MAXN];
int farthestNode = -1;
int maxDist;

void DFS(int node, int prev, int distance) {
	vis[node] = true;
	parent[node] = prev;
	dist[node] = distance;
	if (distance > maxDist) {
		maxDist = distance;
		farthestNode = node;
	}
	for (pair<int, int> next : adj[node]) {
		if (next.first != prev) {
			DFS(next.first, node, distance + next.second);
		}
	}
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
	for (int i = 0; i < M; i++) {
		adj[A[i]].push_back( { B[i], T[i] });
		adj[B[i]].push_back( { A[i], T[i] });
	}
	int maxDiameter = 0;
	int maxRadius = -1;
	int maxRadius2 = -1;
	int maxRadius3 = -1;
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			maxDist = -1;
			DFS(i, i, 0);
			maxDist = 0;
			DFS(farthestNode, farthestNode, 0);
			int diameter = dist[farthestNode];
			int radius = diameter;
			for (int j = farthestNode; j != parent[j]; j = parent[j]) {
				radius = min(radius, max(dist[j], diameter - dist[j]));
			}
			maxDiameter = max(maxDiameter, diameter);
			if (radius > maxRadius) {
				maxRadius3 = maxRadius2;
				maxRadius2 = maxRadius;
				maxRadius = radius;
			} else if (radius > maxRadius2) {
				maxRadius3 = maxRadius2;
				maxRadius2 = radius;
			} else if (radius > maxRadius3) {
				maxRadius3 = radius;
			}
		}
	}
	return max(max(maxRadius2 != -1 ? maxRadius + L + maxRadius2: 0, maxRadius3 != -1 ? maxRadius2 + 2 * L + maxRadius3: 0),
			maxDiameter);
}