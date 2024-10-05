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
		printf("Dimensao invalida.\t"); 
		return -1;
	}
	
	dim = dimMundo;
	return 1;
}

int validarCoord(int linhas, int colunas, int dim) {
	
    char escolha;

    
    if ((linhas < 0 || linhas >= dim) || (colunas < 0 || colunas >= dim)) {
        printf("Coordenadas invalidas.\n");
        return -1;  //retorna -1 quando a coordenada digitada e invalida
    }

    //Ve se a celula ja existe e remove a mesma caso o usuario digite 'S'
    if (jdvMatriz[linhas][colunas].situacao == 'O') {
        printf("A coordenada ja existe. Deseja remover a celula do mapa (Digite S ou N)? ");
        scanf(" %c", &escolha);
        limparBuffer();
        if (escolha == 'S' || escolha == 's') {
            jdvMatriz[linhas][colunas].situacao = '.';
            return 1; // Mostra que a celula foi removida do mundo
        } else {
            return 0; // o jogador nao quis remover a celula digitada
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
		
//		printf("Dimensao %d escolhida", &dimMundo);
		
	}while(validarDim(dimMundo) != 1);
}

void perguntarCoordenadas(){
	
	printf("Digite as coordenadas (x y): ");
	scanf("%d %d", &linhas, &colunas);
    printf("\n");
    
    int res = validarCoord(linhas, colunas, dim);
    
    if (res == -1) {
        perguntarCoordenadas(); // Pergunta novamente se as coordenadas forem invalidas
    }
    mostrarMapa();
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
    } else if(opcao < 0 || opcao > 3) {
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
