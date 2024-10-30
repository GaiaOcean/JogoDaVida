/*
JVIDA-BGLL - Projeto Jogo da Vida - Etapa 3
29/10/2024 - Grupo:BGLL

Nome dos integrantes:

- Beatriz Lima Morais
- Grazielle Batista de Almeida
- Luana Gabrielle Rodrigues Macedo
- Lucas Ferri dos Santos
*/

#ifndef JVIDA_BGLL_PROJETO_MODEL_H
#define JVIDA_BGLL_PROJETO_MODEL_H

#define VALORMAX 60

//Estrutura responsavel por guardar a linha e a coluna de todas as celulas que forem vizinhas de uma celula viva
typedef struct{
  	int linha;
  	int coluna;
}Vizinhos;

//Estrutura para guardar as informacoes de todas as celulas
typedef struct{
  	char situacao;
  	int qtdVizinhos;
  	Vizinhos infoVizinhos[8];
}Mundo;

typedef struct cel{
	int lin, col;
	struct cel *prox;
}TipoCel;

TipoCel *pvivo, *pmorto, *pvivoprox;
int totvivo, totmorto, totvivoprox;

int linhas;
int colunas;
int dim;
bool viz;
int atraso;
int velocidade;
int qtdGeracao;
int geracaoAtual = 0; 
char conf;
int qtdVivas = 0;
Vizinhos celVivas[60];


Mundo jdvMatriz[VALORMAX][VALORMAX];
Mundo jdvAux[VALORMAX][VALORMAX];
void perguntarDim();
void inicializarMatriz60x60();
void inicializarMatrizAux();
int contarVizinhos(int l, int c);
void inicializarQuantidadeVizinhos(int l, int c, int nC, int nL, int qtdVizinhos);

#endif
