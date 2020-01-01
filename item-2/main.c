#include<stdio.h>
#include<stdlib.h>

#include "processo.h"
#include "fila.h"

#define TAM 10

//Grupo1: Denis Ferreira, Luciana Ferreira e Mickael Araujo.

void menu(int opcao) {
	Fila *f = criaFila();
	
	system("cls");
	switch(opcao){
		case 1:{
			int id, j;
			int vet[TAM];
			
			printf("\nInforme o id do processo:");
			scanf("%d", &id);
			
			printf("\nInforme um numero entre 1 e 10:");
			scanf("%d", &j);
			gerarNumeros(vet);
			int tempo = buscaIndice(j, vet);
			
			push(f, id, tempo);
			
			break;
		}
		case 2:{
			maiorTempoEspera(f);
			system("pause");
			break;
		}
		case 3:{
			imprimeFila(f);
			system("pause");
			break;
		}
		case 0:{
			break;
		}
	}
}

int main(void) {
	int opcao;
	
	do {
		system("cls");
		
		printf("******* DIGITE O NUMERO CORRESPONDENTE A UMA DAS OPCOES ABAIXO *******\n\n");
		printf("1. Adicionar processo a fila de espera\n\n");
		printf("2. Liberar processo com maior tempo de espera\n\n");
		printf("3. Imprimir fila de processos\n\n");
		printf("0. Sair\n\n");
		printf("**********************************************************************\n\n");
	
		scanf("%d",&opcao);
		
		menu(opcao);
	} while(opcao!=0);
	
	return 0;
}
