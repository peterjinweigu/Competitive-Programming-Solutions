import sys

adj = [[] for i in range(8)]
adj[7].append(1)
adj[4].append(1)
adj[1].append(2)
adj[4].append(3)
adj[5].append(3)

while True:
    a = int(sys.stdin.readline())
    b = int(sys.stdin.readline())
    if a == 0 and b == 0:
        break
    adj[b].append(a)

queue = []
order = []

for item in range(1,8):
    if len(adj[item]) == 0:
        queue.append(item)


v = [False for i in range(8)]

for i in queue:
    v[i] = True

while len(queue) > 0:
    queue.sort()
    cur = queue.pop(0)
    order.append(cur)
    v[cur] = True
    for item in range(1, 8):
        if cur in adj[item]:
            adj[item].remove(cur)
        if len(adj[item]) == 0:
            if not v[item]:
                queue.append(item)
                v[item] = True

if len(order) == 7:
    for o in order:
        print(o, end=' ')
else:
    print("Cannot complete these tasks. Going to bed.")