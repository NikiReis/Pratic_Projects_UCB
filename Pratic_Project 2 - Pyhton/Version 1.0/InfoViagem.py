
import random
while True:
    origem = str(input("Digite a origem da viagem: ")).strip()
    if len(origem)<4:
        print("Origem não identificada!")
    else:
        break
while True:
    destino = str(input("Digite o destino: "))
    if len(destino)<4:
        print("Destino não identificado")
    else:
        break

preco = random.randint(200,2000)
print(preco)