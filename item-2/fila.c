#include<stdio.h>
#include<stdlib.h>

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
	Nodo *novo = (Nodo*) malloc(sizeof(Nodo));
	addProcesso(novo->process,id);
	novo->proximo = NULL;
	if(f->inicio==NULL) {
		f->inicio = novo;
	}
	else {
		Nodo *aux = f->inicio;
		while(aux->proximo!=NULL) {
			aux = aux->proximo;
		}
		aux->proximo = novo;
	}
}

void imprimeFila(Fila *f) {
	Nodo *aux = f->inicio;
	while(aux!=NULL) {
		imprimeProcesso(aux->process);
		aux = aux->proximo;
	}
}

