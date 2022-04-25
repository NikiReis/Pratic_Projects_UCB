import random

armschairs = random.randint(90,200)
tripvalue = random.randint(250,2000)

chair_data = list()

for x in range(1,armschairs):
    chair_data.append(['D','0'])

def trip_informations(): 
    while True:
        origin = str(input("Type the origin name: ")).strip()
        if len(origin)<=4:
            print("Origin not found!")
            print("Plese, try again!\n")
        else:
            break
    while True:
        destiny = str(input("Type the destiny name: ")).strip()
        if len(destiny)<=4:
            print("Origin not found!")
            print("Plese, try again!\n")
        else:
            break

trip_informations()