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

int inserirOuRetirarCel(int linhas, int colunas, int dim) {
    if (jdvMatriz[linhas][colunas].situacao == '.') {
        gerarSeres(linhas, colunas, dim);  
        return 1;  // celula inserida
    }
    else if (jdvMatriz[linhas][colunas].situacao == 'O') {
    	 if(validarCoord(linhas, colunas, dim) == 1){
        	jdvMatriz[linhas][colunas].situacao = '.';  // celula removida
        	return 2;  // celula removida
        }
    }
    return 0;  // nenhuma alteracao feita
}



//---------FUNCIONALIDADES DO MENU---------
void jogarMenu(){
	
	int resultado;
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
                resultado = inserirOuRetirarCel(linhas, colunas, dim);
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