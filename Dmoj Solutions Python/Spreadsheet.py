import sys

p = [[-1 for j in range(9)] for i in range(10)]
adj = []

for i in range(10):
    adj.append(list(sys.stdin.readline().split()))

c = True
while c:
    c = False
    for i in range(10):
        for j in range(9):
            v = 0
            x = 0
            s = list(adj[i][j].split("+"))
            while len(s) > 0 and x != -1:
                f = 0
                cur = s.pop()
                if cur.isdigit():
                    x = int(cur)
                else:
                    x = p[ord(cur[0]) - 65][int(cur[1]) - 1]
                if x == -1:
                    v = -1
                else:
                    v += x
            if p[i][j] != v:
                c = True
                p[i][j] = v

for i in p:
    for j in i:
        if j >= 0:
            print(str(j), end=' ')
        else:
            print("*", end=' ')
    print('')

