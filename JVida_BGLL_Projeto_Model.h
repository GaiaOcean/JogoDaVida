/*
JVIDA-BGLL - Projeto Jogo da Vida - Etapa 4
05/11/2024 - Grupo:BGLL

Nome dos integrantes:

- Beatriz Lima Morais
- Grazielle Batista de Almeida
- Luana Gabrielle Rodrigues Macedo
- Lucas Ferri dos Santos

	A etapa 4 consiste de substituir a matriz auxiliar utilizada previamente 
	por uma lista ligada, uma vez que a lista ligada faz um uso mais eficiente da memoria.	

*/

#ifndef JVIDA_BGLL_PROJETO_MODEL_H
#define JVIDA_BGLL_PROJETO_MODEL_H

#define VALORMAX 60
#define FALSE 0
#define TRUE 1
#define VIVO 'O'
#define MORTO '.'
#define VIZINHO '+'


bool fviz = FALSE;

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


Mundo jdvMatriz[VALORMAX][VALORMAX];
void inicializarMatriz60x60();
int contarEGuardarVizinhos(int l, int c);
void guardarInformacoesVizinhos(int l, int c, int nC, int nL, int qtdVizinhos);

#endif