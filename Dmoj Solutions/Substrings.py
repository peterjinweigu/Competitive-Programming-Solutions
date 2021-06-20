import sys

n = int(sys.stdin.readline())

for i in range(n):
    count = 0
    sa = []
    s = sys.stdin.readline().strip()
    for j in range(len(s)):
        sa.append(s[j:len(s)])
    sa.sort()
    count += len(sa[0])
    for j in range(1, len(s)):
        lcp = 0
        for a in range(min(len(sa[j]), len(sa[j-1]))):
            if sa[j][a] != sa[j-1][a]:
                break
            lcp += 1
        count += len(sa[j]) - lcp
    print(count + 1)