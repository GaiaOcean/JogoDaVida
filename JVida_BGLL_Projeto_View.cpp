/*
JVida-BGLL - Projeto Jogo da Vida - Etapa 6
24/09/2024 - Grupo:BGLL

Nome dos integrantes:

- Beatriz Lima Morais
- Grazielle Batista de Almeida
- Luana Gabrielle Rodrigues Macedo
- Lucas Ferri dos Santos
*/

#include "JVida_BGLL_Projeto_View.h"

void mostrarMatriz(int dim){
	printf("\t");
    for (int j = 0; j < dim; j++)
      printf("%02d ", j);
    printf("\n\n");
	
	for (int i = 0; i < dim; i++){
		printf("%d\t", i);
      	for (int j = 0; j < dim; j++) 
        	printf("%c  ", jdvMatriz[i][j]);
        printf("\n");
	}	  
}

void perguntarDim(){
	printf("Digite a dimensao do mundo(de 10 a 60): " );
	scanf("%d", &dim);
	
	printf("\n");
}

void perguntarCoordenadas(){
	printf("Digite as coordenadas (x y): ");
    scanf("%d %d", &linhas, &colunas);
    printf("\n");	
}

int menu(){
	int opcao;

	printf("\n======= JOGO DA VIDA =======\n");
    printf("1 - Apresentar Mapa\n");
    printf("2 - Limpar Mapa\n");
    printf("3 - Incluir celula / excluir celulas\n");
    printf("0 - Sair\n");  
    printf("=============================\n");
    printf("Escolha uma opcao: \n");
    scanf("%d", &opcao);
    
    limparBuffer();
    
    return opcao;
}

//void interacoesMenu(int opcao){
//    if(opcao == 0){
//        printf("Saindo do jogo...\n");
//    } else if(opcao < 0 || opcao > 3) {
//        printf("Opcao invalida. Tente novamente.\n");
//    }
//}
void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
