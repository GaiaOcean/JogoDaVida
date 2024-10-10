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
int inserirOuRetirarCel(int linhas, int colunas, int dim);
void jogarMenu();
void limparMapa(int dim);
void alterarViz(bool viz);
void mostrarVizinhos(bool viz);
