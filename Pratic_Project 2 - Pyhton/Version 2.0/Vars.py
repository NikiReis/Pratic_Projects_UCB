import random
import os
import emoji

armschairs = random.randint(90,200)
tripamount = random.randint(250,2000)

new_id = 0
chair_data = list()
disponible = armschairs
reserve_chairs = 0
purchase_chairs = 0
purchase_amount = 0
reserve_amount = 0

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

for x in range(0,armschairs):
    chair_data.append(['D','0'])

def display():
	print("\n[1] Mostrar Poltronas Disponíveis/Reservadas/Compradas")
	print("[2] Realizar uma Reserva")
	print("[3] Comprar uma passagem")
	print("[4] Cancelar uma Reserva/Compra")
	print("[5] Sair do Sistema")

def clear():
        os.system("cls" if os.name=='nt' else "clear")

def end_of_program():
    print(f"Thanks for using our sistem's trip, we hope you enjoied {emoji.emojize(':blush:',':blush:')}")
    print("Here it is some data about the usage")
    print(f"{disponible} amrschairs were still avaible\n{reserve_chairs} armchairs were reserved\n{purchase_chairs} armchairs were bought")
    print(f"Total purchase amount: {purchase_amount}\nReservation total amount: {reserve_amount}")
