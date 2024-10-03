/*
JVida-BGLL - Projeto Jogo da Vida - Etapa 6
24/09/2024 - Grupo:BGLL

Nome dos integrantes:

- Beatriz Lima Morais
- Grazielle Batista de Almeida
- Luana Gabrielle Rodrigues Macedo
- Lucas Ferri dos Santos
*/

#include "JVida_BGLL_Projeto_Controller.h"

//void gerarSeres(int linha, int coluna){
//	
//	jdvMatriz[linha][coluna].situacao = 'O';
//	mostrarMatriz(dim);
//	
//	
//}

void gerarSeres(int linhas, int colunas,int dim){       
    jdvMatriz[linhas][colunas] = 'O'; 
}

void jogarMenu(){
	
	int opcao;
 	
 	do{
 		
 		opcao = menu();
 		
        switch(opcao){
            case 1:
                inicializarMatriz60x60();
                perguntarDim();
                mostrarMatriz(dim);
                break;
            case 2:
                fclearBuffer(); 
                break;
            case 3:
            	mostrarMatriz(dim);
                perguntarCoordenadas();
                gerarSeres(linhas, colunas, dim);
                mostrarMatriz(dim);
                break;
            case 0:
                exit(0);
            default:
                printf("opcao invalida\n");
        }
    } while (opcao != 0);
}

void fclearBuffer(){ 
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

               