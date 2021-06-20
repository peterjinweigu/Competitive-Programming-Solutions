import sys
from bisect import bisect_right

g = int(sys.stdin.readline())
p = int(sys.stdin.readline())

air = [x for x in range(g+1)]

count = 0
for i in range(p):

    num = int(sys.stdin.readline())
    minn = bisect_right(air, num)
    cur = air.pop(minn - 1)
    if cur == 0:
        break
    else:
        count += 1

print (count)
