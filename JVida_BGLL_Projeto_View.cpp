/*
JVIDA-BGLL - Projeto Jogo da Vida - Etapa 4
05/11/2024 - Grupo:BGLL

Nome dos integrantes:

- Beatriz Lima Morais
- Grazielle Batista de Almeida
- Luana Gabrielle Rodrigues Macedo
- Lucas Ferri dos Santos

	A etapa 4 consiste de substituir a matriz auxiliar utilizada previamente 
	por uma lista ligada, uma vez que a lista ligada faz um uso mais eficiente da memoria.	

*/

#include "JVida_BGLL_Projeto_View.h"

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
      		if(!viz && jdvMatriz[i][j].situacao == '+')
      			printf(".  ");
			else
      			printf("%c  ", jdvMatriz[i][j].situacao);
		}
        	
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
	printf("Digite a quantidade de geracoes (0 para sair): ");
	scanf("%d", &qtdGeracao);
	printf("\n");
    limparBuffer();
}

void perguntarVelocidade(){
	printf("Digite a velocidade de sucessao das geracoes (-1 para sair): ");
	scanf("%d", &velocidade);
	printf("\n");
    limparBuffer();
}

void confirmacao(){
	printf("Deseja Gerar outra geracao(S/N): ");
	scanf("%c", &conf);
	if(conf == 'N' || conf == 'n')
		conf = 'N';
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

//----------------FUNCOES DE MENSAGEM-------------------
void mostrarVivos(){
	TipoCel *aux;
	aux = pvivo;
	if(totvivo > 0){
		int k = 0;
		printf("Celulas Vivas: \n");
		while (aux->prox != NULL)
		{
			if(k%10 == 0){
				printf("\n");
			}
			printf("(%d,%d) | ", aux->lin, aux->col);
			aux = aux->prox;
			k++;
		}
		printf("(%d,%d) ", aux->lin, aux->col);
	}
	printf("\n");
}

void mostrarVizinhosMortos(){
	TipoCel *aux;
	aux = pmorto;
	if(totmorto > 0){
		int k = 0;
		printf("\n\nCelulas Vizinhas Mortas: \n");
		while (aux->prox != NULL)
		{
			if(k%10 == 0){
				printf("\n");
			}
			printf("(%d,%d) | ", aux->lin, aux->col);
			aux = aux->prox;
			k++;
		}
		printf("(%d,%d) ", aux->lin, aux->col);
	}
	printf("\n");
}

void mostrarSitGeracao(int qtdCelViva,int geracaoAtual){
	printf("\n\nGeracao %d: %d celulas vivas\n",geracaoAtual,qtdCelViva );
}
