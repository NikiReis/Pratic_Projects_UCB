from Vars import*
from time import sleep

while True: 
    clear()
    def system(userinput,id=0):
        global new_id
        id = new_id
        match userinput:
            
            case 1:
                def showarmchair():

                    for x in range(0,len(chair_data)):
                        if (chair_data[x][0] == "C"):
                            print(f"\033[1;36m{[x][0]}\033[m",end=' ')
                        elif (chair_data[x][0] == "D"):
                            print(f"\033[1;32m{[x][0]}\033[m",end=' ')
                        else:
                            print(f"\033[1;31m{[x][0]}\033m",end=' ')
                showarmchair()
                print(f"\nDisponible: {disponible}\nReserved: {reserve_chairs}\nPuchase Chairs: {purchase_chairs}")
                sleep(5)

            case 2:

                def do_reserve():
                    nonlocal id
                    global reserve_chairs
                    global disponible
                    global reserve_amount

                    chair_number = int(input("Type the armchair that you want reserve: "))

                    if chair_number <= len(chair_data):
                        if (chair_data[chair_number][0] == "D"):
                            id += 1
                            chair_data[chair_number][0] = "R"
                            chair_data[chair_number][1] = str(id)
                            print(f"ATTENTION, YOU ONLY HAVE 10 SECONDS TO NOTE YOUR TRIP'S ID. ID: {id}")
                            sleep(10)
                            disponible -= 1
                            reserve_chairs += 1
                            reserve_amount += tripamount
                        elif ((chair_data[chair_number][0] == "C") or (chair_data[chair_number][0] == "R")):
                            print("Cannot reserve the armchair, it's already selected!")
                            sleep(3)

                    else:
                        print("Armchair not found!")
                        sleep(3)
                                
                do_reserve()

            case 3:

                def buy_trip():
                    global disponible
                    global reserve_chairs
                    global reserve_amount
                    global purchase_chairs
                    global purchase_amount
                    nonlocal id

                    chair_number = int(input("Type the armchair number that you want to buy: "))

                    if chair_number <= len(chair_data):
                        if (chair_data[chair_number][0] == "R"):
                            print("Reserva Encontrada")
                            ID = int(input("Digite o id da reserva: "))
                            if str(ID) == chair_data[chair_number][1]:
                                chair_data[chair_number][0] = "C"
                                print("Passagem comprada")
                                reserve_chairs -= 1
                                purchase_chairs += 1
                                purchase_amount += tripamount
                                reserve_amount -= tripamount
                                sleep(3)

                        elif (chair_data[chair_number][0] == "D"):
                            id += 1
                            chair_data[chair_number][0] = "C"
                            chair_data[chair_number][1] = str(id)
                            purchase_chairs += 1
                            purchase_amount += tripamount
                            disponible -= 1
                            print("Passagem comprada")
                            print(f"ATENÇÃO, VOCÊ TEM 10 SEGUNDOS PARA ANOTAR O ID SUA RESEVA. ID: {id}")
                            sleep(10)

                        elif (chair_data[chair_number][0] == "C"):
                            print("Compra não realizada!")
                            print("Esta poltrona já foi comprada para a passagem de outra pessoa!")
                            sleep(3)
                    else:
                        print("Poltrona não encontrada")
                        sleep(3)
                                    
                buy_trip()   

            case 4:

                def cancel_trip():
                    global disponible
                    global reserve_chairs
                    global reserve_amount
                    global purchase_chairs
                    global purchase_amount
                    nonlocal id
                    
                    chair_number = int(input("Digite o numero da poltrona que deseja cancelar: "))

                    if chair_number <= len(chair_data):
                        if (chair_data[chair_number][0] == "R"):
                            ID = int(input("Digite o id da passagem: "))

                            if (str(ID) == chair_data[chair_number][1]):
                                print("Passagem cancelada")
                                chair_data[chair_number][0] = "D"
                                chair_data[chair_number][1] = "0"
                                reserve_amount -= tripamount
                                reserve_chairs -= 1
                                disponible += 1
                                id -= 1 
                                sleep(3)

                            else:
                                print("ID informado não condiz com ID da poltrona!\n")
                                print("Somente o propietário pode cancelar a reserva")
                                sleep(3)

                        elif (chair_data[chair_number][0] == "C"):
                            ID = int(input("Digite o id da passagem: "))
                            if str(ID) == chair_data[chair_number][1]:
                                print("Passagem cancelada")
                                chair_data[chair_number][0] = "D"
                                chair_data[chair_number][1] = "0"
                                purchase_amount -= tripamount
                                purchase_chairs -= 1
                                disponible += 1
                                id -= 1 

                            else:
                                print("ID informado não condiz com ID da poltrona!\n")
                                print("Somente o propietário pode cancelar a compra")
                                sleep(3)

                        elif (chair_data[chair_number][0] == "D"):
                            print("Não é possível cancelar uma passagem que não tenha sido comprada / reservada")
                            sleep(3)

                    else:
                        print("Poltrona não encontrada")
                        sleep(3)
                cancel_trip()
            case out_of_range:
                print("Valor não indentificado!\nRetornando para a tela inicial\nPor favor escolha apenas os valores mostrados na tela")
                sleep(5)

        new_id = id
        return id

    while True:
        display()
        try:
            answer = int(input("\nType the desired option: "))
        except ValueError:
            print("Valor não identificado!")
            print("Por favor digite um valor válido")
            sleep(2)
            clear()
        else:
            break
    if (answer == 5):
        clear()
        print(f"Thanks for using our sistem's trip, we hope you enjoied {emoji.emojize(':blush:',':blush:')}")
        print("Here it is some data about the usage")
        print(f"{disponible} amrschairs were still avaible\n{reserve_chairs} armchairs were reserved\n{purchase_chairs} armchairs were bought")
        print(f"Total purchase amount: {purchase_amount}\nReservation total amount: {reserve_amount}")

        break
    else:
        system(answer)

