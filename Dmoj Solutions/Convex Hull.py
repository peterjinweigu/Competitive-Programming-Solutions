import sys

k, n, m = sys.stdin.readline().split()
k = int(k)
adj = [[] for i in range(int(n)+1)]

for i in range(int(m)):
    a, b, t, h = sys.stdin.readline().split()
    adj[int(a)].append([int(b), int(t), int(h)])
    adj[int(b)].append([int(a), int(t), int(h)])

s, e = sys.stdin.readline().split()
s = int(s)
e = int(e)

dp = [[sys.maxsize for x in range(k + 1)] for y in range(int(n) + 1)]
for w in range(k+1):
    dp[s][w] = 0
vi = [False for c in range(int(n)+1)]
queue = [s]

while len(queue) > 0:
    cur = queue.pop(0)
    vi[cur] = False
    for node in adj[cur]:
        for i in range(k - node[2] + 1):
            if dp[cur][i] + node[1] < dp[node[0]][i + node[2]]:
                dp[node[0]][i + node[2]] = dp[cur][i] + node[1]
                if not vi[node[0]]:
                    queue.append(node[0])
                    vi[node[0]] = True

if dp[e][k-1] == sys.maxsize:
    print(-1)
else:
    print(dp[e][k-1])




