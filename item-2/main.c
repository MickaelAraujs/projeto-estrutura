#include<stdio.h>
#include<stdlib.h>

#include "processo.h"
#include "fila.h"

#define TAM 10

void menu(int opcao) {
	Fila *f = criaFila();
	
	system("cls");
	printf("\n continue ai \n\n");
	system("pause");
}

int main(void) {
	int opcao;
	
	do {
		system("cls");
		
		printf("===================== DIGITE O NUMERO CORRESPONDENTE A UMA DAS OPCOES ABAIXO ======================\n\n");
		printf("1. Adicionar processo a fila de espera");
		printf("\n\n");
		printf("2. Liberar processo com maior tempo de espera");
		printf("\n\n");
		printf("3. Imprimir fila de processos");
		printf("\n\n");
		printf("0. Sair");
		printf("\n\n");
		printf("=======================================================================================================\n\n");
	
		scanf("%d",&opcao);
		
		menu(opcao);
	} while(opcao!=0);
	
	return 0;
}
