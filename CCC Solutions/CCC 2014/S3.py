import sys
trial = int(sys.stdin.readline().strip())

for att in range(trial):
    state = True
    n = int(sys.stdin.readline().strip())
    stack = [0]
    otherStack= [0]
    count = 1
    for x in range(n):
        temp = int(sys.stdin.readline().strip())
        stack.append(temp)
    while count != n:
        if len(stack) == 0:
            state = False
            break
        if stack[-1] == count:
            count += 1
            stack.pop(-1)
        elif otherStack[-1] == count:
            count += 1
            otherStack.pop(-1)
        else:
            otherStack.append(stack[-1])
            stack.pop(-1)
    if state is True:
        print("Y")
    else:
        print("N")
