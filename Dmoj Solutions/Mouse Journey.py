import sys

r, c = map(int, sys.stdin.readline().split())
dp = [[0 for i in range(c+1)] for j in range(r+1)]
visited = [[False for i in range(c+1)] for j in range(r+1)]
n = int(sys.stdin.readline())

for i in range(n):
    a, b = map(int, sys.stdin.readline().split())
    visited[a][b] = True

dp[1][1] = 1
visited[1][1] = True

for i in range(1, r+1):
    for j in range(1, c+1):
        if visited[i][j] is False:
            dp[i][j] = dp[i-1][j] + dp[i][j-1]

print(dp[r][c])