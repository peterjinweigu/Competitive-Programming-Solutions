import sys
import math
import time

start = time.time()
work = False
x = int(sys.stdin.readline().strip())
y = int(sys.stdin.readline().strip())

v = [False for p in range(1000001)]
queue = [[0, 0]]
room = []

for line in range(x):
    room.append(list(map(int, sys.stdin.readline().split())))

while len(queue) > 0 and work is False:
    item = queue.pop(0)
    v[room[item[0]][item[1]]] = True
    if item == [x-1, y-1]:
        work = True
        break

    c = room[item[0]][item[1]]
    inc = 1
    if c % 2 == 1:
        inc += 1
    for g in range(1, int(math.sqrt(c))+1, inc):
        end = time.time()
        print (end-start)
        if end-start >= 2.9:
            work = True
            break
        if c % g == 0:
            if [g - 1, int(c / g) - 1] == [x-1, y-1]:
                work = True
                break
            elif [int(c / g) - 1, g - 1] == [x-1, y-1]:
                work = True
                break
            else:
                if g-1 < x and int(c / g) - 1 < y:
                    if v[room[g-1][int(c/g) - 1]] is False:
                        v[room[g - 1][int(c / g) - 1]] = True
                        queue.append([g - 1, int(c / g) - 1])
                if g-1 < y and int(c / g) - 1 < x:
                    if v[room[int(c / g) - 1][g-1]] is False:
                        v[room[int(c / g) - 1][g - 1]] = True
                        queue.append([int(c / g) - 1, g - 1])


if work is True:
    print("yes")
else:
    print("no")