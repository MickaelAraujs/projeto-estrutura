#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"

struct nodo {
	int info;
	struct nodo *prox;
};

struct pilha {
	Nodo *topo;
};

Pilha * criar() {
	Pilha *p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = NULL;
	
	return p;
}

void destruir(Pilha *p) {
	Nodo *aux = p->topo;
	while(aux!=NULL) {
		Nodo *aux2 = aux->prox;
		free(aux);
		aux = aux2;
	}
	free(p);
}

int desempilhar(Pilha *p) {
	if(p->topo == NULL) {
		printf("Pilha vazia!!");
		exit(1);
	}
	Nodo *aux = p->topo;
	int valor = aux->info;
	p->topo = aux->prox;
	free(aux);
	
	return valor;
}

void empilhar(Pilha *p, int x) {
	Nodo *novo = (Nodo*) malloc(sizeof(Nodo));
	novo->info = x;
	novo->prox = p->topo;
	p->topo = novo;
}

int tamanho(Pilha *p) {
	Nodo *aux = p->topo;
	int count = 0;
	while(aux!=NULL) {
		count++;
		aux = aux->prox;
	}
	return count;
}

int topo(Pilha *p) {
	if(p->topo == NULL) {
		return -1;
	}
	Nodo *aux = p->topo;
	int tp = aux->info;
	return tp;
}

void imprimir(Pilha *p) {
	Nodo *aux = p->topo;
	printf("[ ");
	while(aux!=NULL) {
		int inf = aux->info;
		printf("%d ",inf);
		aux = aux->prox;
	}
	printf("]\n");
}

