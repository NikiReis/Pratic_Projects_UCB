from random import randint
import os
print("Salumar Airlines")
print("-"*21)

count = 0
classification = []
armchairs = []

destiny = str(input("Type the name of the destination: "))

while len(destiny)<5 or destiny =='':
    destiny = str(input("The destination name's can't be lower than 5 caracters\nOr be empty: "))
chairs = int(input("How many chairs does the airplane has: "))
while chairs <90 or chairs >200:
    chairs = int(input("The plane should have at least 90 chairs and max 200: "))
for i in range (0,chairs):
        count += 1
        armchairs.append(count)
for i in range (0,chairs):
        classification.append("D")
os.system('cls' if os.name =='nt' else 'clear')
print("Options")
print("-"*7)
option = int(input("[1] - Diponible chairs: "))
if option == 1:
    for i in range (0,chairs):
            if len(armchairs) <= chairs and classification[i] == "D":
                print(f"{classification[i]}",end='')
                print(f"{armchairs[i]:<10}\t")
