from Vars import*
from time import sleep

chair_data[20][0] = 'R'
chair_data[20][1] = '1' 

def system(userinput,id=0):
    while True:

        match userinput:
            case 1:

                def showarmchair():
                    for x in range(0,len(chair_data)):
                        if chair_data[x][0] == "D":
                            print(f"\033[1;32m{x}\033[m",end=' ')
                        elif chair_data[x][0] == "C":
                            print(f"\033[1;36{x}\033[m",end=' ')
                        else:
                            print(f"\033[1;31m{x}\033[m",end=' ')
                showarmchair()

            case 2:
                def do_reserve():
                    nonlocal id
                    chair_number = int(input("Type the armchair that you want reserve: "))

                    if chair_data[chair_number][0] == 'D':
                        id += 1
                        chair_data[chair_number][0] = 'R'
                        chair_data[chair_number][1] = str(id)
                        print(f"ATTENTION, YOU ONLY HAVE 10 SECONDS TO NOTE YOUR TRIP'S ID. ID: {id}")
                        sleep(10)

                    elif chair_data[chair_number][0] == 'C' or chair_data[chair_number][0] == 'R':
                        print("Cannot reserve the armchair, it's already selected!")
                    else:
                        print("Archair not found!")
                    
                do_reserve()

            case 3:
                def buy_trip():
                    nonlocal id
                    chair_number = int(input("Type the armchair number that you want reserve: "))

                    if chair_data[chair_number][0] == 'R':
                        print("Reserva Encontrada")
                        ID = int(input("Digite o id da reserva: "))
                        if str(ID) == chair_data[chair_number][1]:
                            chair_data[chair_number][0] = 'C'
                            print("Passagem comprada")

                    elif chair_data[chair_number][0] == 'D':
                        id += 1
                        chair_data[chair_number][0] = 'C'
                        chair_data[chair_number][1] = str(id)
                        print("Passagem comprada")
                        print(f"ATENÇÃO, VOCÊ TEM 10 SEGUNDOS PARA ANOTAR O ID SUA RESEVA. ID: {id}")
                        sleep(10)

                    elif chair_data[chair_number][0] == 'C':
                        print("Compra não realizada!")
                        print("Esta poltrona já foi comprada/reservada para a passagem de outra pessoa!")
                    else:
                        print("Poltrona não encontrada")
                        

                buy_trip()   

            case 4:
                def cancel_trip():
                    nonlocal id
                    chair_number = int(input("Digite o numero da poltrona que deseja comprar: "))

                    if chair_data[chair_number][0] == 'R' or chair_data[chair_number][0] == 'C':
                        ID = int(input("Digite o id da passagem: "))
                        if str(ID) == chair_data[chair_number][1]:
                            print("Passagem cancelada")
                            chair_data[chair_number][0] = 'D'
                            chair_data[chair_number][1] = '0'
                            id -= 1 
                        else:
                            print("ID informado não condiz com ID da poltrona!\n")
                            print("Somente o propietário pode cancelar a reserva / compra")
                    elif chair_data[chair_number][0] == 'D':
                        print("Não é possível cancelar uma passagem que não tenha sido comprada / reservada")
                    else:
                        print("Poltrona não encontrada")
                cancel_trip()
            case 5:
                break

        return id
        
    
system(1)


