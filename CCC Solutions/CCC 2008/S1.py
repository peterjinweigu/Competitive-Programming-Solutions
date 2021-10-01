class city():
    def __init__(self,name,temp):
        self.name = name
        self.temp = temp

def comp(city):
    return city.temp

cities = []
        
while True:
    name, temp= input().split()
    cities.append(city(name,int(temp)))
    if name.lower() == "waterloo":
        break

cities.sort(key= comp)

print (cities[0].name)
