#include<stdio.h>
#include<stdlib.h>

#include "processo.h"

struct processo {
	int id; //número identificador do processo
};

Processo *criaProcesso() {
	Processo *p = (Processo*) malloc(sizeof(Processo));
	return p;
}

void imprimeProcesso(Processo *p) {
	printf("NUMERO DO PROCESSO: %d",p->id);	
}

int liberaProcesso(Processo *p) {
	int aux = p->id;
	free(p);
	return aux;
}

void addProcesso(Processo *p,int id) {
	p->id = id;
}
