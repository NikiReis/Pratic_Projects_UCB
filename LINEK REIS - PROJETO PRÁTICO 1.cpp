// Aluno: Linek Ferreira Almeida dos Reis
// Matr�cula: UC21106202
// Curso: Engenharia de Software
// Data: 26/04/2021
// Institui��o: Universidade Cat�lica de Bras�lia
// Local: Bras�lia - DF, Brasil

//Conceitos do C�digo Limpo utilizados: Coment�rios Iform�tivos, Nomes Pass�veis de Busca, Vari�veis Auto Explicativas e Nomes Pronunci�veis

// declara��o de bibliotecas

#include<stdio.h> // biblioteca respons�vel pelo funcionamento do scanf e printf
#include<string.h> // biblioteca respons�vel por manipula��o de string
#include<stdlib.h> // biblioteca necess�ria para a ativa��o do 'system("cls")
#include<locale.h> // biblioteca respos�vel por fazer o c�digo aceitar acentua��o

//declara��o de vari�veis

int adultos,idosos,maiordeidadetot,idade,maiordeidadefe,maiordeidademas,criancas,masculino,feminino,adolescentes; // vari�veis respons�veis por receber as classifica��es de faixa et�ria 
int Numeropessoas,contador,sessao,sexo; // vari�veis respons�veis pelo pelo funcionamento de estruturas de repeti��o
char nomefilme[30]; // vari�vel por receber o nome do filme que ser� exibido nas sess�es 

// inicio do algoritmo

int main(){ 
	
	setlocale(LC_ALL, "Portuguese");                                              //  declara��o de fun��o dentro da biblioteca #include<locale.h>	
	
	printf("------------------\n");                                             //  printa na tela a mensagem entre aspas 
	printf("   CINE BRAS�LIA  \n");                                            //  printa na tela a mensagem entre aspas 
	printf("------------------\n");                                           //  printa na tela a mensagem entre aspas 

	while(sessao!=2){                                                            //  estrutura de repeti��o de leitura de sess�es
		 	printf("N�mero de Sess�es: ");                                         //  printa na tela a mensagem entre aspas 
			scanf("%d",&sessao);                                            //  leitura do valor introduzido
			fflush(stdin);                                                 //  limpa cache de mem�ria

				if(sessao!=2){                                                                   //  estrutura condicional dentro do while
					printf("Valor inv�lido\n");                                         //  printa na tela a mensagem entre aspas 
					printf("O n�mero de sess�es dever ser exatamente 2\n");	                   //  printa na tela a mensagem entre aspas 
							}                                                                     //  fim da estrutura condicional
	}                                                                    //  fim da estrutura de repeti��o

	while(strlen(nomefilme)<=5 || strlen(nomefilme)>=40 ){                        // estrutura de repeti��o while comparando strings

		printf("Digite o nome do filme: ");                                         //  printa na tela a mensagem entre aspas 
			fflush(stdin);                                                     //  limpa o cache de mem�ria 
			fgets(nomefilme,sizeof(nomefilme),stdin);                         //  leitura do valor introduzido 
			
			if(strlen(nomefilme)<=5 || strlen(nomefilme)>=40){                 //  estrutura condicional dentro da estrutura de repeti��o 'while'
	
			 printf("O nome do filme deve conter no m�nimo 5\n");             //  printa na tela a mensagem entre aspas 
			 printf("e no m�ximo 40 caracteres\n");		
			}                                                                 //  fim da estrutura condicional 
	}                                                               //  fim da estrutura de repeti��o		

while(Numeropessoas<10){                                                      //  estrutura de repeti��o primaria 
	printf("Digite quantas pessoas assitiram o filme: ");                    //  printa na tela a mensagem entre aspas 

		while(scanf("%d",&Numeropessoas)!=1){                                            //  estrutura de repeti��o secundaria dentro da prim�ria
		printf("Digite apenas valores inteiros\n");                                 //  printa na tela a mensagem entre aspas
		printf("Digite quantas pessoas assitiram o filme: ");	                   //  printa na tela a mensagem entre aspas 
		while(getchar() != '\n');                                                 //  while de compara��o que n�o aceita valores em branco 
    	} 	                                                                 //  fim da estrutura de repeti��o	secund�ria
		
		if(Numeropessoas<10)                                                
    	printf("A quantidade m�nima de pessoas dever ser 10\n");              //  printa na tela a mensagem entre aspas                                                                        //  fim da estrutura condicional dentro da estrutura de repeti��o pricipal
	
}                                                                        //  fim da estrutura while principal

system("cls");                                                                 //  limpa a tela do prompt de comando 

for(contador=0;contador<Numeropessoas;contador++){                           //  abertura de estrutura de repeti��o 'for'

system("cls");

	printf("Sexo dos participantes\n");                                         //  printa na tela a mensagem em aspas
	printf("[1] Masculino\n");                                                 //  printa na tela a mensagem em aspas
	printf("[2] Feminino\n");                                                 //  printa na tela a mensagem em aspas
	printf("Escolha o sexo: ");                                              //  printa na tela a mensagem em aspas
	
		while(scanf("%d",&sexo)!=1){                                             //  estrututa de repeti��o de compara��o de dados introduzidos
		   system("cls");                                                        //  limpa a tela 
		   printf("Digite 1 para masculino\nDigite 2 para feminino\n");             //  printa na tela a mensagem em aspas	
	       printf("Escolha o sexo dos participante: \n");                          //  printa na tela a mensagem em aspas

		while(getchar() != '\n');                                                     //  while de compara��o que n�o aceita valores em branco
		}                                                                        //  fim da estrutura de repeti��o while dentro da estrutura de repeti��o 'for'
	
		switch(sexo){                                                             //  abertura de estrutura switch
	  		case 1:                                                                //  declara��o de caso 
	  	
		  		masculino=masculino+1;                                                //  implementa��o de vari�vel
	  			printf("Digite a idade do participante: ");                            //  printa na tela a mensagem em aspas
		 		scanf("%d",&idade);                                               //  leitura do valor introduzido 
		 		fflush(stdin);                                                   // limpa o cache de mem�ria
		 	
					while(idade<3 || idade>100){                                             //  estrututa de repeti��o de compara��o de entrada de dados
			
					printf("Idade Iv�lida\n");                                         //  printa na tela a mensagem dentro das aspas
					printf("Digite uma idade entre 3 e 100 anos: ");                  //  printa na tela a mensagem dentro das aspas
					scanf("%d",&idade);	                                             //  leitura do valor introduzido 
		
					}                                                                   //  fim da estrutura de repeti��o
		
			if(idade>=3 && idade<=13){                                            // abertura estrutura condicional	 
			criancas=criancas+1;	                                         //  implementa��o de vari�vel
			}                                                                   //  fim da estrutura condicional
		
			else if(idade>=14 && idade<=17){                                      // abertura estrutura condicional
			adolescentes = adolescentes+1;	                                 //  implementa��o de vari�vel
			}                                                                   //  fim da estrutura condicional
		
			else if(idade>=18 && idade<=64){                                      // abertura estrutura condicional
			maiordeidademas=maiordeidademas+1;                               //  implementa��o de vari�vel
			adultos=adultos+1;	                                            //  implementa��o de vari�vel
			}                                                                  //  fim da estrutura condicional
		
			else if(idade>=65 && idade<=100){                                     // abertura estrutura condicional
			maiordeidademas=maiordeidademas+1;                               //  implementa��o de vari�vel
			idosos=idosos+1;                                                //  implementa��o de vari�vel
			} 	                                                               // fim da estrutura condicional
	
		break;                                                           // quebra do case 1
		
	  		case 2:
	  	
	  			feminino=feminino+1;
				printf("Digite a idade do participante: ");                         // printa na tela a mensagem dentro das aspas
		 		scanf("%d",&idade);
		 		fflush(stdin);
		 	
					while(idade<3 || idade>100){                                           //  estrututa de repeti��o
			
						printf("Idade Iv�lida\n");                                       // printa na tela a mensagem dentro das aspas
						printf("Digite uma idade entre 3 e 100 anos: ");                // printa na tela a mensagem dentro das aspas
						scanf("%d",&idade);	                                           //  leitura do valor introduzido 	
		
					}                                                                //  fim da estrutura de repeti��o
		
		 	if(idade>=3 && idade<=13){                                         // abertura estrutura condicional
			criancas=criancas+1;	                                       //  implementa��o de vari�vel
			}                                                                 // fim da estrutura condicional
		
			else if(idade>=14 && idade<=17){                                  // abertura estrutura condicional
			adolescentes = adolescentes+1;                               //  implementa��o de vari�vel
			}                                                               // fim da estrutura condicional
		
			else if(idade>=18 && idade<=64){                                  // abertura estrutura condicional
			maiordeidadefe=maiordeidadefe+1;                             //  implementa��o de vari�vel
			adultos=adultos+1;                                          //  implementa��o de vari�vel
			}                                                              //   fim da estrutura condicional
		
			else if(idade>=65 && idade<=100){                                    // abertura estrutura condicional
			idosos=idosos+1;                                                //  implementa��o de vari�vel
			maiordeidadefe=maiordeidadefe+1;                               //  implementa��o de vari�vel
			}	                                                              // fim da estrutura condicional

		break;                                                                 // quebra do case 2

		}                                                                    // fim da estrutura switch

	if(idade>=18 && idade<=100)                                       // abertura estrutura condicional
		maiordeidadetot=maiordeidadetot+1;                    //  implementa��o de vari�vel
	 
}                                                               // fim da estrutura de repeti��o 'for'
	
	system("cls");                                                                   //  limpa a tela do prompt de comando 
	
printf("Filme assistido nas duas sess�es: %s",nomefilme);                          //  printa na tela a mensagem dentro das aspas para cria��o de uma tabela
printf("------------------------------------------------\n");	                       //  printa na tela a mensagem dentro das aspas para cria��o de uma tabela
printf("             Tabela de Resultados               \n");                         //  printa na tela a mensagem dentro das aspas para cria��o de uma tabela
printf("------------------------------------------------\n");                        //  printa na tela a mensagem dentro das aspas para cria��o de uma tabela
printf("de 3 at� 13 anos   | Crian�as      | %d         \n",criancas);              //  printa na tela a mensagem dentro das aspas com vari�vel inclusa
printf("de 14 at� 17 anos  | Adolescentes  | %d         \n",adolescentes);         //  printa na tela a mensagem dentro das aspas com vari�vel inclusa
printf("de 18 at� 64 anos  | Adultos       | %d         \n",adultos);             //  printa na tela a mensagem dentro das aspas com vari�vel inclusa
printf("de 65 at� 100 anos | Idosos        | %d         \n",idosos);	         //  printa na tela a mensagem dentro das aspas com vari�vel inclusa
printf("------------------------------------------------\n");                   //  printa na tela a mensagem dentro das aspas para cria��o de uma tabela

printf("Aperte qualquer bot�o para continuar com os resultados\n");                //  printa na tela a mensagem dentro das aspas
system("pause");                                                                  // pausa o sistema
system("cls");                                                                   // limpa a tela para a visualiza��o da pr�xima tabela

printf("|      Maiores de 18 anos      \n");                                      //  printa na tela a mensagem dentro das aspas para cria��o de uma tabela
printf("|------------------------------\n");                                     //  printa na tela a mensagem dentro das aspas para cria��o de uma tabela
printf("|Quantidade Total  | %d        \n",maiordeidadetot);                    //  printa na tela a mensagem dentro das aspas com vari�vel inclusa
printf("|Sexo Feminino     | %d        \n",maiordeidadefe);                    //  printa na tela a mensagem dentro das aspas com vari�vel inclusa
printf("|Sexo Masculino    | %d        \n",maiordeidademas);                  //  printa na tela a mensagem dentro das aspas com vari�vel inclusa
printf("-------------------------------\n");                                 //  printa na tela a mensagem dentro das aspas para cria��o de uma tabela

printf("Aperte qualquer bot�o para continuar com os resultados\n");               //  printa na tela a mensagem dentro das aspas
system("pause");                                                                 // pausa o sistema
system("cls");                                                                  // limpa a tela para a visualiza��o da pr�xima tabela

printf(" Quantidades por Sexo \n");                                            //  printa na tela a mensagem dentro das aspas para cria��o de uma tabela
printf("----------------------\n");                                           //  printa na tela a mensagem dentro das aspas para cria��o de uma tabela
printf("|Feminino  | %d       \n",feminino);                                 //  printa na tela a mensagem dentro das aspas com vari�vel inclusa
printf("|Masculino | %d       \n",masculino);                               //  printa na tela a mensagem dentro das aspas com vari�vel inclusa
printf("----------------------\n");                                        //  printa na tela a mensagem dentro das aspas para cria��o de uma tabela

printf("\n");                                                                      // pula uma linha para melhor visualiza��o do prompt de comando

printf("Obrigado por utilizar o nosso sistema\nFinalizando o programa\n");       // printa na tela a mensagem dentro das aspas

	return 0;
			
} // finaliza o algoritmo

