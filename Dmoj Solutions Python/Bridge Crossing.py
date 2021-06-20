import sys

names = []
line = []
m = int(sys.stdin.readline())
q = int(sys.stdin.readline())

for i in range(q):
    names.append(sys.stdin.readline().strip())
    line.append(int(sys.stdin.readline()))

dp = [1000000 for x in range(q+1)]
dp[0] = 0
reversal = [-1 for i in range(q+1)]
reversal[0] = 0


for i in range(q+1):
    k = 1
    cur = 0
    while k <= m and k + i - 1 < q:
        cur = max(cur, line[i+k-1])
        if dp[i] + cur < dp[i + k]:
            dp[i + k] = dp[i] + cur
            reversal[i + k] = k
        k += 1

p = [0 for i in range(q+1)]
l = q
h = 0
while reversal[l] != 0:
    h += 1
    p[h] = reversal[l]
    l = l - reversal[l]

count = 0
for item in reversed(p):
    if item == 0:
        continue
    else:
        for i in range(item):
            print(names[count], end = ' ')
            count += 1
        print ('')