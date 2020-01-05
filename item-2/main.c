#include <stdio.h>
#include <stdlib.h>

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
					
					printf("\nInforme o ID do processo a ser realizado:");
					scanf("%d",&id);
					
					indice = rand()%TAM;
					
					int tempo = buscaIndice(indice,vet);
					push(f,id,tempo);
				
					break;
		}
		case 2:{
			int id = pegarIDPrimeiro(f);
			removeProcesso(f,id);
			break;
		}
		case 3:{
			int id;
			printf("Informe o ID do processo que deseja remover:");
			scanf("%d",&id);
			Nodo*aux = procuraIndice(f,id);
			if(aux == NULL){
				printf("ID invalido");
			}
			else{
				removeProcesso(f,id);
				printf("Processo removido com sucesso");
			}
			break;
		}
		case 4: maiorTempoEspera(f); break;
		case 5: imprimeFila(f); break;
		case 6: liberaFila(f); break;
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
		printf("2. Remover o primeiro processo da fila\n\n");
		printf("3. Remover um processo inserindo o id dele\n\n");
		printf("4. Liberar processo com maior tempo de espera\n\n");
		printf("5. Imprimir fila de processos\n\n");
		printf("6. Liberar todos os processos da fila\n\n");
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
