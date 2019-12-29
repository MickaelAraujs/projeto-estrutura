#include<stdio.h>
#include<stdlib.h>

#include "processo.h"
#include "fila.h"

int main(void) {
	Fila *f = criaFila();
	
	int k;
	for(k=1;k<=5;k++) {
		push(f,k);
	}

	imprimeFila(f);

	liberaFila(f);

	return 0;
}
