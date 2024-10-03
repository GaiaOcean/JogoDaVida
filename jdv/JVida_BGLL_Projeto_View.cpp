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
      printf("%02d ", j);
    printf("\n\n");
	
	for (int i = 0; i < dim; i++){
		printf("%d\t", i);
      	for (int j = 0; j < dim; j++) 
        	printf("%c  ", jdvMatriz[i][j]);
        printf("\n");
	}	  
}

void perguntarDim(){
	printf("Digite a dimensao do mundo(de 10 a 60): " );
	scanf("%d", &dim);
	
	printf("\n");
}

void perguntarCoordenadas(){
	printf("Digite as coordenadas (x y): ");
    scanf("%d %d", &linhas, &colunas);
    printf("\n");	
}