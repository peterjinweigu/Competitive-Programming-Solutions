import sys
m = int(sys.stdin.readline())
mount = []
for i in range(m):
    mount.append(int(sys.stdin.readline()))

while True:
    c = int(sys.stdin.readline())
    if c == 99:
        num = int(sys.stdin.readline())-1
        p = int(sys.stdin.readline())
        o = mount[num]
        if num == len(mount)+1:
            mount.append(mount[num] * (p/100))
        else:
            mount.insert(num,(o * (p/100)))
        mount[num+1] = (o * ((100 - p) / 100))
    elif c == 88:
        num = int(sys.stdin.readline())-1
        mount[num+1] = mount[num]+mount[num+1]
        mount.pop(num)
    else:
        break
for j in mount:
    print (int(j), end= ' ')