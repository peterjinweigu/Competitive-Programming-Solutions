import sys

# :)

n = int(sys.stdin.readline().strip())

a = list(map(int, sys.stdin.readline().split()))
b = list(map(int, sys.stdin.readline().split()))
ans = 0
for j in range(n):
    ans += ((a[j] + a[j+1])/2)*b[j]
print(ans)