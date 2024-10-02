/*
JVida-BGLL - Projeto Jogo da Vida - Etapa 6
24/09/2024 - Grupo:BGLL

Nome dos integrantes:

- Beatriz Lima Morais
- Grazielle Batista de Almeida
- Luana Gabrielle Rodrigues Macedo
- Lucas Ferri dos Santos
*/

#include "JVida_BGLL_Projeto_View.h"

void mostrarMatriz(int dim){
	printf("\t");
    for (int j = 0; j < dim; j++)
      printf("%2d ", j);
    printf("\n\n");
	
	for (int i = 0; i < dim; i++){
		printf("%d\t", i);
      	for (int j = 0; j < dim; j++) 
        	printf("%c  ", jdvMatriz[i][j]);
        printf("\n");
	}	  
}