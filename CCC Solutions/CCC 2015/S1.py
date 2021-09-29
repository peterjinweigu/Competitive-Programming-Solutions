amount=int(input())
income=[]
for i in range(amount):
  num= int(input())
  if num>0:
    income.append(num)
  elif num==0:
    income.pop()
s=0
for i in income:
  s+=i
print (s)
