/*
/*
JVIDA-BGLL - Projeto Jogo da Vida - Etapa 1
08/10/2024 - Grupo:BGLL

Nome dos integrantes:

- Beatriz Lima Morais
- Grazielle Batista de Almeida
- Luana Gabrielle Rodrigues Macedo
- Lucas Ferri dos Santos
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
