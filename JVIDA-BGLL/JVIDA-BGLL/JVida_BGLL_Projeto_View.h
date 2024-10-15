/*
JVIDA-BGLL - Projeto Jogo da Vida - Etapa 2
15/10/2024 - Grupo:BGLL

Nome dos integrantes:

- Beatriz Lima Morais
- Grazielle Batista de Almeida
- Luana Gabrielle Rodrigues Macedo
- Lucas Ferri dos Santos

O Controller.h contem os prototipos das funcoes presentes no View.cpp

*/

#include "JVida_BGLL_Projeto_Model.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void mostrarMatriz(int dim);
void inicializarMatriz60x60();
void perguntarDim();
void perguntarCoordenadas();
int retirarCel(int linhas, int colunas, int dim);
int menu();
void interacoesMenu(int opcao);
void limparBuffer();
void limparTela();
int mensagemCoordenada(int status);
