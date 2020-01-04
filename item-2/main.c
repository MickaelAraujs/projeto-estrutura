#include<stdio.h>
#include<stdlib.h>

#include "processo.h"
#include "fila.h"

#define TAM 10

//Grupo1: Denis Ferreira, Luciana Ferreira e Mickael Araujo.

void menu(int opcao,Fila *f) {
	switch(opcao) {
		case 1: {
					int id,indice;
					int vet[TAM];
					gerarNumeros(vet);
					
					printf("informe o ID do processo a ser realizado:\n");
					scanf("%d",&id);
					
					indice = rand()%TAM;
					
					int tempo = buscaIndice(indice,vet);
					push(f,id,tempo);
				
					break;
		}
		case 2: maiorTempoEspera(f); break;
		case 3: imprimeFila(f); break;
		case 4: liberaFila(f); break;
		case 0: break;
		default: printf("OPCAO INVALIDA!!\n\n");
	}
	system("pause");
}

int main(void) {
	Fila *f = criaFila();
	
	int opcao;
	
	do {
		system("cls");
		
		printf("******* DIGITE O NUMERO CORRESPONDENTE A UMA DAS OPCOES ABAIXO *******\n\n");
		printf("1. Adicionar processo a fila de espera\n\n");
		printf("2. Liberar processo com maior tempo de espera\n\n");
		printf("3. Imprimir fila de processos\n\n");
		printf("4 . Liberar todos os processos da fila\n\n");
		printf("0. Sair\n\n");
		printf("**********************************************************************\n\n");
	
		scanf("%d",&opcao);
		
		if((opcao == 2 || opcao == 3 || opcao == 4)&&(vazia(f)==1)) {
			printf("OPCAO INVALIDA! A fila esta vazia!!\n\n");
			system("pause");
			continue;
		}
		
		system("cls");
		menu(opcao,f);
	} while(opcao!=0);
	
	return 0;
}
