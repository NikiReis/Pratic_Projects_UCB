"""
    Descrição do Sistema / Variáveis da função ' def interação() '

    Variáveis
        ' nreserva, ncompra e ndisponiveis ' = 
            Estas variáveis são as resposáveis por assinalar quantas reservas/compras já foram realizadas e quantidade de poltronas ainda disponiveis
            a quantidade de poltronas por padrão se inicializa com a quantidade e poltronas que o avião tem, já que ao inicializar o sistema nenhuma compra foi realizada ainda
            elas se implementam ou decrementam conforme as solicitações do usuário. 
            ' nreservas ' = quatidade de reservas realizadas; ' ncompras ' = quantidade de compras realizadas; ' ndisponiveis ' = quantidade de poltronas ainda disponíveis a serem compradas/reservadas.

             
        ' valordecompra, valordereserva e valortotal ' =
            Estas variáveis serão responsáveis por guardar o valor monetário já gasto pelo usuário e serão printadas ao final da execução.
            ' valordecompra ' = variável resposável por armazenar a valor monetário de compras já realizadas, ela se implementa quando alguém faz uma nova compra e decrementa quando o usuário cancela uma compra;
            ' valordereserva '= variável resposável por armazenar a valor monetário de reservas já realizadas, ela se implementa quando alguém faz uma nova reserva e decrementa quando o usuário confirma a compra de uma reserva 
                realizada ou quando o usuário cancela a reserva de uma passagem.
            ' valortotal ' =  variável por calcular o montante de compras e reservas, ela se incrementa quando o usuário faz uma compra e ou reserva e decrementa quando o usuário cancela uma compra e ou reserva.
        
        ' id ' =
            Esta variável será responsável por armazenar um valor de entrada do usuário quando solicitado, ela é resposável por receber o ' id de uma reserva / compra ' quando solicitado ao usuário,
            ela será como uma varável de busca, se o valor de  id informado pelo usuário existir ele poderá cancelar uma viagem e ou confirmar uma compra, ou seja, uma passagem que antes tinha sido
            apenas sido reservada passará a ser uma compra.

    Sistema

        Na exibição de poltronas disponíveis as cores serão usadas como forma de identificação do status de uma poltrona.
        Se o número da poltrona estiver verde ela estára disponível para uma compra e ou reserva ser realizada, se estiver vermelho significa que uma reserva já foi realizada naquela poltrona
        e se estiver azul significa que uma compra já foi realizada.
        Se o usuário informar um ID que não exista no campo de cancelar uma passagem ele será redirecionado para a tela inicial onde poderá tentar cancelar uma passagem novamente!

"""

from time import sleep
import random
from InfoViagem import *
import os

quantidade = random.randint(90,200)     ## variável responsável por receber a quantidade de assentos que o avião terá, que deve ser entre 90 e 200
data = list()                  ## está variável é uma das mais importante, é ela que guardará as as listas de poltronas do avião e ID de compra/reserva de cada poltrona

for x in range(0,quantidade):   ## esta estrutura de repetição tem a importacia de criar uma repetição do tamanho da quantidade de poltronas
    status = ['D','0']          ## onde está variável receberá este valor padrão, como se fosse os dados de cada poltrona 'D' == 'disponível e '0' é ID de inicio já que nenhuma compra foi realizada ainda
    data.append(status)         ## array responsável por guardar os dados das poltronas e que posteriormente servirá de ponte para acessar dados de uma poltrona em especifico
    
idcr = 0    ## inicialização da variável que se alto implementa e decrementa e a responsável por identificação de cada compra/reserva


def opcoes():   ## função simples para printar o menu de interação 

    print(f"\nOrigem: {origem}")
    print(f"Destino: {destino}")
    print("Menu de Opções")
    print("[1] Visualizar Poltronas Disponíveis\n[2] Comprar Uma Passagem")
    print("[3] Realizar Uma Reserva\n[4] Cancelar Uma Compra ou Reserva\n[0] Sair da Programa")

def interacao(): ## função que guarda toda funcionalidade que o sistema deve ter 

    global quantidade
    global data
    global idcr

    ndisponiveis = quantidade
    nreservas = 0 
    ncompras = 0
    valordecompra = 0
    valordereserva = 0 
    valortotal = 0

    while True:
        
    
        sleep(5)
        os.system('cls' if os.name=='nt' else 'clear')

        opcoes()

        option = int(input("Digite a opção desejada: "))

        if option == 1:

            print(f"Total de poltronas: {quantidade}")
            print("\nPoltronas Disponíveis")
            for i in range(0,len(data)):
                if data[i][0] == 'D':
                    print(f'\033[1;32m{i}\033[m',end=' ')
                elif data[i][0] == 'C':
                    print(f"\033[1;36m{i}\033[m",end=' ')
                else:
                    print(f"\033[1;31m{i}\033[m",end=' ')
            print(f"\nDisponíveis: {ndisponiveis}\nReservadas: {nreservas}\nCompradas: {ncompras}")
                    
                
        elif option == 2:

            poltrona = int(input("Em qual poltrona deseja comprar a passagem ? "))

            if data[poltrona][0] == 'D':
                idcr += 1
                data[poltrona][0] = 'C'
                data[poltrona][1] = str(idcr)

                valordcompra += preco
                valortotal += preco
                ncompras += 1

                if ndisponiveis <= 0:
                    ndisponiveis = 0
                else:
                    ndisponiveis -= 1

                print("Sua compra foi realizada")
                print(f"Anote o ID da sua compra/reserva: \'{idcr}\'")

            elif data[poltrona][0] == 'R':

                print("Uma reserva foi encontrda nessa poltrona")
                id = str(input("Digite ID e confirme ser o dono da reserva:  "))

                if data[poltrona][1] == id:
                    print("Compra realizada!")
                    data[poltrona][0] = 'C'
                    valordecompra += preco
                    valortotal += preco
                    valordereserva -= preco
                    ncompras+=1

                    if nreservas <0:
                        nreservas = 0
                    else:
                        nreservas -= 1
                else:
                    print("ID informado não confere com o ID da reserva\nCompra não realizada!")
            else:
                print("Uma compra já foi realizada nessa poltrona\nPor favor selecione uma poltrona disponível!")
                
        elif option == 3:

            poltrona = int(input("Em qual poltrona deseja reservar a passagem ? "))

            if data[poltrona][0] == 'D':

                idcr += 1
                data[poltrona][0] = 'R'
                data[poltrona][1] = str(idcr)
                valortotal += preco
                valordereserva += preco
                nreservas += 1

                if ndisponiveis <= 0:
                    ndisponiveis = 0
                else:
                    ndisponiveis -= 1

                print("Reserva realizada!")
                print(f"Anote o ID da sua compra/reserva: \'{idcr}\'")

            elif data[poltrona][0] == 'R' or data[poltrona][0] == 'C':
                print("Uma reserva ou compra já foi realizada nessa poltrona\nPor favor selecione uma poltrona disponível!")

        elif option == 4:

            id = str(input("Digite o ID da qual deseja cancelar a passagem: "))

            for x in range(0,len(data)):
                if id in data[x][1] and data[x][0] == 'R':

                    print("Reserva Cancelada")
                    data[x][0]= 'D'
                    data[x][1] = '0'
                    idcr -= 1
                    valordereserva -= preco
                    valortotal -= preco
                    if nreservas <= 0:
                        nreservas = 0
                    else:
                        nreservas -=1
                    ndisponiveis +=1
                    break

                elif id in data[x][1] and data[x][0] == 'C':
                    print("Reserva Cancelada")
                    data[x][0]= 'D'
                    data[x][1] = '0'
                    idcr -= 1
                    valordecompra -= preco
                    valortotal -= preco
                    if ncompras <= 0:
                        ncompras = 0
                    else:
                        ncompras -= 1
                    ndisponiveis +=1
                    break               

        elif option == 0:

            print(f"\nObrigado(a) por utilizar o nosso sistema! :)) ")
            print("Dados da utilização!")
            print(f"Valor total de compra e reserva: R$ \033[1;35m{valortotal}\033[m\nValor das reservas: R$ \033[1;31m{valordereserva}\033[m\nValor das compras: R$ \033[1;36m{valordecompra}\033[m")
            print(f"\033[1;36m{ncompras}\033[m passagens foram compradas\n\033[1;31m{nreservas}\033[m passagens foram reservadas e\n\033[1;32m{ndisponiveis}\033[m poltronas ainda ficaram disponíveis para compra ou reserva")
            break
