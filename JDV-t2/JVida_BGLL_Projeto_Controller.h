/*
JVIDA-BGLL - Projeto Jogo da Vida - Etapa 1
08/10/2024 - Grupo:BGLL

Nome dos integrantes:

- Beatriz Lima Morais
- Grazielle Batista de Almeida
- Luana Gabrielle Rodrigues Macedo
- Lucas Ferri dos Santos
*/

#include "JVida_BGLL_Projeto_View.cpp"
#include "JVida_BGLL_Projeto_Model.cpp"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

void gerarSeres(int linhas, int colunas,int dim);
void limparMapa(int dim);
void tornarVazio(int l, int c);
void tornarVizinho(int l, int c);
int inserirOuRetirarCel(int linhas, int colunas, int dim);
int verificarOcupacao(int l, int c);
void guardarInfoVizinhos(int l, int c, int nC, int nL, int qtdVizinhos);
void infoVizinhos(int l, int c);
void alterarViz();
void gerarSeresAux(int linhas, int colunas);
void guardarInfoVizinhosAux(int l, int c, int nC, int nL, int qtdVizinhos);
void infoVizinhosAux(int l, int c);
int inserirCelAux(int linhas, int colunas);
int qtdVizinhosVivos(int l, int c);
int reproducao(int l, int c);
int sobrevivencia(int l, int c);
int morteFaltaComida(int l,int c);
int morteSolidao(int l, int c);
void copiarMatrizAux(int dim);
void limparMatrizAux(int dim);
void gerarAtraso();
int contarVivas(int dim);
int definirSituacaoCelula(int l, int c);
void proximaGeracao(int dim,int qtdGeracao);
int validarCoordenadas();
void jogarMenu();

