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

#include "JVida_BGLL_Projeto_Model.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void mostrarMatriz(int dim);
int validarDim(int dimMundo);
void perguntarDim();
void perguntarCoordenadas();
int retirarCel(int linhas, int colunas, int dim);
void mostrarSitGeracao(int qtdCelViva,int geracaoAtual);
int menu();
void interacoesMenu(int opcao);
void limparBuffer();
void limparTela();
int mensagemCoordenada(int status);
void perguntarQtdGeracao();
void perguntarVelocidade();
void confirmacao();
void mostrarVizinhosMortos();
void mostrarVivos();
