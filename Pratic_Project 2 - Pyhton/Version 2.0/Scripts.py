from Vars import*

chair_data[20][0] = 'R'
chair_data[20][1] = '1' 

def system(userinput,id=0):
    while True:

        match userinput:
            case 1:

                def showarmchair():
                    for x in range(0,armschairs):
                        print("D\n")
                showarmchair()

            case 2:
                def reserve():
                    nonlocal id
                    chair_number = int(input("Digite o numero da poltrona que deseja reservar: "))
                    if chair_data[chair_number][0] == 'D':
                        id += 1
                        chair_data[chair_number][0] = 'R'
                        chair_data[chair_number][1] = str(id)
                    else:
                        print("Poltrona não encontrada")
                reserve()

            case 3:
                def buy_trip():
                    chair_number = int(input("Digite o numero da poltrona que deseja comprar: "))
                    if chair_data[chair_number][0] == 'R':
                        ID = int(input("Digite o id da reserva: "))
                        if str(ID) == chair_data[chair_number][1]:
                            print("Passagem comprada")

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
                cancel_trip()
            case 5:
                break

        return id
        
    
system(5)

