/*
JVIDA-BGLL - Projeto Jogo da Vida - Etapa 1
08/10/2024 - Grupo:BGLL

Nome dos integrantes:

- Beatriz Lima Morais
- Grazielle Batista de Almeida
- Luana Gabrielle Rodrigues Macedo
- Lucas Ferri dos Santos
*/

#include "JVida_BGLL_Projeto_Controller.h"
#include <time.h>

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
void tornarVazioAux(int l,int c){
	int qtdV = jdvAux[l][c].qtdVizinhos; // Quantidade de vizinhos
    int lV;
    int lC;
    
    for (int i = 0; i < qtdV; i++) {
        lV = jdvAux[l][c].infoVizinhos[i].linha; // Linha do vizinho
        lC = jdvAux[l][c].infoVizinhos[i].coluna; // Coluna do vizinho
        
        

        // Verifica se a celula vizinha nao e viva 
        if (jdvAux[lV][lC].situacao != 'O' && jdvAux[lV][lC].qtdVizVivos == 1) { //Somente torna vazia as celulas que sao vizinhas-mortas APENAS da celula que esta sendo retirada
            jdvAux[lV][lC].situacao = '.'; // se ela nao for viva, torna em vazia
        }
        
        jdvAux[lV][lC].qtdVizVivos = jdvAux[lV][lC].qtdVizVivos - 1;
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

//verifica 

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
	if(jdvMatriz[nL][nC].situacao != 'O'){
		jdvMatriz[nL][nC].situacao = '+';
	}
}

void guardarInfoVizinhosAux(int l, int c, int nC, int nL, int qtdVizinhos){
	jdvAux[l][c].qtdVizinhos = qtdVizinhos + 1;
	jdvAux[l][c].infoVizinhos[qtdVizinhos].coluna = nC;
	jdvAux[l][c].infoVizinhos[qtdVizinhos].linha = nL;
	jdvAux[nL][nC].qtdVizVivos = jdvMatriz[nL][nC].qtdVizVivos + 1;
	if(jdvAux[nL][nC].situacao != 'O'){
		jdvAux[nL][nC].situacao = '+';
	}
}

//Realiza as validacoes necessarias para determinar uma celula como vizinha morta
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
				guardarInfoVizinhosAux(l,c,nC,nL,qtdVizinhos);
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
				guardarInfoVizinhosAux(l,c,nC,nL,qtdVizinhos);
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
		guardarInfoVizinhosAux(l,c,nC,nL,qtdVizinhos);
		qtdVizinhos = qtdVizinhos + 1;
	}
	
	nC = c - 1;//coluna a esquerda
	
	if(nC >= 0){
		guardarInfoVizinhos(l,c,nC,nL,qtdVizinhos);
		guardarInfoVizinhosAux(l,c,nC,nL,qtdVizinhos);
		qtdVizinhos = qtdVizinhos + 1;
	}
}

void alterarViz(){
	viz = !(viz);
}

//funcao para contar quantos vizinhos vivos existem perto de uma celula
int qtdVizinhosVivos(int l, int c) {
	
    int qtdCelViva = 0;
   


    // percorre os 8 vizinhos ao redor da celula
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
        	
            if (i == 0 && j == 0) {
                continue; // ignora a propria celula
            }
            int novaLinha = l + i;
   		    int novaColuna = c + j;
            // verifica se a celula vizinha esta dentro dos limites da matriz
            if (novaLinha >= 0 && novaLinha < dim && novaColuna >= 0 && novaColuna < dim) {
                if (jdvMatriz[novaLinha][novaColuna].situacao == 'O') {
                     qtdCelViva++;
                }
            }
        }
    }
    return  qtdCelViva;//devolve a qtd de celulas vivas vizinhas
}


//um ser vivo nasce numa celula vazia se essa celula vazia tiver exatamente 3 seres vivos vizinhos.
int reproducao(int l, int c) {
	
    int qtdVivos = qtdVizinhosVivos(l, c);

    if (qtdVivos == 3) {
        return 1;  // a celula nasce
    }

    return 0; // nenhuma modificacao feita na celula
}


//Um ser vivo que tenha 2 ou 3 vizinhos sobrevive para a geracao seguinte.
int sobrevivencia(int l, int c) {
	
    int qtdVivos = qtdVizinhosVivos(l, c);
    if (qtdVivos == 2 || qtdVivos == 3) {
        return 1;  // a celula sobrevive, entao nao precisa mudar nada
    } else {
    	if( qtdVivos == 1){
    		jdvAux[l][c].situacao = '+';
		}else if(qtdVivos == 0){
			jdvAux[l][c].situacao = '.';
		}
//        jdvAux[l][c].situacao = '.';  // A celula morre
        return 0;  // a celula não sobreviveu
    }
}


//Um ser vivo com 4 ou mais vizinhos morre porque fica sem comida. 
int morteFaltaComida(int l,int c){
	
	if(qtdVizinhosVivos(l,c) >= 4){
		jdvAux[l][c].situacao = '+';
		return 1;// a celula morre por falta de comida
	}
	return 0; //nenhuma alteracao
}
// Um ser vivo com 0 ou 1 vizinhos morre de solidao.
int morteSolidao(int l, int c){
	
	if(qtdVizinhosVivos(l,c) == 0){ 
		jdvAux[l][c].situacao = '.';
		return 1;// a celula morre por falta de amigos
	}else if(qtdVizinhosVivos(l,c) == 1){
		jdvAux[l][c].situacao = '+';
		return 1;
	}
	return 0;//nenhuma alteracao, a celula continua viva
}

void copiarMatrizAux(int dim) {
    // Copia a matriz auxiliar para a principal
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            jdvMatriz[i][j].situacao = jdvAux[i][j].situacao;  // copia a proxima geracao
        }
    }
}

// Limpa a matriz auxiliar
void limparMatrizAux(int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            jdvAux[i][j].situacao = '.';  
        }
    }
}

void gerarAtraso(){
	time_t lt1, lt2;
    
    lt1 = time(NULL);
    lt2 = lt1;
    
    // enquanto a diferença entre o lt2 e o lt1 for menor que o atraso, continua no loop
    while (difftime(lt2, lt1) < velocidade) {
        lt2 = time(NULL); // atualiza o lt2 com o tempo atual
    }
}

int contarVivas(int dim) {
    int qtdCelViva = 0;
    
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (jdvMatriz[i][j].situacao == 'O') {
                qtdCelViva++;  
            }
        }
    }
    return qtdCelViva;
}

void proximaGeracao(int dim, int qtdGeracao) {
		
    limparMatrizAux(dim);  
    
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (jdvMatriz[i][j].situacao == 'O') {
                if (sobrevivencia(i, j) == 0) {
                    morteFaltaComida(i, j);
                    morteSolidao(i, j);
                } else {
                    jdvAux[i][j].situacao = 'O'; // se sobrevive, copia o estado para a matriz auxiliar
                }
            } else if (jdvMatriz[i][j].situacao == '+' || jdvMatriz[i][j].situacao == '.') { // Verifica se uma nova celula deve nascer
                if (reproducao(i, j) == 1) {
                    jdvAux[i][j].situacao = 'O';
                    infoVizinhos(i, j); // registra vizinhos de novas celulas vivas
                }
            }
            // Verifica se a celula n e viva e precisa ser esvaziada
            if (jdvMatriz[i][j].situacao != 'O' && jdvMatriz[i][j].situacao != '.') {
                tornarVazioAux(i, j);
            }
        }
    }
	    
    copiarMatrizAux(dim); // copia a matriz auxiliar de volta para a matriz principal
    mostrarMatriz(dim); 
    geracaoAtual++;
	int qtdCelViva = contarVivas(dim);  
    mostrarSitGeracao(qtdCelViva, geracaoAtual);
	if (velocidade == 0) {
		confirmacao();
	} else {
		gerarAtraso();
	}
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
			case 5:
				perguntarQtdGeracao();
				perguntarVelocidade();
				limparTela();
				do{
					proximaGeracao(dim,qtdGeracao);
					mostrarMatriz(dim);
					limparTela();
					qtdGeracao = qtdGeracao - 1;
				}while(qtdGeracao > 0 && conf != 'N');
//				mostrarMatrizAux(dim);
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



