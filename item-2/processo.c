#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "processo.h"

struct processo {
	int id; //número identificador do processo
	int tempo; //representa o tempo do processo em ms.
	int espera; //tempo de espera do processo.
};

Processo *criaProcesso() {
	Processo *p = (Processo*) malloc(sizeof(Processo));
	return p;
}

void imprimeProcesso(Processo *p) {
	printf("NUMERO DO PROCESSO: %d\n\n",p->id);
	printf("TEMPO DE EXECUCAO DO PROCESSO: %d ms\n\n",p->tempo);
	printf("TEMPO DE ESPERA DO PROCESSO: %d ms\n\n",p->espera);
}

int liberaProcesso(Processo *p) {
	int aux = p->id;
	free(p);
	return aux;
}

void addProcesso(Processo *p,int id,int espera) {
	p->id = id;
	p->tempo = (rand()%100) + 1;
	p->espera = espera;
}

int tempoEspera(Processo *p) {
	return p->espera;
}

int tempoExe(Processo *p) {
	return p->tempo;
}
