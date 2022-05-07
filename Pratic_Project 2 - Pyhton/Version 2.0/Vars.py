import random

armschairs = random.randint(90,200)
tripvalue = random.randint(250,2000)

id = 0
chair_data = list()
disponible = armschairs
reserved_chairs = 0
purchase_chairs = 0
purchase_value = 0
reserve_value = 0

def display():
	print("[1] Mostrar Poltronas Disponíveis/Reservadas/Compradas")
	print("[2] Realizar uma Reserva")
	print("[3] Comprar uma passagem")
	print("[4] Cancelar uma Reserva/Compra")
	print("[5] Sair do Sistema")

def incremet_purchase():
        global disponible
        global purchase_value
        global purchase_chairs

        disponible -= 1
        purchase_value += tripvalue
        purchase_chairs += 1

def decrement_purchase():
    global disponible
    global purchase_value
    global purchase_chairs

    purchase_value -= tripvalue
    purchase_chairs -= 1
    disponible += 1

def increment_reserve(): 
    global reserved_chairs
    global reserve_value
    global disponible

    reserve_value += tripvalue
    reserved_chairs += 1
    disponible -= 1

def decrement_reserve():
    global reserved_chairs
    global reserve_value
    global disponible

    reserve_value -= tripvalue
    if reserve_value < 0:
        reserve_value = 0
    reserved_chairs -= 1
    disponible += 1

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


