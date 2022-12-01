#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "engine.h"

int main(){

	setlocale(LC_ALL, "portuguese");
	char menuEscolha[99];
	
	menu(menuEscolha);
	
	while(1){
		if(menuEscolha[0] == '1'){
			
			char jogador[99];
			int i;
			
			printf("Digite o seu nome: ");
			fgets(jogador, 98, stdin);
			system("cls");
			
			for(i = 0; i <= 15; i++){
			
				system("cls");
				
				int numeroAleatorio, perguntaIndice = 1, respostaIndice = 2, alternativaCorretaIndice = 1801, caracterInvalido, premioAtual, premioDerrota, j = -1, numerosSorteados[16];
				char respostaUsuario[99], alternativaCorreta = '2';
				
				do{
				    if(i <= 5 && j == -1){
    					numeroAleatorio = gerarNumeroAleatorio(101, 0);
    				}
    				else if(i <= 5 && numerosSorteados[j] == numeroAleatorio){
    					numeroAleatorio = gerarNumeroAleatorio(101, 0);
    					j = -1;
    				}
    				else if(i <= 10 && j == -1){
    					numeroAleatorio = gerarNumeroAleatorio(101, 100);	
    				}
    				else if(i <= 10 && numerosSorteados[j] == numeroAleatorio){
    					numeroAleatorio = gerarNumeroAleatorio(101, 100);	
    					j = -1;
    				}
    				else if(i <= 15 && j == -1){
    					numeroAleatorio = gerarNumeroAleatorio(101, 200);	
    				}
    				else if(i <= 15 && numerosSorteados[j] == numeroAleatorio){
    					numeroAleatorio = gerarNumeroAleatorio(101, 200);
						j = -1;	
    				}
    				j++;
				}while(j < i);
				
				numerosSorteados[i] = numeroAleatorio; 
				
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
				printf("\nDigite o n�mero correspodente a alternativa correta: ");

				do{
					
					caracterInvalido = 0;
					fgets(respostaUsuario, sizeof respostaUsuario, stdin);
					if(respostaUsuario[0] != '1' && respostaUsuario[0] != '2' && respostaUsuario[0] != '3' && respostaUsuario[0] != '4' && respostaUsuario[0] != '5'){
						caracterInvalido++;
						printf("Por favor digite uma resposta v�lida.\n");
					}
					
				}while(caracterInvalido > 0);
			
				
				if(respostaUsuario[0] == alternativaCorreta){
					if(i < 15){
						printf("\nParab�ns voc� acertou.\n\n");
						system("pause");
					}
					else{
						printf("\nParab�ns voc� acertou todas as perguntas necess�rias para o 1 milh�o de reais!\n\n");
						system("pause");
						system("cls");
						salvarHistorico(jogador, 1000000);
						salvarVencedores(jogador);
					}
				}
				else if(respostaUsuario[0] == '5'){
					printf("\nVoc� escolheu parar, e ganhou R$%i.\n\n", premioAtual);
					system("pause");
					system("cls");
					salvarHistorico(jogador, premioAtual);
					break;
				}
				else{
					printf("\nQue pena, voc� errou. Mas ganhou R$%i.\n\n", premioDerrota);
					system("pause");
					system("cls");
					salvarHistorico(jogador, premioDerrota);
					break;
				}
			}
			
			menu(menuEscolha);
			
		}
		else if(menuEscolha[0] == '2'){
			
			system("cls");
			
			int checagemExibirVencedores;
			
			checagemExibirVencedores = exibirVencedores();
			
			if(checagemExibirVencedores  == 0){
				while(1){
					printf("\n\n");
					printf("1 - Apagar hist�rico de Vencedores | 2 - Sair do hist�rico de Vencedores\n| ");
					fgets(menuEscolha, sizeof menuEscolha, stdin);
					
					if(menuEscolha[0] == '1'){
						remove("./data/vencedores.txt");
						system("cls");
						break;
					}
					else if(menuEscolha[0] == '2'){
						break;
					}
					else{
						
						printf("\nVoc� digitou uma op��o inv�lida, por favor digite uma das op��es listadas.\n| ");
						fgets(menuEscolha, sizeof menuEscolha, stdin);
						
					}
					
				}
			}
			else{
				
				printf("Aparentemente ningu�m ainda conseguiu ganhar 1 milh�o de Reais.\n\n");
				system("pause");
				
			}
			system("cls");
			menu(menuEscolha);
			
		}
		else if(menuEscolha[0] == '3'){
			
			system("cls");
			
			int checagemExibirHistorico;
			
			checagemExibirHistorico = exibirHistorico();
			
			if(checagemExibirHistorico == 0){
				while(1){
					printf("\n\n");
					printf("1 - Apagar hist�rico | 2 - Sair do hist�rico\n| ");
					fgets(menuEscolha, sizeof menuEscolha, stdin);
					
					if(menuEscolha[0] == '1'){
						remove("./data/historico.txt");
						system("cls");
						break;
					}
					else if(menuEscolha[0] == '2'){
						break;
					}
					else{
						
						printf("\nVoc� digitou uma op��o inv�lida, por favor digite uma das op��es listadas.\n| ");
						fgets(menuEscolha, sizeof menuEscolha, stdin);
						
					}
					
				}
			}
			else{
				
				printf("Aparentemente voc� ainda n�o jogou, portanto n�o h� hist�rico.\n\n");
				system("pause");
				
			}
			system("cls");
			menu(menuEscolha);
			
		}
		else if(menuEscolha[0] == '4'){
			
			system("cls");
			
			printf("|\t\t\t\tCreditos\t\t\t\t|\n");
			printf("|\t\t\t\t\t\t\t\t\t|\n");
			printf("|\t\t\t\t Wilton\t\t\t\t\t|\n");
			printf("________________________________________________________________________");
			
			printf("\n\n");
			system("pause");
			system("cls");
			
			menu(menuEscolha);
			
		}
		else if(menuEscolha[0] == '5'){
			
			return 0;
			break;
			
		}
		else{
			
			printf("\nVoc� digitou uma op��o inv�lida, por favor digite uma das op��es listadas.\n| ");
			fgets(menuEscolha, sizeof menuEscolha, stdin);
			
		}
	}
	
}
