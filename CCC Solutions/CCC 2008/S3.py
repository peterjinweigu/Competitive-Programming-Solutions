import sys
from collections import deque

t = int(sys.stdin.readline().strip())

for j in range(t):
    x = int(sys.stdin.readline().strip())
    y = int(sys.stdin.readline().strip())
    grid = []
    q = deque()
    ans = [[sys.maxsize for p in range(y)] for h in range(x)]
    for i in range(x):
        line = list(sys.stdin.readline().strip())
        grid.append(line)
    ans[0][0] = 1
    q.append([0, 0])
    while len(q) > 0:
        cur = q.popleft()
        sx = cur[0]
        sy = cur[1]
        mode = 0
        if grid[sx][sy] == "+":
            mode = 1
        if grid[sx][sy] == "-":
            mode = 2
        if grid[sx][sy] == "|":
            mode = 3
        if sx < x-1:
            if mode == 1 or mode == 3:
                if ans[sx + 1][sy] > ans[sx][sy] + 1 and grid[sx + 1][sy] != "*":
                    ans[sx + 1][sy] = ans[sx][sy] + 1
                    q.append([sx + 1, sy])
        if sx > 0:
            if mode == 1 or mode == 3:
                if ans[sx - 1][sy] > ans[sx][sy] + 1 and grid[sx - 1][sy] != "*":
                    ans[sx - 1][sy] = ans[sx][sy] + 1
                    q.append([sx - 1, sy])
        if mode == 1 or mode == 2:
            if sy < y - 1:
                if ans[sx][sy + 1] > ans[sx][sy] + 1 and grid[sx][sy + 1] != "*":
                    ans[sx][sy + 1] = ans[sx][sy] + 1
                    q.append([sx, sy+1])
            if sy > 0:
                if ans[sx][sy - 1] > ans[sx][sy] + 1 and grid[sx][sy - 1] != "*":
                    ans[sx][sy - 1] = ans[sx][sy] + 1
                    q.append([sx, sy-1])
    if ans[x-1][y-1] == sys.maxsize:
        print(-1)
    else:
        print(ans[x-1][y-1])
