import sys

pos = []
num = 0

class Speed:
    def __init__(self, time, place):
        self.time = time
        self.place = place


def compare(value):
    return value.time


n = int(sys.stdin.readline().strip())

for i in range(n):
    x, y = sys.stdin.readline().split()
    pos.append(Speed(int(x), int(y)))

pos.sort(key=compare)

for j in range(len(pos)-1):
    if num < abs((pos[j].place - pos[j+1].place)/(pos[j+1].time - pos[j].time)):
        num = abs((pos[j].place - pos[j+1].place)/(pos[j+1].time - pos[j].time))

print (num)