/*
JVIDA-BGLL - Projeto Jogo da Vida - Etapa 5
12/11/2024 - Grupo:BGLL

Nome dos integrantes:

- Beatriz Lima Morais
- Grazielle Batista de Almeida
- Luana Gabrielle Rodrigues Macedo
- Lucas Ferri dos Santos

	A etapa 5 consiste em salvar e recuperar geracoes salvas anteriormente pelo usuario a partir 
	da utilizacao de listas ligadas.


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

//----------------------Gravacao/Recuperacao de cels vivas-------------------------------
typedef struct c{
	int lin, col;
}Cel;

typedef struct list{
	int tamanhoList;//pode ser ate 400 cel vivas
	Cel L[400];
}TipoLista;

TipoLista Lvivo; //struct sem ponteiros

//lConfig[50];//grava ate 50 listas de cel vivas iniciais
int qtdConf = 0;//quantidade de configuracoes iniciais
int ultimarecup = -1;//indice da ultima configuracao recuperada (de 0 a 49)

struct arquivo{
	int i; //linhas
	int j; //colunas
	TipoLista TL; //1 lista total
	int geracao;
}LConfig[50];

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
int qtdCelViva = 0;


Mundo jdvMatriz[VALORMAX][VALORMAX];
void inicializarMatriz60x60();
int contarEGuardarVizinhos(int l, int c);
void guardarInformacoesVizinhos(int l, int c, int nC, int nL, int qtdVizinhos);

#endif
