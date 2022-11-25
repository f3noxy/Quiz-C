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
			
			char jogador[99];
			int i;
			
			printf("Digite o seu nome: ");
			fgets(jogador, 98, stdin);
			system("cls");
			
			for(i = 0; i <= 15; i++){
			
				system("cls");
				
				int numeroAleatorio = gerarNumeroAleatorio(300), perguntaIndice = 1, respostaIndice = 2, alternativaCorretaIndice = 1801, caracterInvalido, premioAtual, premioDerrota;
				char respostaUsuario[99], alternativaCorreta = '2';
				
				if(numeroAleatorio > 1){
					perguntaIndice = (numeroAleatorio*6)-5;
					respostaIndice = perguntaIndice+1;
					alternativaCorretaIndice = 1800 + numeroAleatorio;
					alternativaCorreta = obterAlternativaCorreta(alternativaCorretaIndice);
				}
				
				exibirPergunta(perguntaIndice);
				exibirRespostas(respostaIndice);
				premioAtual = checarPremioParar(i);
				premioDerrota = checarPremioPerder(i);
				printf("\nDigite 5 caso queira parar ganhando R$%i\n", premioAtual);
				printf("\nDigite o número correspodente a alternativa correta: ");
				do{
					
					caracterInvalido = 0;
					fgets(respostaUsuario, sizeof respostaUsuario, stdin);
					if(respostaUsuario[0] != '1' && respostaUsuario[0] != '2' && respostaUsuario[0] != '3' && respostaUsuario[0] != '4' && respostaUsuario[0] != '5'){
						caracterInvalido++;
						printf("Por favor digite uma resposta válida.\n");
					}
					
				}while(caracterInvalido > 0);
			
				
				if(respostaUsuario[0] == alternativaCorreta){
					if(i < 15){
						printf("\nParabéns você acertou.\n\n");
						system("pause");
					}
					else{
						printf("\nParabéns você acertou todas as perguntas necessárias para o 1 milhão de reais!\n\n");
						system("pause");
						system("cls");
						salvarHistorico(jogador, 1000000);
						salvarVencedores(jogador);
					}
				}
				else if(respostaUsuario[0] == '5'){
					printf("\nVocê escolheu parar, e ganhou R$%i.\n\n", premioAtual);
					system("pause");
					system("cls");
					salvarHistorico(jogador, premioAtual);
					break;
				}
				else{
					printf("\nQue pena, você errou. Mas ganhou R$%i.\n\n", premioDerrota);
					system("pause");
					system("cls");
					salvarHistorico(jogador, premioDerrota);
					break;
				}
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
