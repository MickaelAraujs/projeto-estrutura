#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "processo.h"
#include "fila.h"

#define TAM 10

int main(void) {
	printf("TESTANDO IMPLEMENTACAO:\n\n\n");
	
	Fila *f = criaFila();
	
	int vet[TAM];
	gerarNumeros(vet);
	int k;
	for(k=0;k<TAM;k++) {
		int num = buscaIndice(k,vet);
		push(f,k,num);
	}
	
	imprimeFila(f);
	liberaFila(f);

	return 0;
}
