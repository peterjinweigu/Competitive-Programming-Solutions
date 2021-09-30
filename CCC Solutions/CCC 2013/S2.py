maximum= int(input())
rail=[]
count=0
cars= int(input())
for i in range(cars):
  rail.append(int(input()))
  if count>=4:
    rail.pop(0)
  if sum(rail)>maximum:
    break
  count+=1
print (count)
