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
	
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
        	
            if (jdvMatriz[i][j].situacao == 'O' || jdvMatriz[i][j].situacao == '+') {
                jdvMatriz[i][j].situacao = '.';
            }
            
        }
    }
}

	
//int mostrarOuNaoMortas(int coluna,int linha, int dim,bool){
//	
//	if(bool == false){
//		mostrarMatriz(dim);
//	}
//	
//}

void tornarVazio(int l, int c){
	int qtdV = jdvMatriz[l][c].qtdVizinhos;
	int lV;
	int lC;
	
	for(int i = 0; i < qtdV; i++){
		lV = jdvMatriz[l][c].infoVizinhos[i].linha;
		lC = jdvMatriz[l][c].infoVizinhos[i].coluna;
		
		jdvMatriz[lV][lC].situacao = '.';
	}
}

//verifica as possibilidades de acao para a coordenada informada, de forma que,
//se a coordenada estiver vazia, ela e' ocupada e se estiver ocupada, pode ser esvaziada
int inserirOuRetirarCel(int linhas, int colunas, int dim) {
    if (jdvMatriz[linhas][colunas].situacao == '.' || jdvMatriz[linhas][colunas].situacao == '+') {
        gerarSeres(linhas, colunas, dim);  
        return 1;  // celula inserida
    }
    else if (jdvMatriz[linhas][colunas].situacao == 'O') {
    	 if( retirarCel(linhas, colunas, dim) == 1){
        	jdvMatriz[linhas][colunas].situacao = '.';
//			tornarVazio(linhas, colunas);
        	return 2;  // celula removida
        }
    }
    return 0;

}

void mostrarCelulasMortas(int linhas,int colunas, int dim){
//	if (jdvMatriz[linhas][colunas].situacao == 'O') {


       if(perguntarCelulasMortas() == 1){
			tornarVazio(linhas, colunas);
 	  	}
}



void guardarInfoVizinhos(int l, int c){
	int nL = l - 1;
	int nC = c - 1;
	int qtdVizinhos = 0;
	
	if(nL >= 0){
		for(int i = 1; i <= 3; i++){
			if(nC >= 0 || nC >= dim){
				jdvMatriz[l][c].qtdVizinhos = qtdVizinhos + 1;
				jdvMatriz[l][c].infoVizinhos[qtdVizinhos].coluna = nC;
				jdvMatriz[l][c].infoVizinhos[qtdVizinhos].linha = nL;
				if(jdvMatriz[nL][nC].situacao != 'O'){
					jdvMatriz[nL][nC].situacao = '+';
					jdvMatriz[l][c].infoVizinhos[qtdVizinhos].situacao = jdvMatriz[nL][nC].situacao;
				}
				qtdVizinhos = qtdVizinhos + 1;
			}
			nC = nC + 1;
		}
	}
	
	
	nL = l + 1;
	nC = c - 1;
	
	if(nL < dim){
		for(int i = 1; i <= 3; i++){
			if(nC >= 0){
				jdvMatriz[l][c].qtdVizinhos = qtdVizinhos + 1;
				jdvMatriz[l][c].infoVizinhos[qtdVizinhos].coluna = nC;
				jdvMatriz[l][c].infoVizinhos[qtdVizinhos].linha = nL;
				if(jdvMatriz[nL][nC].situacao != 'O'){
					jdvMatriz[nL][nC].situacao = '+';
					jdvMatriz[l][c].infoVizinhos[qtdVizinhos].situacao = jdvMatriz[nL][nC].situacao;
				}
				qtdVizinhos = qtdVizinhos + 1;
			}
			nC = nC + 1;
		}
	}
	
	nL = l;
	nC = c + 1;
	
	if(nC < dim){
		jdvMatriz[l][c].qtdVizinhos = qtdVizinhos + 1;
		jdvMatriz[l][c].infoVizinhos[qtdVizinhos].coluna = nC;
		jdvMatriz[l][c].infoVizinhos[qtdVizinhos].linha = nL;
		if(jdvMatriz[nL][nC].situacao != 'O'){
			jdvMatriz[nL][nC].situacao = '+';
			jdvMatriz[l][c].infoVizinhos[qtdVizinhos].situacao = jdvMatriz[nL][nC].situacao;
		}
		qtdVizinhos = qtdVizinhos + 1;
	}
	
	nC = c - 1;
	
	if(nC >= 0){
		jdvMatriz[l][c].qtdVizinhos = qtdVizinhos + 1;
		jdvMatriz[l][c].infoVizinhos[qtdVizinhos].coluna = nC;
		jdvMatriz[l][c].infoVizinhos[qtdVizinhos].linha = nL;
		if(jdvMatriz[nL][nC].situacao != 'O'){
			jdvMatriz[nL][nC].situacao = '+';
			jdvMatriz[l][c].infoVizinhos[qtdVizinhos].situacao = jdvMatriz[nL][nC].situacao;
		}
		qtdVizinhos = qtdVizinhos + 1;
	}
}

//int validarCoordenadas(){
//	
//	do{
//		perguntarCoordenadas();
//		if (linhas == dim && colunas == dim){
//			return -1;
//		}
//		if ((linhas < 0 || linhas >= dim) || (colunas < 0 || colunas >= dim)) {
//            printf("Coordenada invalida! Tente novamente.\n");  // Exibe a mensagem de erro
//        } else {
//        	guardarInfoVizinhos(linhas,colunas);
//            return 0;  // Coordenadas validas
//        }
//	}while(1);
//        
//}



//---------FUNCIONALIDADES DO MENU---------
void jogarMenu(){

	int opcao;
 	
	inicializarMatriz60x60();
    perguntarDim();
    limparTela();
 	mostrarMatriz(dim);
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
                    validarCoordenadas();
                    inserirOuRetirarCel(linhas, colunas, dim);
                }
                linhas = 0, colunas = 0;
                mostrarMatriz(dim);
                break;
            case 4:
            	mostrarMatriz(dim);
            	perguntarCelulasMortas();
            	mostrarCelulasMortas(linhas, colunas, dim);
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
