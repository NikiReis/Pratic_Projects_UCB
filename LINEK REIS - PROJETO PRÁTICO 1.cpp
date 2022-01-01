// Aluno: Linek Ferreira Almeida dos Reis
// Matrícula: UC21106202
// Curso: Engenharia de Software
// Data: 26/04/2021
// Instituição: Universidade Católica de Brasília
// Local: Brasília - DF, Brasil

//Conceitos do Código Limpo utilizados: Comentários Iformátivos, Nomes Passíveis de Busca, Variáveis Auto Explicativas e Nomes Pronunciáveis

// declaração de bibliotecas

#include<stdio.h> // biblioteca responsável pelo funcionamento do scanf e printf
#include<string.h> // biblioteca responsável por manipulação de string
#include<stdlib.h> // biblioteca necessária para a ativação do 'system("cls")
#include<locale.h> // biblioteca resposável por fazer o código aceitar acentuação

//declaração de variáveis

int adultos,idosos,maiordeidadetot,idade,maiordeidadefe,maiordeidademas,criancas,masculino,feminino,adolescentes; // variáveis responsáveis por receber as classificações de faixa etária 
int Numeropessoas,contador,sessao,sexo; // variáveis responsáveis pelo pelo funcionamento de estruturas de repetição
char nomefilme[30]; // variável por receber o nome do filme que será exibido nas sessões 

// inicio do algoritmo

int main(){ 
	
	setlocale(LC_ALL, "Portuguese");                                              //  declaração de função dentro da biblioteca #include<locale.h>	
	
	printf("------------------\n");                                              
	printf("   CINE BRASÍLIA  \n");                                             
	printf("------------------\n");                                           

	while(sessao!=2){                                                            //  estrutura de repetição de leitura de sessões
		 	printf("Número de Sessões: ");                                          
			scanf("%d",&sessao);                                            
			fflush(stdin);                                                 //  limpa cache de memória

				if(sessao!=2){                                                                   //  estrutura condicional dentro do while
					printf("Valor inválido\n");                                          
					printf("O número de sessões dever ser exatamente 2\n");	                    
							}                                                                     //  fim da estrutura condicional
	}                                                                    //  fim da estrutura de repetição

	while(strlen(nomefilme)<=5 || strlen(nomefilme)>=40 ){                        // estrutura de repetição while comparando strings

		printf("Digite o nome do filme: ");                                         
			fflush(stdin);                                                     //  limpa o cache de memória 
			fgets(nomefilme,sizeof(nomefilme),stdin);                         //  leitura do valor introduzido 
			
			if(strlen(nomefilme)<=5 || strlen(nomefilme)>=40){                 //  estrutura condicional dentro da estrutura de repetição 'while'
	
			 printf("O nome do filme deve conter no mínimo 5\n");             
			 printf("e no máximo 40 caracteres\n");		
			}                                                                 //  fim da estrutura condicional 
	}                                                               //  fim da estrutura de repetição		

while(Numeropessoas<10){                                                      //  estrutura de repetição primaria 
	printf("Digite quantas pessoas assitiram o filme: ");                    

		while(scanf("%d",&Numeropessoas)!=1){                                            //  estrutura de repetição secundaria dentro da primária
		printf("Digite apenas valores inteiros\n");                                 
		printf("Digite quantas pessoas assitiram o filme: ");	                    
		while(getchar() != '\n');                                                  
    	} 	                                                                 //  fim da estrutura de repetição	secundária
		
		if(Numeropessoas<10)                                                
    	printf("A quantidade mínima de pessoas dever ser 10\n");              //  printa na tela a mensagem entre aspas                                                                        //  fim da estrutura condicional dentro da estrutura de repetição pricipal
	
}                                                                        //  fim da estrutura while principal

system("cls");                                                                 //  limpa a tela do prompt de comando 

for(contador=0;contador<Numeropessoas;contador++){                           //  abertura de estrutura de repetição 'for'

system("cls");

	printf("Sexo dos participantes\n");                                         
	printf("[1] Masculino\n");                                                 
	printf("[2] Feminino\n");                                                
	printf("Escolha o sexo: ");                                              
	
		while(scanf("%d",&sexo)!=1){                                             //  estrututa de repetição de comparação de dados introduzidos
		   system("cls");                                                        //  limpa a tela 
		   printf("Digite 1 para masculino\nDigite 2 para feminino\n");             	
	       printf("Escolha o sexo dos participante: \n");                          

		while(getchar() != '\n');                                                     //  while de comparação que não aceita valores em branco
		}                                                                        //  fim da estrutura de repetição while dentro da estrutura de repetição 'for'
	
		switch(sexo){                                                             //  abertura de estrutura switch
	  		case 1:                                                                //  declaração de caso 
	  	
		  		masculino=masculino+1;                                                //  implementação de variável
	  			printf("Digite a idade do participante: ");                            
		 		scanf("%d",&idade);                                               
		 		fflush(stdin);                                                   // limpa o cache de memória
		 	
					while(idade<3 || idade>100){                                             //  estrututa de repetição de comparação de entrada de dados
			
					printf("Idade Iválida\n");                                         
					printf("Digite uma idade entre 3 e 100 anos: ");                  
					scanf("%d",&idade);	                                             //  leitura do valor introduzido 
		
					}                                                                   //  fim da estrutura de repetição
		
			if(idade>=3 && idade<=13){                                            // abertura estrutura condicional	 
			criancas=criancas+1;	                                         
			}                                                                   //  fim da estrutura condicional
		
			else if(idade>=14 && idade<=17){                                      // abertura estrutura condicional
			adolescentes = adolescentes+1;	                                 
			}                                                                   //  fim da estrutura condicional
		
			else if(idade>=18 && idade<=64){                                      // abertura estrutura condicional
			maiordeidademas=maiordeidademas+1;                               
			adultos=adultos+1;	                                            
			}                                                                  //  fim da estrutura condicional
		
			else if(idade>=65 && idade<=100){                                     // abertura estrutura condicional
			maiordeidademas=maiordeidademas+1;                               
			idosos=idosos+1;                                                
			} 	                                                               // fim da estrutura condicional
	
		break;                                                           // quebra do case 1
		
	  		case 2:
	  	
	  			feminino=feminino+1;
				printf("Digite a idade do participante: ");                         // printa na tela a mensagem dentro das aspas
		 		scanf("%d",&idade);
		 		fflush(stdin);
		 	
					while(idade<3 || idade>100){                                           //  estrututa de repetição
			
						printf("Idade Iválida\n");                                       
						printf("Digite uma idade entre 3 e 100 anos: ");                
						scanf("%d",&idade);	                                           //  leitura do valor introduzido 	
		
					}                                                                //  fim da estrutura de repetição
		
		 	if(idade>=3 && idade<=13){                                         // abertura estrutura condicional
			criancas=criancas+1;	                                       
			}                                                                 // fim da estrutura condicional
		
			else if(idade>=14 && idade<=17){                                  // abertura estrutura condicional
			adolescentes = adolescentes+1;                               
			}                                                               // fim da estrutura condicional
		
			else if(idade>=18 && idade<=64){                                  // abertura estrutura condicional
			maiordeidadefe=maiordeidadefe+1;                            
			adultos=adultos+1;                                          
			}                                                              //   fim da estrutura condicional
		
			else if(idade>=65 && idade<=100){                                    // abertura estrutura condicional
			idosos=idosos+1;                                                
			maiordeidadefe=maiordeidadefe+1;                               
			}	                                                              // fim da estrutura condicional

		break;                                                                 // quebra do case 2

		}                                                                    // fim da estrutura switch

	if(idade>=18 && idade<=100)                                       // abertura estrutura condicional
		maiordeidadetot=maiordeidadetot+1;                   
	 
}                                                               // fim da estrutura de repetição 'for'
	
	system("cls");                                                                   //  limpa a tela do prompt de comando 
	
printf("Filme assistido nas duas sessões: %s",nomefilme);                          //  printa na tela a mensagem dentro das aspas para criação de uma tabela
printf("------------------------------------------------\n");	                       
printf("             Tabela de Resultados               \n");                         
printf("------------------------------------------------\n");                        //  printa na tela a mensagem dentro das aspas para criação de uma tabela
printf("de 3 até 13 anos   | Crianças      | %d         \n",criancas);             
printf("de 14 até 17 anos  | Adolescentes  | %d         \n",adolescentes);         
printf("de 18 até 64 anos  | Adultos       | %d         \n",adultos);             
printf("de 65 até 100 anos | Idosos        | %d         \n",idosos);	         
printf("------------------------------------------------\n");                   

printf("Aperte qualquer botão para continuar com os resultados\n");               
system("pause");                                                                  // pausa o sistema
system("cls");                                                                   // limpa a tela para a visualização da próxima tabela

printf("|      Maiores de 18 anos      \n");                                      //  printa na tela a mensagem dentro das aspas para criação de uma tabela
printf("|------------------------------\n");                                     
printf("|Quantidade Total  | %d        \n",maiordeidadetot);                    
printf("|Sexo Feminino     | %d        \n",maiordeidadefe);                    
printf("|Sexo Masculino    | %d        \n",maiordeidademas);                  
printf("-------------------------------\n");                                 //  printa na tela a mensagem dentro das aspas para criação de uma tabela

printf("Aperte qualquer botão para continuar com os resultados\n");               
system("pause");                                                                 // pausa o sistema
system("cls");                                                                  // limpa a tela para a visualização da próxima tabela

printf(" Quantidades por Sexo \n");                                            
printf("----------------------\n");                                           
printf("|Feminino  | %d       \n",feminino);                                 
printf("|Masculino | %d       \n",masculino);                               
printf("----------------------\n");                                        

printf("\n");                                                                      

printf("Obrigado por utilizar o nosso sistema\nFinalizando o programa\n");       

	return 0;
			
} // finaliza o algoritmo

