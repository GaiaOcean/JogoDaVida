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

#include "JVida_BGLL_Projeto_View.cpp"
#include "JVida_BGLL_Projeto_Model.cpp"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

void gerarSeres(int linhas, int colunas,int dim);
void limparMapa(int dim);
void tornarVazio(int l, int c);
void tornarVizinhoVivoOuMorto(int l, int c);
int inserirOuRetirarCel(int linhas, int colunas, int dim);
int verificarSeCelulaVizinhaViva(int l, int c);
void definirSituacaoVizinhos(int l, int c);
void alterarViz();
void gerarSeresLista(int linhas, int colunas);
void guardarInfoVizinhosLista(int l, int c, int nC, int nL, int qtdVizinhos);
void definirEArmazenarVizinhosLista(int l, int c);
int inserirCelLista(int linhas, int colunas);
int qtdVizinhosVivos(int l, int c);
int reproducao(int l, int c);
int sobrevivencia(int l, int c);
int morteFaltaComida(int l,int c);
int morteSolidao(int l, int c);
void gerarAtraso();
int contarVivas(int dim);
int definirSituacaoCelula(int l, int c);
void proximaGeracao(int dim,int qtdGeracao);
int validarCoordenadas();
void jogarMenu();
void carregaMorto(int i, int j);
void mostrarVivos();
void liberaLista(TipoCel *aux, int tot);
void carregaVivo(int i, int j);
void alterarSituacaoVizinhoMorto();
void iniciarListas();
void armazenarInfoVizinhos();
int carrega1Morto(int i, int j);
void recuperarCels();
void deletaConf();
void limparGeracao();
void gravaCelulas();
void carregaConfig();
void alterarSituacaoVivo();
void excluiVivo(int i, int j);