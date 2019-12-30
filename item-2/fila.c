#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "processo.h"
#include "fila.h"

struct nodo {
	Processo *process;
	struct nodo *proximo;
};

struct fila {
	Nodo *inicio;
};

Fila *criaFila() {
	Fila *f = (Fila*) malloc(sizeof(Fila));
	f->inicio = NULL;
	return f;
}

void push(Fila *f,int id) {
	srand(time(NULL));

	Nodo *novo = (Nodo*) malloc(sizeof(Nodo));
	novo->process = criaProcesso();

	novo->proximo = NULL;

	if(f->inicio==NULL) {
		f->inicio = novo;
		addProcesso(novo->process,id,0);
	}
	else {
		Nodo *aux = f->inicio;
		int soma = tempoEspera(aux->process);
		while(aux->proximo!=NULL) {
			aux = aux->proximo;
			soma = soma + tempoEspera(aux->process);
		}
		aux->proximo = novo;
		addProcesso(novo->process,id,soma);
	}
}

void imprimeFila(Fila *f) {
	Nodo *aux = f->inicio;
	while(aux!=NULL) {
		imprimeProcesso(aux->process);
		aux = aux->proximo;
	}
}

void liberaFila(Fila *f) {
	Nodo *aux = f->inicio;
	while(aux!=NULL) {
		f->inicio = aux->proximo;
		int processID = liberaProcesso(aux->process);
		printf("processo %d finalizado!!!\n\n",processID);
		Nodo *aux2 = aux;
		aux = aux->proximo;
		free(aux2);
	}
}
