#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"
#include "Empilha.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	int estado = 1;    
    int discos = 0; 
    Pilha * A = criar();
    Pilha * B = criar();
    Pilha * C = criar();
    while(estado != 1000){
        switch(estado){
			case 1 :
   	 			system("cls");//pra limpar a tela
    			estado = inicializar(A, &discos);     
   				break;
			case 2 :
   				system("cls");
   				mostrarPinos(A,B,C); 
   				mostrarPossibilidades(A,B,C); 
			case 3 :
    			estado = movimentar(A, B, C);                
        		break;            
			case 4 :
    			if(tamanho(C) == discos){
            		estado = 5;
        		}
        		else{
            		estado = 2;   
        		}
        		break;  
			case 5 :
        		terminar(A, B, C);
        		estado = 1000;
        		break;            
    	}  
    }
    printf("VOCE CONSEGUIU , VOCE E DEMAIS!!");

	return 0;
}
