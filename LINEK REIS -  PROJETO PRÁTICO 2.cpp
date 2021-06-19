// Aluno: LINEK FERREIRA ALMEIDA DOS REIS
// MATRÍCULA: UC21106202
// CURSO: ENGENHARIA DE SOFTWARE
// INSTITUIÇÃO DE ENSINO: UNIVERSIDADE CATÓLICA DE BRASÍLIA
// DATA: 15/06/2021

// Inclusão de bibliotecas para o funcionamento do programa

#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>



// Função para o reconhecimento do ' textcolor(); ' pertencente a biblioteca conio.h
// Sem essa função não há a alteração das cores das strings

void textcolor(int iColor){
 HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
 CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
 BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
 bufferInfo.wAttributes &= 0x00F0;
 SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

// Função principal
int main(){
	
int idreserva=0,vercodigo;	
char opcao,opcao2,resposta[3],destino[20],classificacao[10][20];
int valor,i=0,j=0,quantidade,contador,poltronas[10][20];
int cadeira,codigos[10][20];
int codvaga,vlrcompra,idade,quantidadecompra=0,quantidadereserva=0;

  
	
	setlocale(LC_ALL,"Portuguese");			 // Implementação do reconhecimento das acentuações da língua portuguesa
	
	printf("---------------------\n");
	printf("SALUMAR LINHAS AÉREAS\n");
	printf("---------------------\n");
	
	printf("Digite o nome do destino: ");
		scanf("%s",&destino);  					// Leitura de dados
		
	while(strlen(destino)<5){					// estrutura de repetição caso as condições não tenham sido atendidas
		
		printf("Destino Inválido!\nDigite o destino desejado: ");
			scanf("%s",&destino);
			
	}
	
	printf("Digite o valor da passagem: ");
		
		while(scanf("%d",&valor)!=1){			// estrutura de repetição caso as condições não tenham sido atendidas
			
			printf("Digite apenas valores inteiros: ");
				while(getchar()!='\n');
				
		}
		
		printf("Quantidade de poltronas no avião: ");
			while(scanf("%d",&quantidade)!=1){				// estrutura de repetição caso as condições não tenham sido atendidas
				printf("Digite apenas valores inteiros: ");
					while(getchar()!='\n');
			}
			
			if(quantidade>200 || quantidade<90){			// Estrutura condicional para a quantidade de poltronas
				while(quantidade>200 || quantidade<90){
					printf("\nQuantidade máxima atingida\nou quantidade mínima não alcançada\n");
					printf("Quantidade de poltronas no avião: ");
					scanf("%d",&quantidade);
				}
			}
		
				
		for(i=0;i<10;i++){									// estrutura de repetição para a classificação das poltronas
						for(j=0;j<20;j++){
							contador++;
							poltronas[i][j] = contador;
						}
					}
		for(i=0;i<10;i++){
						for(j=0;j<20;j++){
							classificacao[i][j]='D';
						}
					}
						
	
		
while(strcmp(resposta,"sim")!=1){	// estrutura de repetição para o programa continuar funcionando até caso o usuário decida o contrário
	
	idreserva = idreserva + 1;
		fflush(stdin);
		
		printf("\n-------------------------\n");
		printf("      MENU DE OPÇÕES     \n");
		printf("-------------------------\n");
		printf("[D] Poutronas disponíveis\n");
		printf("[C] Compras realizadas\n");
		printf("[R] Reservar poltrona\n");
		printf("[E] Cancelar Reservas\n");
		printf("[I] Instruções\n");
		printf("[X] Encerrar Software\n");
		printf("Digite a opção desejada: ");
		
				while(scanf("%c",&opcao)!=1){
					
					printf("Opção inválida\nDigite a opção desejada: ");
					while(getchar()!='\n');
					opcao = toupper(opcao);
						
				}
				
				opcao = toupper(opcao);
				printf("\n");
				
				fflush(stdin);
				
				if(opcao=='D'){	
				
					fflush(stdin);
					
					for(i=0;i<10;i++){  // estrutura de repetição para a atualização das classificações das poltronas
						for(j=0;j<20;j++){
							
								fflush(stdin);
								
							if(poltronas[i][j]<=quantidade && (classificacao[i][j]=='R' || classificacao[i][j]=='C' ||  classificacao[i][j]=='D')){
								
								if(classificacao[i][j]=='R'){
									
									textcolor(4);  // muda a cor da string
									printf("|%c",classificacao[i][j]);
									printf("%d|\t",poltronas[i][j]);
									
								}else if(classificacao[i][j]=='D'){
									
									textcolor(2);
									printf("|%c",classificacao[i][j]);
									printf("%d|\t",poltronas[i][j]);
									
								}else if(classificacao[i][j]=='C'){
									
									textcolor(1);
									printf("|%c",classificacao[i][j]);
									printf("%d|\t",poltronas[i][j]);
									
								}
							}
						}
					}
						textcolor(7);
						
				}else if(opcao=='C'){ // estrura condicional essencial para o funcionamento do programa
					
					for(i=0;i<10;i++){
						for(j=0;j<20;j++){
							
							if(poltronas[i][j]<=quantidade && (classificacao[i][j]=='C')){
								
								textcolor(1);
								printf("|%c",classificacao[i][j]);
								printf("%d|\t",poltronas[i][j]);
								
							}
						}
					}
					
						textcolor(7);
						printf("\nQuantidade de reservas realizadas: %d\n",quantidadereserva);
						printf("Quantidade de compras realizadas: %d\n",quantidadecompra);
						printf("Valor total em R$ das vendas confirmadas: R$ %d\n",vlrcompra);
				
				}else if(opcao=='R'){ // estrura condicional essencial para o funcionamento do programa
				
					printf("Digite o numero da poltrona desejada: ");
						scanf("%d",&cadeira);
						
					for(i=0;i<10;i++){
						for(j=0;j<20;j++){
							
							if(cadeira==poltronas[i][j] && (classificacao[i][j]=='R' || classificacao[i][j]=='C')){
								
								while(cadeira==poltronas[i][j] && (classificacao[i][j]=='R' || classificacao[i][j]=='C')){
									
									printf("poltrona já selecionada\ndigite a poltrona desejada: ");
											scanf("%d",&cadeira);
											
								}
							}
						}
					}
					
					for(i=0;i<10;i++){ // estrutura de repetição para a atualização das classificações das poltronas
							for(j=0;j<20;j++){
								
							if(cadeira==poltronas[i][j] && (classificacao[i][j]=='D')){
							classificacao[i][j] = 'R';
							codigos[i][j] = idreserva;
							quantidadereserva = quantidadereserva + 1;
							
							}
							}
						}
						
							printf("ATENÇÃO! ANOTE O CÓDIGO DA RESERVA!\n");
							printf("Seu código de reserva: %d\n",idreserva);
								
							fflush(stdin);
							
							printf("\n[C] Confirmar Reserva\n");
							printf("[R] Continuar...\n");
							printf("Digite a opção desejada: ");
								scanf("%c",&opcao2);
								opcao2 = toupper(opcao2);
								
							if(opcao2=='C'){ // estrura condicional essencial para o funcionamento do programa
								
								printf("\nDigite o código da vaga: ");
									scanf("%d",&codvaga);
									
									for(i=0;i<10;i++){  // estrutura de repetição para a atualização das classificações das poltronas
									for(j=0;j<20;j++){
										
										if(codvaga==codigos[i][j] && (classificacao[i][j]=='R')){
											
											classificacao[i][j]='C';
											printf("\nReserva encontrada e confirmada\n");
											printf("Digite a idade inteira do passageiro: ");
											
												while(scanf("%d",&idade)!=1){
													printf("A idade deve ser composta apenas por números: ");
																while(getchar()!='\n');
												}
												if(idade<=5){
													
													vlrcompra = vlrcompra + (valor/2);
													quantidadecompra = quantidadecompra + 1;
													quantidadereserva = quantidadereserva - 1;
													
												}else if(idade>=6){
													
													vlrcompra = vlrcompra + valor;
													quantidadecompra = quantidadecompra + 1;
													quantidadereserva = quantidadereserva - 1;
													
												}
	
										}
							}
						}
					}
				 }else if(opcao=='E'){ // estrura condicional essencial para o funcionamento do programa
						 
							printf("\ndigite o numero do código: ");
								scanf("%d",&vercodigo);
								
							 for(i=0;i<10;i++){
							for(j=0;j<20;j++){
								
								if(vercodigo==codigos[i][j] && (classificacao[i][j]=='R')){
									
								 	classificacao[i][j] = 'D';
								 	printf("Vaga encontrada e Cancelada!\n");
								 	
								}
							}
						}
						
				}else if(opcao=='I'){ // estrura condicional essencial para o funcionamento do programa
					
					printf("----------\n");
					printf("Instruções\n");
					printf("----------\n");
					printf("Você poderá realizar quantas compra e reservas quiser\n");
					printf("desde que ainda tenha poltronas disponíveis no avião.\n");
					printf("Você poderá cancelar uma reserva a qualquer hora, mas atente-se,\n");
					printf("uma compra não poderá ser cancelada!\n");
					
				}else if(opcao=='X'){ // estrura condicional essencial para o funcionamento do programa
					
					system("cls");
						printf("Quantidade de reservas realizadas: %d\n",quantidadereserva);
						printf("Quantidade de compras realizadas: %d\n",quantidadecompra);
						printf("Valor total em R$ das vendas confirmadas: R$ %d\n",vlrcompra);
						printf("\n");
						printf("Obrigado por utilizar o nosso sistema :)!");
						return 0;
				}
				
				fflush(stdin);
				
				printf("\n");
				printf("\nDigite SIM para retornar ao menu inicial\n");
				printf("Ou digite qualquer outra palavra para finalizar o programa\n");
				printf("\nRetornar ao menu inicial ?  ");
					scanf("%s",&resposta);
					fflush(stdin);
					
					if(strcmp(resposta,"sim")!=0){ // estrura condicional essencial para o funcionamento do programa
						
						system("cls");
						printf("Quantidade de reservas realizadas: %d\n",quantidadereserva);
						printf("Quantidade de compras realizadas: %d\n",quantidadecompra);
						printf("Valor total em R$ das vendas confirmadas: R$ %d\n",vlrcompra);
						printf("\n");
						printf("Obrigado por utilizar o nosso sistema :)!");
					
						
						return 0;
					}
					
					system("cls");
			
	}
	return 0;
} // fim da função principal 
