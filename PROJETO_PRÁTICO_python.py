from random import randint
import os

totalvalue = 0
count = 0
classification = []
armchairs = []

while True:
    print("Salumar Airlines")
    print("-"*21)


    destiny = str(input("Type the name of the destination: "))

    while len(destiny)<5 or destiny =='':
        destiny = str(input("The destination name's can't be lower than 5 caracters\nOr be empty: "))
    chairs = int(input("How many chairs does the airplane has: "))
    while chairs <90 or chairs >200:
        chairs = int(input("The plane should have at least 90 chairs and max 200: "))
    for i in range (0,chairs):
        count += 1
        armchairs.append(count)
    price = int(input("Type the value of the passage: "))
    for i in range (0,chairs):
        classification.append("D")
    os.system('cls' if os.name =='nt' else 'clear')
    print("Options")
    print("-"*7)
    print("[1] - Diponible chairs\n[2] Reserved or Confirmed boughts\n[3] Total value of the bought \n[4] Cancel a reservation")
    option = int(input("Type the desired option: "))       
    if option == 1:
        for i in range (0,chairs):
            if len(armchairs) <= chairs and classification[i] == "D":
                print(f"{classification[i]}",end='')
                print(f"{armchairs[i]:<10}\t")
    elif option == 2:
        for i in range (0,chairs):
            if len(armchairs) <= chairs and classification[i] == "R":
                if classification[i] == "R":
                    print(f"{classification[i]}",end='')
                    print(f"{armchairs[i]:<5}\t")
    elif option == 3:
        os.system("cls" if os.name == 'nt' else 'clear')
        print(totalvalue)

    endprogram = str(input("You want to buy another passage ?\nType any buttom to confirm or type 'No' to finish the program")).upper()
    if endprogram == 'NO':
        break
