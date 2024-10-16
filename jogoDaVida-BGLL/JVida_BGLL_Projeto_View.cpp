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

//void mostrarInfoVizinhos(int l, int c){
//	int qtdV = jdvMatriz[l][c].qtdVizinhos;
//	for(int i = 0; i < qtdV; i++){
//		printf("linha %d\n", jdvMatriz[l][c].infoVizinhos[i].linha);
//		printf("coluna %d\n", jdvMatriz[l][c].infoVizinhos[i].coluna);
//		printf("viz vivos %d\n", jdvMatriz[jdvMatriz[l][c].infoVizinhos[i].linha][jdvMatriz[l][c].infoVizinhos[i].coluna].qtdVizVivos);
//		printf("\n");	
//	}
//}

void mostrarMatriz(int dim){
	limparTela();
	printf("\n============================= JOGO DA VIDA =============================\n\n");
	printf("  '.' - celula morta/vazia | 'O' - celula viva | '+' - vizinha-morta\n\n");
	
	printf("\t");
    for (int j = 0; j < dim; j++)
      printf("%02d ", j);
    printf("\n\n");
	
	for (int i = 0; i < dim; i++){
		printf("%02d\t", i);
      	for (int j = 0; j < dim; j++){
      		if(viz == false && jdvMatriz[i][j].situacao == '+')
      			printf(".  ");
			else
      			printf("%c  ", jdvMatriz[i][j].situacao);
		}
        	
        printf("\n");
	} 
}

void mostrarMatrizAux(int dim){

	printf("\t");
    for (int j = 0; j < dim; j++)
      printf("%02d ", j);
    printf("\n\n");
	
	for (int i = 0; i < dim; i++){
		printf("%02d\t", i);
      	for (int j = 0; j < dim; j++)
        	printf("%c  ", jdvAux[i][j].situacao);
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

int mensagemCoordenada(int status){
	
	if(status == -1)
		printf("Coordenada invalida. Tenta novamente\n");
	else
		printf("Celula adicionada.\n");
	
	return 0;
        
}

int retirarCel(int linhas, int colunas, int dim) {
	
    char escolha;

    //Ve se a celula ja existe e remove a mesma caso o usuario digite 'S'
    if (jdvMatriz[linhas][colunas].situacao == 'O') {
        printf("A coordenada ja existe. Deseja remover a celula do mapa (Digite S ou N)? ");
        scanf(" %c", &escolha);
        
        escolha = toupper(escolha); //transforma a entrada em caixa alta para facilitar a validacao

        if (escolha == 'S') {
	        printf("A celula %d%d foi removida do mundo.", linhas,colunas);
            return 1; // celula removida do mundo
        } 
    }
    return 0; 
}

void mostrarSitGeracao(int qtdCelViva,int geracaoAtual){
	printf("Geracao %d: %d celulas vivas\n",geracaoAtual,qtdCelViva );
}

//-----------INTERACOES COM JOGADOR-----------

void perguntarDim(){
	int dimMundo;
	do{
		printf("\n============================= JOGO DA VIDA =============================\n\n");
		printf("Digite a dimensao do mundo(de 10 a 60) [0 para sair do jogo]: " );
		scanf("%d", &dimMundo);
		
		if(dimMundo == 0)
			exit(0);
		
	}while(validarDim(dimMundo) != 1);
}

void perguntarCoordenadas() {
    printf("\nDigite as coordenadas (x y) ou (%d %d para sair): ", dim, dim);
    scanf("%d %d", &linhas, &colunas);
    printf("\n");
    limparBuffer();
}

void perguntarQtdGeracao(){
	printf("Digite a quantidade de geracoes: ");
	scanf("%d", &qtdGeracao);
	printf("\n");
    limparBuffer();
}

void perguntarVelocidade(){
	printf("Digite a velocidade de sucessao das geracoes: ");
	scanf("%d", &velocidade);
	printf("\n");
    limparBuffer();
}
//--------------FUNCIONALIDADES DO MENU------------

int menu(){
	int opcao;

	printf("\n======= JOGO DA VIDA =======\n");
    printf("1 - Apresentar Mapa\n");
    printf("2 - Limpar Mapa\n");
    printf("3 - Incluir celula / excluir celulas\n");
    printf("4 - Mostrar/Esconder vizinhas-mortas\n");
    printf("5 - Mostrar Proximas Geracoes\n");
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
