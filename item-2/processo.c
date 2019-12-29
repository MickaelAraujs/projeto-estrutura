#include<stdio.h>
#include<stdlib.h>

#include "processo.h"

#define TEMPO_MAX 100.0 // representa o tempo máximo para cada processo em ms.

struct processo {
	int id; //número identificador do processo
	float tempo; //representa o tempo do processo em ms.
};

Processo *criaProcesso() {
	Processo *p = (Processo*) malloc(sizeof(Processo));
	return p;
}

void imprimeProcesso(Processo *p) {
	printf("NUMERO DO PROCESSO: %d\n\n",p->id);
	printf("TEMPO DE EXECUCAO DO PROCESSO: %.2f\n\n",p->tempo);
}

int liberaProcesso(Processo *p) {
	int aux = p->id;
	free(p);
	return aux;
}

void addProcesso(Processo *p,int id) {
	p->id = id;
}
