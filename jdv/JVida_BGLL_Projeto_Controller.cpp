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
    jdvMatriz[linhas][colunas].situacao = 'O'; 
}

//---------FUNCIONALIDADES DO MENU---------
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
                limparBuffer(); 
                break;
            case 3:
            	mostrarMatriz(dim);
                perguntarCoordenadas();
                gerarSeres(linhas, colunas, dim);
                mostrarMatriz(dim);
                break;
            case 0:
                interacoesMenu(opcao);
				exit(0);
            default:
                interacoesMenu(opcao);
        }
    } while (opcao != 0);
}