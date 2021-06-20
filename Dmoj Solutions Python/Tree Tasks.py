import sys
from collections import deque

# Unfortunately this solution will TLE on DMOJ (C++ w/ same logic passes)

n = int(sys.stdin.readline().strip())
adj = [[] for j in range(n+1)]

for j in range(n-1):
    a, b, c = map(int, sys.stdin.readline().split())
    adj[a].append([b, c])
    adj[b].append([a, c])

d = deque()
d.append(1)

dist1 = [sys.maxsize for i in range(n+1)]
dist2 = [sys.maxsize for i in range(n+1)]
dist1[1] = 0

while len(d) > 0:
    cur = d.popleft()
    for node in adj[cur]:
        if dist1[cur] + node[1] < dist1[node[0]]:
            dist1[node[0]] = dist1[cur] + node[1]
            d.append(node[0])

mx = 1
for j in range(1, len(dist1)):
    if dist1[j] > dist1[mx]:
        mx = j

dist1 = [sys.maxsize for i in range(n+1)]
dist1[mx] = 0
d.append(mx)

while len(d) > 0:
    cur = d.popleft()
    for node in adj[cur]:
        if dist1[cur] + node[1] < dist1[node[0]]:
            dist1[node[0]] = dist1[cur] + node[1]
            d.append(node[0])

mx = 1
for j in range(1, len(dist1)):
    if dist1[j] > dist1[mx]:
        mx = j

print(dist1[mx])

dist2[mx] = 0
d.append(mx)

while len(d) > 0:
    cur = d.popleft()
    for node in adj[cur]:
        if dist2[cur] + node[1] < dist2[node[0]]:
            dist2[node[0]] = dist2[cur] + node[1]
            d.append(node[0])

minn = sys.maxsize
for j in range(1, n+1):
    minn = min(minn, max(dist1[j], dist2[j]))

print(minn)