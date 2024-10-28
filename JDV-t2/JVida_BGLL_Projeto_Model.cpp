/*
JVIDA-BGLL - Projeto Jogo da Vida - Etapa 3
28/10/2024 - Grupo:BGLL

Nome dos integrantes:

- Beatriz Lima Morais
- Grazielle Batista de Almeida
- Luana Gabrielle Rodrigues Macedo
- Lucas Ferri dos Santos

	A etapa 3 consiste de criar uma simulacao da evolucao das celulas ao longo de varias geracoes
	Esta simulacao sera realizada com o auxilio de uma matriz auxiliar
	O usuario pod definir a quantidade de geracao a serem simuladas
	tembem deve ser possivel ajustar a velocidade com que as geracoes seram exibidas.
	
*/

#include "JVida_BGLL_Projeto_Model.h"

void inicializarMatriz60x60(){
	for (int i = 0; i < 60; i++)
      for (int j = 0; j < 60; j++) {
      	jdvMatriz[i][j].situacao = '.'; // Define todos as celulas como vazias inicialmente
      	jdvMatriz[i][j].qtdVizVivos = 0; //Define todas as celulas como sem vizinhos-vivos
	  } 
        
}

void inicializarMatrizAux(){
	for (int i = 0; i < 60; i++)
      for (int j = 0; j < 60; j++) 
        jdvAux[i][j].situacao = '.'; // Define todos as celulas como vazias inicialmente
}
