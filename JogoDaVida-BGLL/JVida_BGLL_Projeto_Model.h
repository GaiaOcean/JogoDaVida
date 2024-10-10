/*
JVIDA-BGLL - Projeto Jogo da Vida - Etapa 1
08/10/2024 - Grupo:BGLL

Nome dos integrantes:

- Beatriz Lima Morais
- Grazielle Batista de Almeida
- Luana Gabrielle Rodrigues Macedo
- Lucas Ferri dos Santos
*/

#ifndef JVIDA_BGLL_PROJETO_MODEL_H
#define JVIDA_BGLL_PROJETO_MODEL_H

#define VALORMAX 60

typedef struct{
  	char situacao;
  	int linha;
  	int coluna;
}Vizinhos;
  
typedef struct{
  	char situacao;
  	int qtdVizinhos;
  	Vizinhos infoVizinhos[8];
}Mundo;

int linhas;
int colunas;
int dim;
bool viz; // flag para mostrar ou nao os vizinhos

Mundo jdvMatriz[VALORMAX][VALORMAX];
Mundo jdvAux[VALORMAX][VALORMAX];

void inicializarMatriz60x60();
void perguntarDim();
void inicializarMatrizAux();

#endif
