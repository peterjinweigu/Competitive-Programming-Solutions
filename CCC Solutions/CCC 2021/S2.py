import sys

# :)
f = []
total = 0
stackF = 0
stackB = 0


def cmp(p):
    return -p[0]


n = int(sys.stdin.readline().strip())
for j in range(n):
    x, y, z = map(int, sys.stdin.readline().split())
    f.append([x+z, y, 1])
    if x-z > 0:
        f.append([x-z, y, -1])
        total += (x-z)*y
        stackB += y

f.sort(key=cmp)
last = 0

ans = sys.maxsize
while len(f) > 0:
    ans = min(total, ans)
    cur = f.pop(-1)
    if cur[2] == -1:
        total -= stackB*(cur[0] - last)
        total += stackF * (cur[0] - last)
        last = cur[0]
        stackB -= cur[1]

    else:
        total -= stackB * (cur[0] - last)
        total += stackF * (cur[0] - last)
        stackF += cur[1]
        last = cur[0]
print(ans)
