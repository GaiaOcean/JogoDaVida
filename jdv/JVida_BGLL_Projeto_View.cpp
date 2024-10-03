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
        	printf("%c  ", jdvMatriz[i][j].situacao);
        printf("\n");
	}	  
}

int validarDim(int dimMundo){
	if(dimMundo < 10 || dimMundo > 60){
		printf("Dimensao invalida.\t"); 
		return -1;
	}
	
	dim = dimMundo;
	return 1;
}

int validarCoord(int linhas, int colunas){
	
	char escolha;
	
	if((linhas >= 0 && linhas < dim)&&(colunas >= 0 && colunas < dim)){ //verifica se as coordenas sao validas
		if (jdvMatriz[linhas][colunas].situacao == 'O'){

			printf("A coordenada já existe. Deseja remover a célula do mapa (Digite S ou N)? ");
            scanf(" %c", &escolha);
			
			if (escolha == 'S' || escolha == 's') {
                jdvMatriz[linhas][colunas].situacao = '.';
                printf("Célula removida.\n");
                return 1;
			}
		}
	}
	
	return -1;
	
}

void perguntarDim(){
	int dimMundo;
	do{
		printf("Digite a dimensao do mundo(de 10 a 60): " );
		scanf("%d", &dimMundo);
		
		printf("\n");
	}while(validarDim(dimMundo) != 1);
}

void perguntarCoordenadas(){
	printf("Digite as coordenadas (x y): ");
    scanf("%d %d", &linhas, &colunas);
    printf("\n");	
    
    validarCoord(linhas, colunas);
    
}

