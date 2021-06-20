import sys
from math import sqrt


primes = [False for i in range(10000001)]

for i in range(2, 10000001):
    if not primes[i]:
        for j in range(i*2, 10000001, i):
            primes[j] = True
    else:
        continue

for i in range(5):
    ans1 = 0
    ans2 = 0
    ans3 = 0
    found = False
    n = int(sys.stdin.readline())
    if not primes[n]:
        print("%s = %s" % (n, n))
        continue
    elif n % 2 == 0:
        for x in range(2, int(n/2)):
            if not primes[x] and not primes[n-x]:
                ans1 = x
                ans2 = n-x
        print("%s = %s + %s" % (n, ans1, ans2))




