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


void gerarSeres(int linhas, int colunas,int dim){       
    jdvMatriz[linhas][colunas].situacao = 'O';
}

int inserirOuRetirarCel(int linhas, int colunas, int dim){
	
    if ((linhas >= 0 && linhas < dim) && (colunas >= 0 && colunas < dim)){
        if (jdvMatriz[linhas][colunas].situacao == '.') {
            gerarSeres(linhas, colunas, dim);  
            return 1;  // celula inserida
        }
        else if (jdvMatriz[linhas][colunas].situacao == 'O') {
            int resultado = validarCoord(linhas, colunas, dim);
            if (resultado == 1) {
                return 2;  // celula removida
            }
        }
    }
    return 0;  // coordenadas invalidas ou nenhuma alteracao
}


//---------FUNCIONALIDADES DO MENU---------
void jogarMenu(){
	
	int opcao;
 	
	inicializarMatriz60x60();
	inicializarMatrizAux();
    perguntarDim();
    limparTela();
 	
 	do{
 		
 		opcao = menu();
 		
        switch(opcao){
            case 1:
            	limparTela();
                mostrarMatriz(dim);
                break;
            case 2:
                limparBuffer(); 
                break;
            case 3:
            	mostrarMatriz(dim);
                perguntarCoordenadas();
                inserirOuRetirarCel(linhas, colunas, dim);
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