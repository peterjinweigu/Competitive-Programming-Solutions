import sys
sys.setrecursionlimit(10000)

temp = ["."] * 6
possP = [[0, 1], [0, 2], [0, 3], [1, 2], [1, 3], [2, 3]]

favN = int(sys.stdin.readline()) - 1
g = int(sys.stdin.readline())
total = 0
memo = set()

for i in range(g):
    a, b, c, d = map(int, sys.stdin.readline().split())
    a -= 1
    b -= 1
    cur = ""
    if c > d:
        cur = "W"
    elif c == d:
        cur = "T"
    else:
        cur = "L"
    for k in range(6):
        if possP[k] == [a, b] or possP[k] == [b, a]:
            temp[k] = cur


def solve(op, le):
    global total
    s = ""
    for item in op:
        s += item
    if s in memo:
        return
    if le == 6:
        pts = [0, 0, 0, 0]
        for i in range(6):
            if op[i] == "W":
                pts[possP[i][0]] += 3
            elif op[i] == "L":
                pts[possP[i][1]] += 3
            else:
                pts[possP[i][0]] += 1
                pts[possP[i][1]] += 1
        big = True
        tempo = pts[favN]
        for j in range(4):
            if j == favN:
                continue
            elif pts[j] >= tempo:
                big = False
        if big:
            total += 1
        s = ""
        for item in op:
            s += item
        memo.add(s)
        return
    for i in range(6):
        if op[i] == ".":
            op[i] = "W"
            solve(op, le + 1)
            op[i] = "L"
            solve(op, le + 1)
            op[i] = "T"
            solve(op, le + 1)
            op[i] = "."


solve(temp, len(temp) - temp.count("."))

print (total)
