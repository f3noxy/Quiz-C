#ifndef ENGINE_H
#define ENGINE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

#endif
