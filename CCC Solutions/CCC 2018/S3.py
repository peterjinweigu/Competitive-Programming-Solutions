import sys
sys.setrecursionlimit(10000)

optimusPrime = []
n, m = map(int, sys.stdin.readline().split())
notP = False
di = ["U", "R", "D", "L"]
start = []
sp = []

for i in range(n):
    optimusPrime.append(list(sys.stdin.readline().strip()))

for i in range(n):
    for j in range(m):
        if optimusPrime[i][j] == "S":
            start.append(i)
            start.append(j)
        if optimusPrime[i][j] == "C":
            count = 1
            count1 = 1
            count2 = 1
            count3 = 1
            while True:
                if optimusPrime[i][j-count] != 'W':
                    if optimusPrime[i][j-count] not in di and optimusPrime[i][j-count] != "C":
                        if optimusPrime[i][j-count] != "S":
                            optimusPrime[i][j-count] = 'X'
                        else:
                            notP = True
                    count += 1
                if optimusPrime[i][j+count1] != 'W':
                    if optimusPrime[i][j+count1] not in di and optimusPrime[i][j+count1] != "C":
                        if optimusPrime[i][j+count1] != "S":
                            optimusPrime[i][j+count1] = 'X'
                        else:
                            notP = True
                    count1 += 1
                if optimusPrime[i-count2][j] != 'W':
                    if optimusPrime[i-count2][j] not in di and optimusPrime[i-count2][j] != "C":
                        if optimusPrime[i-count2][j] != "S":
                            optimusPrime[i-count2][j] = 'X'
                        else:
                            notP = True
                    count2 += 1
                if optimusPrime[i+count3][j] != 'W':
                    if optimusPrime[i+count3][j] not in di and optimusPrime[i+count3][j] != "C":
                        if optimusPrime[i+count3][j] != "S":
                            optimusPrime[i+count3][j] = 'X'
                        else:
                            notP = True
                    count3 += 1
                if optimusPrime[i+count3][j] == 'W' and optimusPrime[i-count2][j] == 'W' and optimusPrime[i][j-count] == 'W' and optimusPrime[i][j+count1] == 'W':
                    break


def check(xx, yy, d):
    if optimusPrime[xx][yy] == "A" or optimusPrime[xx][yy] == "W" or optimusPrime[xx][yy] == "X" or optimusPrime[xx][yy] == "C" :
        sp.append(0)
        sp.append(0)
    elif optimusPrime[xx][yy] == "U":
        optimusPrime[xx][yy] = "A"
        check(xx-1,yy,"U")
    elif optimusPrime[xx][yy] == "D":
        optimusPrime[xx][yy] = "A"
        check(xx+1,yy,"D")
    elif optimusPrime[xx][yy] == "R":
        optimusPrime[xx][yy] = "A"
        check(xx,yy+1,"R")
    elif optimusPrime[xx][yy] == "L":
        optimusPrime[xx][yy] = "A"
        check(xx,yy-1,"L")
    elif optimusPrime[xx][yy] == ".":
        sp.append(xx)
        sp.append(yy)
    else:
        sp.append(0)
        sp.append(0)


start.append(0)
queue = [start]

while len(queue) > 0:
    cur = queue.pop(0)
    x = cur[0]
    y = cur[1]
    w = cur[2]
    if optimusPrime[x][y] == "." or optimusPrime[x][y] == "S":
        optimusPrime[x][y] = str(w)
        queue.append([x+1, y, w+1])
        queue.append([x-1, y, w+1])
        queue.append([x, y+1, w+1])
        queue.append([x, y-1, w+1])
    elif optimusPrime[x][y] in di:
        check(x, y, optimusPrime[x][y])
        nx = sp[0]
        ny = sp[1]
        if nx != 0 and ny != 0:
            optimusPrime[nx][ny] = str(w)
            queue.append([nx + 1, ny, w + 1])
            queue.append([nx - 1, ny, w + 1])
            queue.append([nx, ny + 1, w + 1])
            queue.append([nx, ny - 1, w + 1])
        sp.clear()


if not notP:
    for o in optimusPrime:
        for p in o:
            if p == "X" or p == ".":
                print(-1)
            elif p.isdigit() and int(p) != 0:
                print(p)
else:
    for o in optimusPrime:
        for p in o:
            if p == "X" or p == ".":
                print(-1)
            elif p.isdigit() and int(p) != 0:
                print(-1)
