import sys

n, v = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
a = []
p = [0 for j in range(v)]
dp = [sys.maxsize for j in range(10001)]
dp[0] = 0

for j in range(v):
    x, y = map(int, sys.stdin.readline().split())
    a.append([j, x, y-1])

a.sort(key=lambda x: x[2])
a = a[::-1]

for i in range(n):
    for j in range(arr[i], 10001):
        dp[j] = min(dp[j], dp[j-arr[i]] + 1)
    while len(a) > 0:
        if a[-1][2] == i:
            if dp[a[-1][1]] < sys.maxsize:
                p[a[-1][0]] = dp[a[-1][1]]
            else:
                p[a[-1][0]] = -1
            a.pop(-1)
        else:
            break
for j in p:
    print(j)



