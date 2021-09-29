j= int(input())
a= int(input())
s= ['S','M','L']
sizes= []
fit=0
for i in range(0,j,1):
  size= input()
  sizes.append(size)
for i in range(0,a,1):
  x,y= (input().split())
  try:
    if s.index(sizes[int(y)-1])>= s.index(x):
      fit+=1
      sizes[int(y)-1]= ('T')
  except:
    continue
print (fit)
