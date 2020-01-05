#include "processo.h"

//criando TAD nodo
typedef struct nodo Nodo;

//criando TAD fila
typedef struct fila Fila;

//criando nova fila, retorna um ponteiro para uma fila
Fila *criaFila();

//retorna o tamanho da fila
int tamanhoFila(Fila *f);

//adicionar elemento ao final da fila
void push(Fila *f,int id,int tempo);

//imprime todos os elementos da fila
void imprimeFila(Fila *f);

//libera todos os elementos da fila, chamando a função liberaProcesso contido em processo.h
void liberaFila(Fila *f);

//retira da fila os processos
void removeProcesso(Fila *f, int id);

Nodo *pegaAnterior(Fila*f, Nodo*aux, Nodo*anterior);

void maiorTempoEspera(Fila *f);

int vazia(Fila *f);

int pegarIDPrimeiro(Fila *f);

//busca o processo pelo id e retorna um  poteiro que aaponta para o mesmo
Nodo *procuraIndice(Fila *f, int id);
