#include "processo.h"

//criando TAD fila
typedef struct fila Fila;

//criando nova fila, retorna um ponteiro para uma fila
Fila *criaFila();

//adicionar elemento ao final da fila
void push(Fila *fila,int id);

//imprime todos os elementos da fila
void imprimeFila(Fila *fila);

//libera todos os elementos da fila, chamando a função liberaProcesso contido em processo.h
void liberaFila(Fila *fila);
