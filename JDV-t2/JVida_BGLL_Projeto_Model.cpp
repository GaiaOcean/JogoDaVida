/*
JVIDA-BGLL - Projeto Jogo da Vida - Etapa 3
28/10/2024 - Grupo:BGLL

Nome dos integrantes:

- Beatriz Lima Morais
- Grazielle Batista de Almeida
- Luana Gabrielle Rodrigues Macedo
- Lucas Ferri dos Santos

	A etapa 3 consiste de criar uma simulacao da evolucao das celulas ao longo de varias geracoes
	Esta simulacao sera realizada com o auxilio de uma matriz auxiliar
	O usuario pod definir a quantidade de geracao a serem simuladas
	tembem deve ser possivel ajustar a velocidade com que as geracoes seram exibidas.
	
*/

#include "JVida_BGLL_Projeto_Model.h"
int contarVizinhos(int l, int c){
	int nL = l - 1; //Inicia com a linha acima da coordenada informada
	int nC = c - 1; //Inicia com a coluna a esquerda da coordenada informada
	int qtdVizinhos = 0;
	
	//Verifica se a linha acima da coordenada informada e' valida 
	if(nL >= 0){
	//Caso seja, verifica se a coluna, nas 3 posicoes possiveis, e' valida, se for, altera sua situacao para 'vizinha-morta'
		for(int i = 1; i <= 3; i++){
			if(nC >= 0 && nC < dim){
				jdvMatriz[l][c].qtdVizinhos = jdvMatriz[l][c].qtdVizinhos + 1;
				qtdVizinhos = qtdVizinhos + 1;
			}
			nC = nC + 1; //a cada rodada do loop, segue uma coluna para a direita ate que as 3 possibilidades de colunas vizinhas sejam verificadas
		}
	}
	
	nL = l + 1; //linha abaixo da coordenada informada
	nC = c - 1;
	
	//Em seguida, realiza as mesmas verificacoes nas celulas vizinhas da linha abaixo da coordenada, se esta existir
	if(nL < dim){
		for(int i = 1; i <= 3; i++){
			if(nC >= 0 && nC < dim){
				jdvMatriz[l][c].qtdVizinhos = jdvMatriz[l][c].qtdVizinhos + 1;
				qtdVizinhos = qtdVizinhos + 1;
			}
			nC = nC + 1;
		}
	}
	
	//Apos verificar ambas as linhas,
	//verifica se as celulas imediatamente a esquerda e a direita da coordenada existem e, se sim, altera sua situacao para 'vizinha-morta'
	
	nL = l; //linha da coordenada
	nC = c + 1; //coluna a direita da coordenada
	
	if(nC < dim){
		jdvMatriz[l][c].qtdVizinhos = jdvMatriz[l][c].qtdVizinhos + 1;
		qtdVizinhos = qtdVizinhos + 1;
	}
	
	nC = c - 1;//coluna a esquerda
	
	if(nC >= 0){
		jdvMatriz[l][c].qtdVizinhos = jdvMatriz[l][c].qtdVizinhos + 1;
		qtdVizinhos = qtdVizinhos + 1;
	}
	
	return 1;
}



void inicializarMatriz60x60(int dim){
	for (int i = 0; i < 60; i++){	
      for (int j = 0; j < 60; j++) {
      	jdvMatriz[i][j].situacao = '.'; // Define todos as celulas como vazias inicialmente
      	jdvMatriz[i][j].qtdVizinhos = 0;
	  }
	}
	  
	for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            contarVizinhos(i,j);
        }
    }
    
}


void inicializarMatrizAux(){
	for (int i = 0; i < 60; i++)
      for (int j = 0; j < 60; j++) 
        jdvAux[i][j].situacao = '.'; // Define todos as celulas como vazias inicialmente
}
