/*
JVIDA-BGLL - Projeto Jogo da Vida - Etapa 1
08/10/2024 - Grupo:BGLL

Nome dos integrantes:

- Beatriz Lima Morais
- Grazielle Batista de Almeida
- Luana Gabrielle Rodrigues Macedo
- Lucas Ferri dos Santos
*/

#include "JVida_BGLL_Projeto_View.h"

void mostrarMatriz(int dim){
	limparTela();
	printf("\t");
    for (int j = 0; j < dim; j++)
      printf("%02d ", j);
    printf("\n\n");
	
	for (int i = 0; i < dim; i++){
		printf("%02d\t", i);
      	for (int j = 0; j < dim; j++) 
        	printf("%c  ", jdvMatriz[i][j].situacao);
        printf("\n");
	}	  
}

// -----------FUNCOES DE VALIDACOES-----------
int validarDim(int dimMundo){
	if(dimMundo < 10 || dimMundo > 60){
		printf("Dimensao invalida.\n"); 
		return -1;
	}
	
	dim = dimMundo;
	return 1;
}

int retirarCel(int linhas, int colunas, int dim) {
	
    char escolha;

    //Ve se a celula ja existe e remove a mesma caso o usuario digite 'S'
    if (jdvMatriz[linhas][colunas].situacao == 'O') {
        printf("A coordenada ja existe. Deseja remover a celula do mapa (Digite S ou N)? ");
        scanf(" %c", &escolha);

        if (escolha == 'S' || escolha == 's') {
	        printf("A celula %d%d foi removida do mundo.", linhas,colunas);
            return 1; // celula removida do mundo
        } 
    }
    return 0; 
}

//-----------INTERACOES COM JOGADOR-----------

void perguntarDim(){
	int dimMundo;
	do{
		printf("\n======= JOGO DA VIDA =======\n");
		printf("Digite a dimensao do mundo(de 10 a 60): " );
		scanf("%d", &dimMundo);
		
		
	}while(validarDim(dimMundo) != 1);
}

void perguntarCoordenadas() {
    int res;  // armazena o resultado da validaçao
    do {
        printf("Digite as coordenadas (x y) ou (%d %d para sair): ", dim, dim);
        scanf("%d %d", &linhas, &colunas);
        printf("\n");
        limparBuffer();
        
        // Verifica se as coordenadas estao dentro dos limites
        if (linhas == dim|| colunas == dim){
            res = 0;
        }else if ((linhas < 0 || linhas >= dim) || (colunas < 0 || colunas >= dim)) {
            printf("Coordenada invalida! Tente novamente.\n");  // Exibe a mensagem de erro
            res = -1;  // Coordenadas invalidas
        } else {
            res = 0;  // Coordenadas validas
        }
    } while (res == -1);  //  continua pedindo ata receber coordenadas validas

   // mostrarMatriz(dim);  
}


//--------------FUNCIONALIDADES DO MENU------------

int menu(){
	int opcao;

	printf("\n======= JOGO DA VIDA =======\n");
    printf("1 - Apresentar Mapa\n");
    printf("2 - Limpar Mapa\n");
    printf("3 - Incluir celula / excluir celulas\n");
    printf("0 - Sair\n");  
    printf("=============================\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    limparBuffer();
    return opcao;
}

void interacoesMenu(int opcao){
    if(opcao == 0){
        printf("Saindo do jogo...\n");
    } else if(opcao < 0 || opcao > 4) {
        printf("Opcao invalida. Tente novamente.\n");
    }
}

//--------------FUNCOES LIMPAR-----------
void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void limparTela(){
	system("cls||clear");
}
