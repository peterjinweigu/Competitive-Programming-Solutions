import sys
n, m = map(int, sys.stdin.readline().split())
d = {}
p = 0.0000000001
edges = []
for j in range(n):
    d[sys.stdin.readline().strip()] = j
for i in range(m):
    a, b, c = sys.stdin.readline().split()
    edges.append([d[a], d[b], float(c)])

dist = [0]*n
dist[d["APPLES"]] = 1

for j in range(n-1):
    for u, v, w in edges:
        if dist[u]*w+p > dist[v]:
            dist[v] = dist[u]*w


if dist[d["APPLES"]] > 1.00000000001:
    print("YA")
else:
    print("NAW")

