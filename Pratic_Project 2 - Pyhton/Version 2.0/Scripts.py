from Vars import*
from time import sleep

while True:
    display()
    def system(userinput):
        match userinput:
            case 1:

                def showarmchair():
                    for x in range(0,len(chair_data)):
                        if chair_data[x][0] == "C":
                            print(f"\033[1;36m{[x][0]}\033[m",end=' ')
                        elif chair_data[x][0] == "D":
                            print(f"\033[1;32m{[x][0]}\033[m",end=' ')
                        else:
                            print(f"\033[1;31m{[x][0]}\033m",end=' ')
                showarmchair()

            case 2:
                def do_reserve():
                    global id
                    chair_number = int(input("Type the armchair that you want reserve: "))

                    if chair_data[chair_number][0] == "D":
                        id += 1
                        chair_data[chair_number][0] = "R"
                        chair_data[chair_number][1] = str(id)
                        increment_reserve()
                        print(f"ATTENTION, YOU ONLY HAVE 10 SECONDS TO NOTE YOUR TRIP'S ID. ID: {id}")
                        sleep(10)

                    elif chair_data[chair_number][0] == "C" or chair_data[chair_number][0] == "R":
                        print("Cannot reserve the armchair, it's already selected!")
                    else:
                        print("Archair not found!")
                                
                do_reserve()

            case 3:
                def buy_trip():
                    global id
                    chair_number = int(input("Type the armchair number that you want to buy: "))

                    if chair_data[chair_number][0] == "R":
                        print("Reserva Encontrada")
                        ID = int(input("Digite o id da reserva: "))
                        if str(ID) == chair_data[chair_number][1]:
                            chair_data[chair_number][0] = "C"
                            print("Passagem comprada")

                    elif chair_data[chair_number][0] == "D":
                        id += 1
                        chair_data[chair_number][0] = "C"
                        chair_data[chair_number][1] = str(id)
                        incremet_purchase()
                        print("Passagem comprada")
                        print(f"ATENÇÃO, VOCÊ TEM 10 SEGUNDOS PARA ANOTAR O ID SUA RESEVA. ID: {id}")
                        sleep(10)

                    elif chair_data[chair_number][0] == "C":
                        print("Compra não realizada!")
                        print("Esta poltrona já foi comprada/reservada para a passagem de outra pessoa!")
                    else:
                        print("Poltrona não encontrada")
                                    

                buy_trip()   

            case 4:
                def cancel_trip():
                    global id
                    chair_number = int(input("Digite o numero da poltrona que deseja cancelar: "))

                    if chair_data[chair_number][0] == "R":
                        ID = int(input("Digite o id da passagem: "))
                        if str(ID) == chair_data[chair_number][1]:
                            print("Passagem cancelada")
                            chair_data[chair_number][0] = "D"
                            chair_data[chair_number][1] = "0"
                            decrement_reserve()
                            id -= 1 
                        else:
                            print("ID informado não condiz com ID da poltrona!\n")
                            print("Somente o propietário pode cancelar a reserva")

                    elif chair_data[chair_number][0] == "C":
                        ID = int(input("Digite o id da passagem: "))
                        if str(ID) == chair_data[chair_number][1]:
                            print("Passagem cancelada")
                            chair_data[chair_number][0] = "D"
                            chair_data[chair_number][1] = "0"
                            decrement_purchase()
                            id -= 1 
                        else:
                            print("ID informado não condiz com ID da poltrona!\n")
                            print("Somente o propietário pode cancelar a compra")

                    elif chair_data[chair_number][0] == "D":
                        print("Não é possível cancelar uma passagem que não tenha sido comprada / reservada")
                    else:
                        print("Poltrona não encontrada")
                cancel_trip()

    answer = int(input("\nType the desired option: "))
    if answer == 5:
        break
    else:
        system(answer)
 
    
