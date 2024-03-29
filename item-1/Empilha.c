#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"
#include "Empilha.h"

int inicializar(Pilha * pino1, int * discos){    
    printf("************GAME DA TORRE DE HANOI*************\n");	
    printf("INSIRA O NUMERO DE DISCOS PARA COMECAR A JOGAR:\n");
    fflush(stdin);
    scanf("%d", discos);
    if(*discos < 0){
        return 1;
    }
    int aux = *discos;
    while(aux > 0){
        empilhar(pino1, aux);    
        aux = aux - 1;    
    }
    return 2;
}
void terminar(Pilha * pino1, Pilha * pino2, Pilha * pino3){
    destruir(pino1);
    destruir(pino2);
    destruir(pino3);
}

int movimentar(Pilha * pino1, Pilha * pino2, Pilha * pino3){    
    char movimento[3] = {0,0,'\0'};
    printf("Digite o proximo movimento: \n");
    fflush(stdin);
    scanf("%c%c", movimento, movimento + 1);
    switch(movimento[0]){
        case 'A':
            switch(movimento[1]){
                case 'B':
                    if(mover(pino1, pino2) == 0)
                        return 3;
                    break;
                case 'C':
                    if(mover(pino1, pino3) == 0)
                        return 3;
                    break;
                default:
                    printf("Movimento invalido!\n");
                        return 3;
            }
            break;
        case 'B':
            switch(movimento[1]){
                case 'A':
                    if(mover(pino2, pino1) == 0)
                        return 3;
                    break;
                case 'C':
                    if(mover(pino2, pino3) == 0)
                        return 3;
                    break;
                default:
                    printf("Movimento invalido!\n");
                    return 3;
            }
            break;
        case 'C':
            switch(movimento[1]){
                case 'A':
                    if(mover(pino3, pino1) == 0)
                        return 3;
                    break;
                case 'B':
                    if(mover(pino3, pino2) == 0)
                        return 3;
                    break;
                default:
                    printf("Movimento invalido!\n");
                    return 3;
                }
                break;
        default:
            printf("Movimento invalido!\n");
            return 3;
            break;         
    }
    return 4;
}

int mover(Pilha * origem, Pilha * destino){    
    if(tamanho(origem) > 0 && (tamanho(destino) <= 0 || topo(origem) < topo(destino))){
        empilhar(destino,desempilhar(origem));
        return 1;
    }
    else {
        printf("Nao e possivel fazer este movimento.\n");
        return 0;
    }
}

void mostrarPinos(Pilha * pino1, Pilha * pino2, Pilha * pino3){
    printf("A: ");
    imprimir(pino1);
    printf("B: ");
    imprimir(pino2);
    printf("C: ");
    imprimir(pino3);
}

void mostrarPossibilidades(Pilha * pino1, Pilha * pino2, Pilha * pino3){
    printf("Voce pode fazer esses movimentos: ");
    if((topo(pino1) < topo(pino2) || tamanho(pino2) == 0) && tamanho(pino1) > 0){
            printf(" AB ");
    }
    if((topo(pino1) < topo(pino3) || tamanho(pino3) == 0) && tamanho(pino1) > 0){
            printf(" AC ");
    }
    if((topo(pino2) < topo(pino1) || tamanho(pino1) == 0) && tamanho(pino2) > 0){
            printf(" BA ");
    }
    if((topo(pino2) < topo(pino3) || tamanho(pino3) == 0) && tamanho(pino2) > 0){
            printf(" BC ");        
    }
    if((topo(pino3) < topo(pino1) || tamanho(pino1) == 0) && tamanho(pino3) > 0){
            printf(" CA ");
    }
    if((topo(pino3) < topo(pino2) || tamanho(pino2) == 0) && tamanho(pino3) > 0){
            printf(" CB ");
    }
    printf("\n");
}
