/*
JVida-BGLL - Projeto Jogo da Vida - Etapa 6
24/09/2024 - Grupo:BGLL

Nome dos integrantes:

- Beatriz Lima Morais
- Grazielle Batista de Almeida
- Luana Gabrielle Rodrigues Macedo
- Lucas Ferri dos Santos
*/

#include "JVida_BGLL_Projeto_Controller.cpp"

int main(){
  inicializarMatriz60x60();
  perguntarDim();
  mostrarMatriz(dim);
  perguntarCoordenadas();
  gerarSeres(linhas,colunas,dim);
  mostrarMatriz(dim);
  
  return 0;
}
