stats = []
count = 0
for i in range(4): stats.append(int(input()))
while stats[0] > 0:
    for i in range(1,4):
        stats[i] += 1
        if stats[i] % 35 == 0  and i == 1:
            stats[0] += 30
        if stats[i] % 100 == 0 and i == 2:
            stats[0] += 60
        if stats[i] % 10 == 0 and i == 3:
            stats[0] += 9
        count += 1
        stats[0] -= 1
        if stats[0] <= 0:
            break

print ("Martha plays %s times before going broke." % (str(count)))
