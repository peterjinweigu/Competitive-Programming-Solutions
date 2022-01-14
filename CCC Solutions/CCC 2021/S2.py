import sys

# :)

m = int(sys.stdin.readline().strip())
n = int(sys.stdin.readline().strip())
k = int(sys.stdin.readline().strip())
row = [1 for j in range(m+1)]
col = [1 for _ in range(n+1)]

for j in range(k):
    t, h = sys.stdin.readline().split()
    if t == "C":
        col[int(h)] *= -1
    else:
        row[int(h)] *= -1
r = 0
c = 0
ans = 0
for j in range(m+1):
    if row[j] == -1:
        r += 1
        ans += n - (2*c)
for i in range(n+1):
    if col[i] == -1:
        c += 1
        ans += m - (2*r)

print(ans)
