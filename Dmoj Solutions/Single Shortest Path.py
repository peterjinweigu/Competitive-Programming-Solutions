import sys

a, b = sys.stdin.readline().split()
adj = [[] for i in range(int(a))]

for j in range(int(b)):
    x, y, z = sys.stdin.readline().split()
    adj[int(x)-1].append([int(y)-1, int(z)])
    adj[int(y)-1].append([int(x)-1, int(z)])


queue = [0]
dp = [-1] * int(a)
dp[0] = 0
v = [False for l in range(int(a))]
v[0] = True

while len(queue) > 0:
    cur = queue.pop(0)
    for q in adj[cur]:
        if v[q[0]] is False:
            queue.append(q[0])
            v[q[0]] = True
        if dp[q[0]] > q[1] + dp[cur] and dp[q[0]] != -1:
            dp[q[0]] = q[1] + dp[cur]
        elif dp[q[0]] == -1:
            dp[q[0]] = q[1] + dp[cur]

for item in dp:
    print(item)

