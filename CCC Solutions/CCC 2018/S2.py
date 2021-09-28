n= int(input())
Table = [[0 for a in range(n)] for b in range(n)]
x= 0
def swap(x,y):
  del(Table[x][0])
  Table[x].append(y)  
while (x!= n):
  arr= list(map(int,input().split()))
  num= 0
  while (num!= len(arr)):
    swap(x,arr[num])
    num+=1
  x+=1
def printarr(arr):
  for row in arr:
    for element in row:
      print(element ,end=' ')
    print ('')
def rotate(table):
  if len(table)==1:
    print (table)
  else:
    tableN= [x[:] for x in table]
    a= len(table)
    for x in range(0,a):
      for y in range (0,a):
        tableN[y][a-1-x]= table[x][y]
    if tableN[0][0]<tableN[0][1] and tableN[0][0]<tableN[1][0]:
      printarr(tableN)
    else:
      rotate(tableN)
rotate(Table)
