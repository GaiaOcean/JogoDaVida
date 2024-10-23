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
  	int qtdVizVivos;
}Mundo; 

int linhas;
int colunas;
int dim;
bool viz;
int atraso;
int velocidade;
int qtdGeracao;
int geracaoAtual = 0; 
char conf;


Mundo jdvMatriz[VALORMAX][VALORMAX];
Mundo jdvAux[VALORMAX][VALORMAX];
void perguntarDim();
void inicializarMatrizAux();

#endif
