import sys

adj = [0 for i in range(10001)]
n = int(sys.stdin.readline())


def iwishihadfriends(xx, yy):
    v = [False for i in range(10001)]
    distance = -1
    while True:
        if v[xx] or xx == y:
            break
        distance += 1
        v[xx] = True
        xx = adj[xx]
    if xx == yy:
        return distance
    else:
        return -1


for i in range(n):
    a, b = map(int, sys.stdin.readline().split())
    adj[a] = b

while True:
    x, y = map(int, sys.stdin.readline().split())
    if x == 0 and y == 0:
        break
    ret = iwishihadfriends(x, y)
    if ret == -1:
        print ("No")
    else:
        print ("Yes %s" % ret)
