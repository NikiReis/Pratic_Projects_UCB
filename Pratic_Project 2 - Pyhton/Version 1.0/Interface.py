from hmac import compare_digest
import os
import random
from InfoViagem import *
quantidade = random.randint(90,200)
data = list()

for x in range(0,quantidade):
    status = ['D','0']
    data.append(status)
    
idcr = 0



def opcoes():
    print(f"Origem: {origem}")
    print(f"Destino: {destino}")
    print("Menu de Opções")
    print("[1] Visualizar Poltronas Disponíveis\n[2] Comprar Uma Passagem")
    print("[3] Realizar Uma Reserva\n[4] Cancelar Uma Compra ou Reserva\n[0] Sair da Programa")

def menu():
    valordcompra = 0
    valordreserva = 0 
    valortotal = 0
    while True:
        global quantidade
        global data
        global idcr

      
        opcoes()
        option = int(input("Digite a opção desejada: "))

        if option == 1:
            print(f"Total de poltronas: {quantidade}")
            print("\nPoltronas Disponíveis")
            for i in range(0,quantidade):
                print(f'{data[i]}\t\t')
                
        elif option == 2:

            poltrona = int(input("Em qual poltrona deseja comprar a passagem ? "))

            if data[poltrona][0] == 'D':

                idcr += 1
                data[poltrona][0] = 'C'
                data[poltrona][1] = str(idcr)

                valordcompra += preco
                valortotal += preco

            if data[poltrona][0] == 'R':

                data[poltrona][0] = 'C'
                valordcompra += preco
                valortotal += preco
                valordreserva -= preco

        elif option == 3:

            poltrona = int(input("Em qual poltrona deseja reservar a passagem ? "))
            if data[poltrona][0] == 'D':
                idcr += 1
                data[poltrona][0] = 'R'
                data[poltrona][1] = str(idcr)
                valortotal += preco
                valordreserva += preco

        elif option == 4:

            id = str(input("Digite o ID da qual deseja cancelar a passagem: "))
            for x in range(0,len(data)):
                if id in data[x][1] and data[x][0] == 'R':

                    print("Reserva Cancelada")
                    data[x][0]= 'D'
                    data[x][1] = '0'
                    idcr -= 1
                    valordreserva -= preco
                    valortotal -= preco
                    break
                elif id in data[x][1] and data[x][0] == 'C':
                    print("Reserva Cancelada")
                    data[x][0]= 'D'
                    data[x][1] = '0'
                    idcr -= 1
                    valordcompra -= preco
                    valortotal -= preco

        elif option == 0:
            
            break

