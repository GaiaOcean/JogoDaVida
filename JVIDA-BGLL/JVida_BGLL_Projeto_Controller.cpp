/*
JVIDA-BGLL - Projeto Jogo da Vida - Etapa 2
15/10/2024 - Grupo:BGLL

Nome dos integrantes:

- Beatriz Lima Morais
- Grazielle Batista de Almeida
- Luana Gabrielle Rodrigues Macedo
- Lucas Ferri dos Santos

O Controller.cpp e' o intermediador entre o Model e o View, ele contem a parte logica do processamento do jogo

*/

#include "JVida_BGLL_Projeto_Controller.h"


void gerarSeres(int linhas, int colunas,int dim){       
    jdvMatriz[linhas][colunas].situacao = 'O';
}

//Funcao responsavel por limpar o mapa
void limparMapa(int dim) {
	
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
        	
            if (jdvMatriz[i][j].situacao == 'O' || jdvMatriz[i][j].situacao == '+') {
                jdvMatriz[i][j].situacao = '.';
            }
            
        }
    }
}

void tornarVazio(int l, int c){
	int qtdV = jdvMatriz[l][c].qtdVizinhos; // Quantidade de vizinhos
    int lV;
    int lC;

    for (int i = 0; i < qtdV; i++) {
        lV = jdvMatriz[l][c].infoVizinhos[i].linha; // Linha do vizinho
        lC = jdvMatriz[l][c].infoVizinhos[i].coluna; // Coluna do vizinho
        

        // Verifica se a celula vizinha nao e viva 
        if (jdvMatriz[lV][lC].situacao != 'O' && jdvMatriz[lV][lC].qtdVizVivos == 1) { //Somente torna vazia as celulas que sao vizinhas-mortas APENAS da celula que esta sendo retirada
            jdvMatriz[lV][lC].situacao = '.'; // se ela nao for viva, torna em vazia
        }
        
        jdvMatriz[lV][lC].qtdVizVivos = jdvMatriz[lV][lC].qtdVizVivos - 1;
    }  
}

//Em casos de retirada de uma celula viva que e' vizinha de outra celula viva, o local da celula viva que foi excluida
//deve se tornar 'vizinha-morta' ao inves de 'morta'
void tornarVizinho(int l, int c){
	if(verificarOcupacao(l,c) == 1)
    	jdvMatriz[l][c].situacao = '+';
    else
        jdvMatriz[l][c].situacao = '.';
}

//verifica as possibilidades de acao para a coordenada informada, de forma que,
//se a coordenada estiver vazia, ela e' ocupada e se estiver ocupada, pode ser esvaziada
int inserirOuRetirarCel(int linhas, int colunas, int dim) {
    if (jdvMatriz[linhas][colunas].situacao == '.' || jdvMatriz[linhas][colunas].situacao == '+') {
        gerarSeres(linhas, colunas, dim);
        infoVizinhos(linhas,colunas);
        return 1;  // celula inserida
    }
    else if (jdvMatriz[linhas][colunas].situacao == 'O') {
    	 if(retirarCel(linhas, colunas, dim) == 1){
    	 	tornarVizinho(linhas, colunas);
			tornarVazio(linhas, colunas);
        	return 2;  // celula removida
        }
    }
    return 0;  // nenhuma alteracao feita
}


//Verifica se entre os vizinhos de uma celula esta uma celula viva
int verificarOcupacao(int l, int c){
	int qtdV = jdvMatriz[l][c].qtdVizinhos;
	int nL, nC;
	
	for(int i = 0; i < qtdV; i++){
		nL = jdvMatriz[l][c].infoVizinhos[i].linha;
		nC = jdvMatriz[l][c].infoVizinhos[i].coluna;
		
		if(jdvMatriz[nL][nC].situacao == 'O')
			return 1;
	}
	
	return 0;
}

//Altera e armazena as informacoes das celulas vizinhas a uma celula no momento em que ela e' incluida no mundo
void guardarInfoVizinhos(int l, int c, int nC, int nL, int qtdVizinhos){
	jdvMatriz[l][c].qtdVizinhos = qtdVizinhos + 1;
	jdvMatriz[l][c].infoVizinhos[qtdVizinhos].coluna = nC;
	jdvMatriz[l][c].infoVizinhos[qtdVizinhos].linha = nL;
	jdvMatriz[nL][nC].qtdVizVivos = jdvMatriz[nL][nC].qtdVizVivos + 1;
	if(jdvMatriz[nL][nC].situacao == '.'){
		jdvMatriz[nL][nC].situacao = '+';
    }
}

void infoVizinhos(int l, int c){
	int nL = l - 1; //Inicia com a linha acima da coordenada informada
	int nC = c - 1; //Inicia com a coluna a esquerda da coordenada informada
	int qtdVizinhos = 0;
	
	//Verifica se a linha acima da coordenada informada e' valida 
	if(nL >= 0){
		//Caso seja, verifica se a coluna, nas 3 posicoes possiveis, e' valida, se for, altera sua situacao para 'vizinha-morta'
		for(int i = 1; i <= 3; i++){
			if(nC >= 0 && nC < dim){
				guardarInfoVizinhos(l,c,nC,nL,qtdVizinhos);
				qtdVizinhos = qtdVizinhos + 1;
			}
			nC = nC + 1; //a cada rodada do loop, segue uma coluna para a direita ate que as 3 possibilidades de colunas vizinhas sejam verificadas
		}
	}
	
	nL = l + 1; //linha abaixo da coordenada informada
	nC = c - 1;
	
	//Em seguida, realiza as mesmas verificacoes nas celulas vizinhas da linha abaixo da coordenada, se esta existir
	if(nL < dim){
		for(int i = 1; i <= 3; i++){
			if(nC >= 0 && nC < dim){
				guardarInfoVizinhos(l,c,nC,nL,qtdVizinhos);
				qtdVizinhos = qtdVizinhos + 1;
			}
			nC = nC + 1;
		}
	}
	
	//Apos verificar ambas as linhas,
	//verifica se as celulas imediatamente a esquerda e a direita da coordenada existem e, se sim, altera sua situacao para 'vizinha-morta'
	
	nL = l; //linha da coordenada
	nC = c + 1; //coluna a direita da coordenada
	
	if(nC < dim){
		guardarInfoVizinhos(l,c,nC,nL,qtdVizinhos);
		qtdVizinhos = qtdVizinhos + 1;
	}
	
	nC = c - 1;//coluna a esquerda
	
	if(nC >= 0){
		guardarInfoVizinhos(l,c,nC,nL,qtdVizinhos);
		qtdVizinhos = qtdVizinhos + 1;
	}
}

void alterarViz(){
	viz = !viz;
}

int validarCoordenadas(){
	
	do{
		perguntarCoordenadas();
		if(linhas == dim && colunas == dim)
			return 0;
		
		if ((linhas < 0 || linhas >= dim) || (colunas < 0 || colunas >= dim)) {
			mensagemCoordenada(-1);
        } else {
        	inserirOuRetirarCel(linhas, colunas, dim);
        	mensagemCoordenada(0);
        	return 1;
        }
	}while(1);
        
}

//---------FUNCIONALIDADES DO MENU---------
void jogarMenu(){

	int opcao;
 	
	inicializarMatriz60x60();
	inicializarMatrizAux();
    perguntarDim();
    limparTela();
 	mostrarMatriz(dim);
	viz = false;

 	do{
 		
 		opcao = menu();
 		
        switch(opcao){
            case 1:
            	limparTela();
                mostrarMatriz(dim);
                break;
            case 2:
                limparMapa(dim);
                mostrarMatriz(dim);
                break;
            case 3:
                while(linhas != dim || colunas != dim){    
                    mostrarMatriz(dim);
                	validarCoordenadas();
                }
                linhas = 0, colunas = 0;
                mostrarMatriz(dim);
                break;
			case 4:
				limparTela();
				alterarViz();
				mostrarMatriz(dim);
				break;
            case 0:
                interacoesMenu(opcao);
				exit(0);
            default:
                interacoesMenu(opcao);
        }
    } while (opcao != 0);
}
