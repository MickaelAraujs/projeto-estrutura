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

int tamanhoFila(Fila *f) {
	Nodo *aux = f->inicio;
	int count = 0;
	while(aux!=NULL) {
		count++;
		aux = aux->proximo;
	}
	return count;
}

void push(Fila *f,int id,int tempo) {
	Nodo *novo = (Nodo*) malloc(sizeof(Nodo));
	novo->process = criaProcesso();

	novo->proximo = NULL;

	if(f->inicio==NULL) {
		f->inicio = novo;
		addProcesso(novo->process,id,0);
	}
	else {
		Nodo *aux = f->inicio;
		int soma = tempoExe(aux->process);
		while(aux->proximo!=NULL) {
			aux = aux->proximo;
			soma = soma + tempoExe(aux->process);
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
	printf("\n\n LIBERANDO PROCESSOS ...\n\n");
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

void maiorTempoEspera(Fila *f) {
	/* O maior tempo de espera é o último elemento da fila pois o tempo de espera consiste na soma dos tempos de execução dos processos */
	
	Nodo *aux = f->inicio;
	while(aux->proximo!=NULL) {
		aux = aux->proximo;
	}
	int tempoEsp = tempoEspera(aux->process);
	
	Nodo *aux2 = f->inicio;
	while(aux2->proximo!=aux) {
		aux2 = aux2->proximo;
	}
	aux2->proximo = NULL;
	
	int process = liberaProcesso(aux->process);
	printf("processo %d finalizado!!!\n\n",process);
	free(aux);
}

int vazia(Fila *f) {
	if(f->inicio == NULL) {
		return 1;
	}
	return 0;
}
