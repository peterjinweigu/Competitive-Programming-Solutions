import sys


n = int(sys.stdin.readline().strip())
dp = [[0 for j in range(n+1)] for i in range(n+1)]

arr = list(map(int, sys.stdin.readline().split()))
for j in range(1, n+1):
    dp[j][j] = arr[j-1]

for j in range(1, n):
    for i in range(1, n-j+1):
        k = j+i
        dp[i][k] = max(arr[i-1] - dp[i+1][k], arr[k-1] - dp[i][k-1])

print(dp[1][n])

