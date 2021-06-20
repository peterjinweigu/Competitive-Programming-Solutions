import sys
from itertools import permutations

n = int(sys.stdin.readline().strip())
choice = [0, 0, 0, 0]
mx = 0


def solve(lvl, cur):
    global choice
    global mx
    if lvl >= 4:
        if cur <= 24:
            mx = max(mx, cur)
        return
    solve(lvl+1, cur + choice[lvl])
    solve(lvl+1, cur - choice[lvl])
    solve(lvl+1, cur * choice[lvl])
    if cur % choice[lvl] == 0 and choice[lvl] != 0:
        solve(lvl+1, cur/choice[lvl])
    if lvl == 2:
        solve(lvl+2, cur * (choice[lvl]+choice[lvl+1]))
        solve(lvl+2, cur * (choice[lvl]-choice[lvl+1]))
        solve(lvl+2, cur * (choice[lvl]*choice[lvl+1]))
        solve(lvl+2, cur + (choice[lvl]+choice[lvl+1]))
        solve(lvl+2, cur + (choice[lvl]-choice[lvl+1]))
        solve(lvl+2, cur + (choice[lvl]*choice[lvl+1]))
        solve(lvl+2, cur - (choice[lvl]+choice[lvl+1]))
        solve(lvl+2, cur - (choice[lvl]-choice[lvl+1]))
        solve(lvl+2, cur - (choice[lvl]*choice[lvl+1]))
        if choice[lvl + 1] != 0:
            if choice[lvl] % choice[lvl+1] == 0:
                solve(lvl+2, cur * (choice[lvl]/choice[lvl+1]))
                solve(lvl + 2, cur + (choice[lvl] / choice[lvl + 1]))
                solve(lvl + 2, cur - (choice[lvl] / choice[lvl + 1]))
                if cur % (choice[lvl]/choice[lvl+1]) == 0:
                    solve(lvl + 2, cur / (choice[lvl] / choice[lvl + 1]))
        if (choice[lvl]+choice[lvl+1]) != 0:
            if cur % (choice[lvl]+choice[lvl+1]) == 0:
                solve(lvl + 2, cur / (choice[lvl] + choice[lvl + 1]))
        if (choice[lvl]-choice[lvl+1]) != 0:
            if cur % (choice[lvl]-choice[lvl+1]) == 0:
                solve(lvl + 2, cur / (choice[lvl] - choice[lvl + 1]))
        if (choice[lvl]*choice[lvl+1]) != 0:
            if cur % (choice[lvl]*choice[lvl+1]) == 0:
                solve(lvl + 2, cur / (choice[lvl] * choice[lvl + 1]))


for j in range(n):
    mx = 0
    a = []
    for i in range(4):
        a.append(int(sys.stdin.readline().strip()))
    b = set(permutations(a))
    for i in b:
        choice = list(i)
        solve(1, choice[0])
    print(int(mx))