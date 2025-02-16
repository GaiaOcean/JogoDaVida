/*
JVIDA-BGLL - Projeto Jogo da Vida - Etapa 6
19/11/2024 - Grupo:BGLL

Nome dos integrantes:

- Beatriz Lima Morais
- Grazielle Batista de Almeida
- Luana Gabrielle Rodrigues Macedo
- Lucas Ferri dos Santos

    A etapa 6 e' a entrega do projeto final, ela abilita a jogada completa do Jogo Da Vida,
	permitindo gerar, salvar, recuperar e excluir geracoes de celulas utilizando listas ligadas.


*/
#include "JVida_BGLL_Projeto_View.h"

void mostrarMatriz(int dim){
	limparTela();
	if(opcaoCarregarMenu != 7){
		printf("\n============================= JOGO DA VIDA =============================\n\n");
		printf("  '.' - celula morta/vazia | 'O' - celula viva | '+' - vizinha-morta\n\n");
	} else {
		mostrarObservacao();
	}
	printf("\n\t");
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
	if(opcaoCarregarMenu != 7){
		mostrarVivos();
	    mostrarVizinhosMortos();
	}
	
}


// -----------FUNCOES DE VALIDACOES-----------
int validarDim(int dimMundo){
	if(dimMundo < 10 || dimMundo > 60){
	    limparTela();
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

void apresentarMensamDeSucesso(int status){
	
	switch(status){
		case 1:
			printf("Configuracao Gravada com sucesso\n");
			break;
		case 2:
			printf("O arquivo CONF_INIC foi removido com sucesso.");
			break;
		case 3:
			printf("O arquivo CONFIG_INIC foi removido.\n");
			break;
		default:
			printf("Mudanca feita com sucesso");
	}
}
void apresentaMensagemDeErro(int status){
	
	switch(status){
		case 0:
			printf("ERRO: O arquivo CONF_INIC nao pode ser removido\n");
			break;
	    case 1:
	    	printf("O arquivo CONF_INIC foi removido");
	    	break;
	    case 2:
	    	printf("Nao existe configuracao a recuperar");
	    	break;
	    case 3:
	    	printf("Nao e possivel deletar: O deposito de geracoes iniciais esta vazio\n");
	    	break;
	    case 4:
	    	printf("ERRO: O arquivo CONFIG_INIC nao pode ser removido");
	    	break;
	    case 5:
	    	printf("\nO arquivo CONFIG_INIC foi removido com sucesso\n");
	    	break;
	    case 6:
	    	printf("Nao ha geracoes salvas\n");
	    	break;
	    case 7:
	    	printf("Erro na gravacao do arquivo CONFIG_INIC\n");
	    	break;
	    case 8:
	    	printf("Erro ao abrir o arquivo de configuracoes\n");
	    	break;
	    case 9:
	    	printf("Nao foi possivel carregar: Nenhuma geracao salva\n");
	    	break;
	    case 10:
	    	printf("Nao existe celulas vivas para gravacao.\n");
	    	break;
	    case 11:
	    	printf("Erro: A dimensao da matriz salva e diferente da dimensao atual.\n");
	    	break;
	    case 12:
	    	printf("Nao ha geracoes anteriores.\n");
	    	break;
	    case 13:
	    	printf("Nao ha proximas geracoes.\n");
	    	break;
		default:
			printf("Erro desconhecido");
	}
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
int continuarMostrandoGeracoes(){
	
	int op;
	printf("\n\n1 - Ver proxima geracao salva\n2 - Ver a geracao salva anterior\n3 - Carregar essa geracao para o jogo atual\n0 - Sair sem alterar o jogo atual\n");
	scanf("%d", &op);
	
	return op;
	
}
int rconfirma(){
	
	char opcaoUsuario;
	
	toupper(opcaoUsuario);
	printf("Confirma exclusao das configuracoes iniciais?(s ou n):");
	scanf("%c", &opcaoUsuario);
	
	if(opcaoUsuario == 'S')
		return 0;
	else
		return 1;	
}


//--------------FUNCIONALIDADES DO MENU------------

int menu(){
	int opcao;
    printf("\n1 - Apresentar Mapa\n");
    printf("2 - Limpar Mapa\n");
    printf("3 - Incluir celula / excluir celulas\n");
    printf("4 - Mostrar/Esconder vizinhas-mortas\n");
    printf("5 - Mostrar Proximas Geracoes\n");
    printf("6 - Salvar Geracoes\n");
    printf("7 - Carregar Geracoes Salvas\n");
    printf("8 - Deletar Geracoes salvas\n");
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
		printf("\nCelulas Vivas: \n");
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
		printf("\nCelulas Vizinhas Mortas: \n");
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
	printf("\n\nGeracao %d: %d celulas vivas\n",geracaoAtual,qtdCelViva);
}

void mostrarInformacoesSave(int indiceSave, int qtdVivas){
	printf("\n\nSave %d - Celulas vivas: %d\n",indiceSave+1,qtdVivas);
}

void mostrarObservacao(){
	printf("\n------------------------------------------------------------------------------------------------------------");
	printf("\n OBSERVACAO:\n -Se a dimensao da matriz salva for maior que a da atual, pode ser que algumas celulas\n  nao aparecam caso estejam em coordenadas nao existentes na matriz atual.\n -A matriz que aparece abaixo mostra exatamente a forma que esse save ira se comportar no jogo atual\n");
	printf("------------------------------------------------------------------------------------------------------------\n");
}
