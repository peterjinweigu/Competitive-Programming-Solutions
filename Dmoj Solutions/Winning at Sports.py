import sys
n = int(sys.stdin.readline())
sieve = [[0 for i in range(2010)] for i in range(2010)]

for i in range(2010):
    for j in range(2010):
        if j < i:
            if j == 0:
                sieve[i][j] = 1
            elif i == j + 1:
                sieve[i][j] = sieve[i][j-1] % 1000000007
            else:
                sieve[i][j] = (sieve[i-1][j] % 1000000007 + sieve[i][j-1] % 1000000007) % 1000000007

for i in range(1, n+1):
    x, y = map(int, sys.stdin.readline().split("-"))
    print("Case #%s: %s %s " % (i, sieve[x][y], sieve[y+1][y]))

