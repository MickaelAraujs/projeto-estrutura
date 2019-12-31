#include<stdio.h>
#include<stdlib.h>

#include "processo.h"
#include "fila.h"

//Grupo1: Denis Ferreira, Luciana Ferreira e Mickael Araujo.

int main(void) {
	printf("TESTANDO IMPLEMENTACAO:\n\n\n");
	
	Fila *f = criaFila();
	
	int k;
	for(k=0;k<5;k++) {
		push(f,k);
	}

	imprimeFila(f);
	liberaFila(f);

	return 0;
}
