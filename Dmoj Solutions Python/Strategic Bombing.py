import sys

roads = [[] for i in range(26)]

allRoads = []

while True:
    r = sys.stdin.readline().strip()
    if r == "**":
        break
    roads[ord(r[0]) - 65].append(ord(r[1])-65)
    roads[ord(r[1])-65].append(ord(r[0])-65)
    allRoads.append([ord(r[0])-65, ord(r[1])-65])

total = 0

while len(allRoads) > 0:
    queue = [0]
    v = [False for i in range(26)]
    curr = allRoads.pop(0)
    reached = False
    while len(queue) > 0 and reached is False:
        n = queue.pop(0)
        v[n] = True
        for node in roads[n]:
            if v[node] is False:
                if [n, node] != curr and [node, n] != curr:
                    if node == 1:
                        reached = True
                        break
                    v[node] = True
                    queue.append(node)
    if not reached:
        print(chr(curr[0]+65) + chr(curr[1]+65))
        total += 1
print("There are %s disconnecting roads." % total)
