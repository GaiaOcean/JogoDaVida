/*
JVIDA-BGLL - Projeto Jogo da Vida - Etapa 1
08/10/2024 - Grupo:BGLL

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

//Funcao responsavel por limpar o mapa
void limparMapa(int dim) {
	
//    printf("Limpando o mapa...\n"); 
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
        	
            if (jdvMatriz[i][j].situacao == 'O') {
                jdvMatriz[i][j].situacao = '.';
            }
            
        }
    }
}

int inserirOuRetirarCel(int linhas, int colunas, int dim) {
    if (jdvMatriz[linhas][colunas].situacao == '.') {
        gerarSeres(linhas, colunas, dim);  
        return 1;  // celula inserida
    }
    else if (jdvMatriz[linhas][colunas].situacao == 'O') {
    	 if(retirarCel(linhas, colunas, dim) == 1){
        	jdvMatriz[linhas][colunas].situacao = '.';  
        	return 2;  // celula removida
        }
    }
    return 0;  // nenhuma alteracao feita
}



//---------FUNCIONALIDADES DO MENU---------
void jogarMenu(){

	int opcao;
 	
	inicializarMatriz60x60();
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
                limparMapa(dim);
                mostrarMatriz(dim);
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