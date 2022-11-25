#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "engine.h"

int main(){

	setlocale(LC_ALL, "portuguese");
	char menuEscolha[99];
	
	printf("Escolha uma das opções a seguir digitando o numero correspodente:\n");
	printf("| 1 - Jogar\n");
	printf("| 2 - Vencedores\n");
	printf("| 3 - Creditos\n");
	printf("| 4 - Sair\n");
	printf("| ");
	fgets(menuEscolha, sizeof menuEscolha, stdin);
	
	while(1){
		if(menuEscolha[0] == '1'){
			
			system("cls");
			
			int numeroAleatorio = gerarNumeroAleatorio(300), perguntaIndice = 1, respostaIndice = 2, alternativaCorretaIndice = 1801, caracterInvalido;
			char respostaUsuario[99], alternativaCorreta = '2';
			
			if(numeroAleatorio > 1){
				perguntaIndice = (numeroAleatorio*6)-5;
				respostaIndice = perguntaIndice+1;
				alternativaCorretaIndice = 1800 + numeroAleatorio;
				alternativaCorreta = obterAlternativaCorreta(alternativaCorretaIndice);
			}
			
			exibirPergunta(perguntaIndice);
			exibirRespostas(respostaIndice);
			printf("\nDigite o número correspodente a alternativa correta: ");
			do{
				
				caracterInvalido = 0;
				fgets(respostaUsuario, sizeof respostaUsuario, stdin);
				if(respostaUsuario[0] != '1' && respostaUsuario[0] != '2' && respostaUsuario[0] != '3' && respostaUsuario[0] != '4'){
					caracterInvalido++;
					printf("Por favor digite uma resposta válida.\n");
				}
				
			}while(caracterInvalido > 0);
			
			if(respostaUsuario[0] == alternativaCorreta){
				printf("\nParabéns você acertou.\n\n");
			}
			else{
				printf("\nQue pena, você errou.\n\n");
			}
			
			printf("Escolha uma das opções a seguir digitando o numero correspodente:\n");
			printf("| 1 - Jogar\n");
			printf("| 2 - Vencedores\n");
			printf("| 3 - Creditos\n");
			printf("| 4 - Sair\n");
			printf("| ");
			fgets(menuEscolha, sizeof menuEscolha, stdin);
			
		}
		else if(menuEscolha[0] == '2'){
			printf("Escolheu 2.\n");
			fgets(menuEscolha, sizeof menuEscolha, stdin);
		}
		else if(menuEscolha[0] == '3'){
			printf("Creditos\nWilton");
			fgets(menuEscolha, sizeof menuEscolha, stdin);
		}
		else if(menuEscolha[0] == '4'){
			return 0;
			break;
		}
		else{
			printf("\nVocê digitou uma opção inválida, por favor digite uma das opções listadas.\n");
			fgets(menuEscolha, sizeof menuEscolha, stdin);
		}
	}
	
}
