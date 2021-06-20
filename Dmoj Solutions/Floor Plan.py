import sys


n = int(sys.stdin.readline())
a = int(sys.stdin.readline())
b = int(sys.stdin.readline())

floor = [["I" for i in range(b+2)]]
for i in range(a):
    line = list(sys.stdin.readline().strip())
    line.insert(0, "I")
    line.append('I')
    floor.append(line)
floor.append(["I" for i in range(b+2)])

# wow battleship!


def find(x, y, z):
    if floor[x][y] == ".":
        floor[x][y] = z
        find(x-1, y, z)
        find(x+1, y, z)
        find(x, y-1, z)
        find(x, y+1, z)


count = 0
for j in range(a+1):
    for k in range(b+1):
        if floor[j][k] == ".":
            find(j, k, str(count))
            count += 1

endC = [0 for i in range(count)]

for item in floor:
    for h in item:
        if h.isdigit():
            endC[int(h)] += 1

endC.sort()
amt = 0
for room in reversed(endC):
    if n-room < 0:
        break
    else:
        n -= room
        amt += 1

if amt == 1:
    print("1 room, %s square metre(s) left over" % n)
else:
    print("%s rooms, %s square metre(s) left over" % (amt, n))



