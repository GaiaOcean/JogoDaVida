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
    if(linhas == dim || colunas == dim){
        return 0; // nrnhuma alteração feita
    }
    else if (jdvMatriz[linhas][colunas].situacao == '.') {
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

void checarVizinhas(int dim){
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(jdvMatriz[i][j].situacao == 'O'){
                if(i-1 >= 0 && i+1 < dim && j-1 >= 0 && j+1 < dim && jdvMatriz[i][j].situacao != 'O'){
                    jdvMatriz[i][j+1].situacao = '+';
                    jdvMatriz[i][j-1].situacao = '+';
                    jdvMatriz[i+1][j].situacao = '+';
                    jdvMatriz[i+1][j+1].situacao = '+';
                    jdvMatriz[i+1][j-1].situacao = '+';
                    jdvMatriz[i-1][j].situacao = '+';
                    jdvMatriz[i-1][j+1].situacao = '+';
                    jdvMatriz[i-1][j-1].situacao = '+';
                }
                if (i == 0){ //linha i = 0
                    if(j == 0){ // i = 0, e j = 0;
                        jdvMatriz[i][j+1].situacao = '+';
                        jdvMatriz[i+1][j].situacao = '+';
                        jdvMatriz[i+1][j+1].situacao = '+';
                    }
                     if(j == dim-1){ // i = 0, e j = dim-1;
                        jdvMatriz[i][j-1].situacao = '+';
                        jdvMatriz[i+1][j].situacao = '+';
                        jdvMatriz[i+1][j-1].situacao = '+';
                    }
                    jdvMatriz[i][j-1].situacao = '+';
                    jdvMatriz[i][j+1].situacao = '+';
                    jdvMatriz[i+1][j].situacao = '+';
                    jdvMatriz[i+1][j-1].situacao = '+';
                    jdvMatriz[i+1][j+1].situacao = '+';
                }
                if (i == dim-1){ //linha i = dim-1
                    if(j == 0){ // i = dim-1, e j = 0;
                        jdvMatriz[i][j+1].situacao = '+';
                        jdvMatriz[i-1][j].situacao = '+';
                        jdvMatriz[i-1][j+1].situacao = '+';
                    }
                     if(j == dim-1){ // i = dim-1, e j = dim-1;
                        jdvMatriz[i][j-1].situacao = '+';
                        jdvMatriz[i-1][j].situacao = '+';
                        jdvMatriz[i-1][j-1].situacao = '+';
                    }
                    jdvMatriz[i][j-1].situacao = '+';
                    jdvMatriz[i][j+1].situacao = '+';
                    jdvMatriz[i+1][j].situacao = '+';
                    jdvMatriz[i+1][j-1].situacao = '+';
                    jdvMatriz[i+1][j+1].situacao = '+';
                }
                
            }
        }
    }
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
                while(linhas != dim || colunas != dim){    
                    mostrarMatriz(dim);
                    perguntarCoordenadas();
                    inserirOuRetirarCel(linhas, colunas, dim);
                }
                linhas = 0, colunas = 0;
                mostrarMatriz(dim);
                break;
            case 4:
                checarVizinhas(dim);
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

