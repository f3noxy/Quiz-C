#ifndef ENGINE_H
#define ENGINE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdbool.h> 
#include <string.h>

int gerarNumeroAleatorio(int maxRange){
	
	srand(time(NULL));
	return rand() % maxRange;
	
}

void exibirPergunta(int numeroPergunta){
	
	char pergunta[99];
	int i;
	FILE *perguntas;
	
	perguntas = fopen("./data/questions.txt", "r");
	
	for(i = 0; i < numeroPergunta; i++){
		
		fgets(pergunta, 99, perguntas);
		
	}
	
	fclose(perguntas);
	
	printf("%s", pergunta);
	
}

void exibirRespostas(int comecoRespostas){
	
	char resposta[99];
	int i;
	FILE *respostas;
	
	respostas = fopen("./data/questions.txt", "r");
	
	for(i = 0; i <= comecoRespostas+3; i++){
		
		if(i >= comecoRespostas){
			printf("%s\n", resposta);
		}
		fgets(resposta, 99, respostas);

	}
	
	fclose(respostas);
	
}

char obterAlternativaCorreta(int numeroResposta){
		
	char alternativa[99];
	int i;
	FILE *alternativas;
	
	alternativas = fopen("./data/questions.txt", "r");
	
	for(i = 0; i < numeroResposta; i++){
		
		fgets(alternativa, 99, alternativas);
		
	}
	
	fclose(alternativas);
	
	return alternativa[0];
	
}

int checarPremioParar(int perguntaAtual){
	switch(perguntaAtual){
		case 0:
			return 0;
			break;
		case 1:
			return 1000;
			break;
		case 2:
			return 2000;
			break;
		case 3:
			return 3000;
			break;
		case 4:
			return 4000;
			break;
		case 5:
			return 5000;
			break;
		case 6:
			return 10000;
			break;
		case 7:
			return 20000;
			break;
		case 8:
			return 30000;
			break;
		case 9:
			return 40000;
			break;
		case 10:
			return 50000;
			break;
		case 11:
			return 100000;
			break;
		case 12:
			return 200000;
			break;
		case 13:
			return 300000;
			break;
		case 14:
			return 400000;
			break;
		case 15:
			return 500000;
			break;
	}
}

int checarPremioPerder(int perguntaAtual){
	switch(perguntaAtual){
		case 0:
			return 0;
			break;
		case 1:
			return 500;
			break;
		case 2:
			return 1000;
			break;
		case 3:
			return 1500;
			break;
		case 4:
			return 2000;
			break;
		case 5:
			return 2500;
			break;
		case 6:
			return 5000;
			break;
		case 7:
			return 10000;
			break;
		case 8:
			return 15000;
			break;
		case 9:
			return 20000;
			break;
		case 10:
			return 25000;
			break;
		case 11:
			return 50000;
			break;
		case 12:
			return 100000;
			break;
		case 13:
			return 150000;
			break;
		case 14:
			return 200000;
			break;
		case 15:
			return 0;
			break;
	}
}

bool file_exists (char *filename) {
  struct stat   buffer;   
  return (stat (filename, &buffer) == 0);
}

void salvarVencedores(char nome[99]){
	
	FILE *vencedores;
	
	if(file_exists("./data/vencedores.txt")){
		vencedores = fopen("./data/vencedores.txt", "a");
	}
	else{
		vencedores = fopen("./data/vencedores.txt", "w");
		fputs("--- Vencedores do Jogo ---\n\n", vencedores);
	}
	
	fputs(nome, vencedores);
	
	fclose(vencedores);
	
}

void salvarHistorico(char nome[99], int premio){
	
	FILE *historico;
	char premioString[7];
	
	if(file_exists("./data/historico.txt")){
		historico = fopen("./data/historico.txt", "a");
	}
	else{
		historico = fopen("./data/historico.txt", "w");
		fputs("--- Historico ---\n\n", historico);
	}
	
	nome[strlen(nome) - 1] = ' ';
	snprintf(premioString, 7, "%d", premio);
	
	fputs(nome, historico);
	fputs("- R$", historico);
	fputs(premioString, historico);
	fputs("\n", historico);
	
	fclose(historico);
	
}

#endif
