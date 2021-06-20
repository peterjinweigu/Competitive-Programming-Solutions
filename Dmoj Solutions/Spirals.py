import math

start = int(input())
end = int(input())
table = [['00' for i in range(round(math.sqrt(end - start + 1)))] for s in range(math.ceil(math.sqrt(end - start + 1)))]
x = (math.ceil(round(math.sqrt(end - start + 1)) / 2)) - 1
y = (math.ceil(math.ceil(math.sqrt(end - start + 1)) / 2)) - 1
table[y][x] = start
direction = 0
speed = 0
on = True
while on is True:
    speed += 1
    for a in range(2):
        for b in range(speed):
            if direction == 0:
                if start < end:
                    y += 1
                    start += 1
                    table[y][x] = start
                else:
                    on = False
                    break
            elif direction == 1:
                if start < end:
                    x += 1
                    start += 1
                    table[y][x] = start
                else:
                    on = False
                    break
            elif direction == 2:
                if start < end:
                    y -= 1
                    start += 1
                    table[y][x] = start
                else:
                    on = False
                    break
            elif direction == 3:
                if start < end:
                    x -= 1
                    start += 1
                    table[y][x] = start
                else:
                    on = False
                    break
        if direction < 3:
            direction += 1
        else:
            direction = 0
        if on is False:
            break

for h in table:
    for j in h:
        if j == '00':
            print('  ', end=' ')
        else:
            if j < 10:
                print(' ' + (str(j)), end=' ')
            else:
                print(j, end=' ')
    print('')