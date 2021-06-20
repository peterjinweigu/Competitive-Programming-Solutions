import sys

n, m = map(int, sys.stdin.readline().split())

adj = [[] for i in range(n+1)]

for i in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    adj[a].append([b, c])

queue = [1]
v = [False for i in range(n+1)]
dist = [sys.maxsize for i in range(n+1)]
dist2 = [sys.maxsize for i in range(n+1)]
temp = []
allV = [0] * (n+1)
dist[1] = 0
dist2[1] = 0

while queue:
    cur = queue.pop()
    v[cur] = False
    for node in adj[cur]:
        if dist2[node[0]] > node[1] + dist[cur] > dist[node[0]] or dist2[node[0]] == 0:
            dist2[node[0]] = node[1] + dist[cur]
        if node[1] + dist[cur] < dist[node[0]]:
            dist[node[0]] = node[1] + dist[cur]
            allV[node[0]] = cur
            queue.append(node[0])
            v[node[0]] = True

for u in range(n, -1, -1):
    if dist2[u] != 0 and dist2[u] < sys.maxsize and u in temp:
        print(dist2[u] - dist[u] + dist[n])
        break
    elif u == 0:
        print (-1)
        break
