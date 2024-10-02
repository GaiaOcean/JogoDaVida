/*
JVida-BGLL - Projeto Jogo da Vida - Etapa 6
24/09/2024 - Grupo:BGLL

Nome dos integrantes:

- Beatriz Lima Morais
- Grazielle Batista de Almeida
- Luana Gabrielle Rodrigues Macedo
- Lucas Ferri dos Santos
*/

#include "JVida_BGLL_Projeto_Model.h"

#include <stdio.h>
void inicializarMatriz60x60(){
	for (int i = 0; i < 60; i++)
      for (int j = 0; j < 60; j++) 
        jdvMatriz[i][j] = '.'; // Define todos as celulas como vazias inicialmente
}

void perguntarDIm(int* dim){
	
	printf("Digite a dimensao da matriz(de 10 a 60): " );
	scanf("%d",dim);
	
//	return *dim;
}
