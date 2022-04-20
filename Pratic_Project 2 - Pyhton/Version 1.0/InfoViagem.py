
import random

# a estrutura de repetição abaixo será responsável por criar um looping onde a varável chamada 'origem' responsável por simular a origem
# de uma viagem, jamais poderá ter um tamanho menor do que 4 caracteres e nem ser preenchida com espaços, isso vale também para a outra 
# estrutura de repetição, que também tem a mesma função, mas dessa vez com a variável 'destino' responsável por simular o destino de uma viagem

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

## assim como a quantidade de poltronas do avião que será um valor aleatório entre 90 e 200, a variável também receberá um valor aleatório
## mas dessa vez entre 200 e 2000 para simular o valor da passagem na hora da utilização do sistema.
preco = random.randint(200,2000)
