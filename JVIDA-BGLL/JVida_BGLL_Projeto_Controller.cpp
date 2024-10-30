/*
JVIDA-BGLL - Projeto Jogo da Vida - Etapa 3
29/10/2024 - Grupo:BGLL

Nome dos integrantes:

- Beatriz Lima Morais
- Grazielle Batista de Almeida
- Luana Gabrielle Rodrigues Macedo
- Lucas Ferri dos Santos

	A etapa 3 consiste de criar uma simulacao da evolucao das celulas ao longo de varias geracoes
	Esta simulacao sera realizada com o auxilio de uma matriz auxiliar
	O usuario pod definir a quantidade de geracao a serem simuladas
	tembem deve ser possivel ajustar a velocidade com que as geracoes seram exibidas
*/

#include "JVida_BGLL_Projeto_Controller.h"
#include <time.h>
#include <stdlib.h>

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

//verifica as possibilidades de acao para a coordenada informada, de forma que,
//se a coordenada estiver vazia, ela e' ocupada e se estiver ocupada, pode ser esvaziada
int inserirOuRetirarCel(int linhas, int colunas, int dim) {
    if (jdvMatriz[linhas][colunas].situacao == '.' || jdvMatriz[linhas][colunas].situacao == '+') {
        gerarSeres(linhas, colunas, dim);
        definirSituacaoVizinhos(linhas,colunas);
        return 1;  // celula inserida
    }
    else if (jdvMatriz[linhas][colunas].situacao == 'O') {
    	 if(retirarCel(linhas, colunas, dim) == 1){
    	 	tornarVizinhoVivoOuMorto(linhas, colunas);
			tornarVazio(linhas, colunas);
        	return 2;  // celula removida
        }
    }
    return 0;  // nenhuma alteracao feita
}

//---------------------FUNCIONALIDADES PARA VIZINHOS---------------------------

//Em casos de retirada de uma celula viva que e' vizinha de outra celula viva, o local da celula viva que foi excluida
//deve se tornar 'vizinha-morta' ao inves de 'morta'
void tornarVizinhoVivoOuMorto(int l, int c){
	if(verificarSeCelulaVizinhaViva(l,c) == 1)
    	jdvMatriz[l][c].situacao = '+';
    else
        jdvMatriz[l][c].situacao = '.';
}

//Verifica se entre os vizinhos de uma celula esta uma celula viva
int verificarSeCelulaVizinhaViva(int l, int c){
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

//Funcao responsave por tornar uma celula vazia
void tornarVazio(int l, int c){
	int qtdV = jdvMatriz[l][c].qtdVizinhos; // Quantidade de vizinhos
    int lV;
    int lC;

    for (int i = 0; i < qtdV; i++) {
        lV = jdvMatriz[l][c].infoVizinhos[i].linha; // Linha do vizinho
        lC = jdvMatriz[l][c].infoVizinhos[i].coluna; // Coluna do vizinho
        

        // Verifica se a celula vizinha nao e viva 
        if (jdvMatriz[lV][lC].situacao != 'O' && qtdVizinhosVivos(lV,lC) == 0) { //Somente torna vazia as celulas que sao vizinhas-mortas APENAS da celula que esta sendo retirada
            jdvMatriz[lV][lC].situacao = '.'; // se ela nao for viva, torna em vazia
        }
        
    }  
}

//Realiza as validacoes necessarias para determinar uma celula como vizinha morta
void definirSituacaoVizinhos(int l, int c){
	int quantidadeDeVizinhos = jdvMatriz[l][c].qtdVizinhos;
	
	for(int i = 0; i < jdvMatriz[l][c].qtdVizinhos; i++){
		int linhaVizinho = jdvMatriz[l][c].infoVizinhos[i].linha;
		int colunaVizinho = jdvMatriz[l][c].infoVizinhos[i].coluna;
		
		if(jdvMatriz[linhaVizinho][colunaVizinho].situacao == '.')
			jdvMatriz[linhaVizinho][colunaVizinho].situacao = '+';
	}
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

void alterarViz(){
	viz = !viz;
}

//---------------------FUNCIONALIDADES PARA MATRIZ AUXILIAR----------------------

//As funcaoes abaixo sao utiizadas para a matriz auxiliar
void gerarSeresAux(int linhas, int colunas){       
    jdvAux[linhas][colunas].situacao = 'O';
}

void definirEArmazenarVizinhosAux(int l, int c){
	int quantidadeDeVizinhos = jdvMatriz[l][c].qtdVizinhos;
	
	for(int i = 0; i < jdvMatriz[l][c].qtdVizinhos; i++){
		int linhaVizinho = jdvMatriz[l][c].infoVizinhos[i].linha;
		int colunaVizinho = jdvMatriz[l][c].infoVizinhos[i].coluna;
		
		if(jdvAux[linhaVizinho][colunaVizinho].situacao == '.')
			jdvAux[linhaVizinho][colunaVizinho].situacao = '+';
	}
}

int inserirCelAux(int linhas, int colunas){
    gerarSeresAux(linhas, colunas);
    definirEArmazenarVizinhosAux(linhas,colunas);
    return 1;  // celula inserida
}

 // Copia a matriz auxiliar para a principal
void copiarMatrizAux(int dim) {
    
    int lV,lC;
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

//-----------------FUNCIONALIDADES PARA NOVAS GERACOES----------------

//um ser vivo nasce numa celula vazia se essa celula vazia tiver exatamente 3 seres vivos vizinhos.
int reproducao(int l, int c) {
	
    int qtdVivos = qtdVizinhosVivos(l, c);

    if (qtdVivos == 3) {
    	inserirCelAux(l,c);
        return 1;  // a celula nasce
    }

    return 0; // nenhuma modificacao feita na celula
}


//Um ser vivo que tenha 2 ou 3 vizinhos sobrevive para a geracao seguinte.
int sobrevivencia(int l, int c) {
	
    int qtdVivos = qtdVizinhosVivos(l, c);
    if (qtdVivos == 2 || qtdVivos == 3)
        return 1; // a celula sobrevive, entao nao precisa mudar nada
	return 0;  // a celula nao sobreviveu    
}

//Um ser vivo com 4 ou mais vizinhos morre porque fica sem comida. 
int morteFaltaComida(int l,int c){
	
	int qtdVivos = qtdVizinhosVivos(l, c);
	if(qtdVizinhosVivos(l, c) >= 4){
		return 1;// a celula morre por falta de comida
	}
	return 0; //nenhuma alteracao
}

// Um ser vivo com 0 ou 1 vizinhos morre de solidao.
int morteSolidao(int l, int c){
	
	int qtdVivos = qtdVizinhosVivos(l, c);
	if(qtdVivos == 0 || qtdVivos == 1){ 
		return 1;// a celula morre por falta de amigos
	}
	
	return 0;
}

//Funcao responsavel por criar a proxima geracao de celulas
void proximaGeracao(int dim,int qtdGeracao) {
	limparMatrizAux(dim);
	
    	for (int i = 0; i < dim; i++) {
	    	for (int j = 0; j < dim; j++) {
	    		definirSituacaoCelula(i,j);
	    	}
		}
	    
	    copiarMatrizAux(dim); // copia a matriz auxiliar de volta para a matriz principal
	    limparMatrizAux(dim);
        mostrarMatriz(dim);
        geracaoAtual++;
		int qtdCelViva = contarVivas(dim);  
   		mostrarSitGeracao(qtdCelViva, geracaoAtual);
		if(velocidade == 0){
			confirmacao();
		}
        else{
			gerarAtraso();
		}
		
}

//Gera um atraso para que seja perceptivel quando se passa de uma geracao para a outra
void gerarAtraso(){
	time_t lt1, lt2;
    
    lt1 = time(NULL);
    lt2 = lt1;
    
    // enquanto a diferença entre o lt2 e o lt1 for menor que o atraso, continua no loop
    while (difftime(lt2, lt1) < velocidade) {
        lt2 = time(NULL); // atualiza o lt2 com o tempo atual
    }
}

//---------------FUNCIONALIDADES DE VERIFICACOES E DEFINICAO DE SITUACAO------------------

//Conta a quantidade de celulas "O" na matriz
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

int definirSituacaoCelula(int l, int c){
	
	if(morteSolidao(l,c) == 1){
		return 0;
	}
		
	if(morteFaltaComida(l,c) == 1){
		return 0; //nada alterado na matriz auxiliar
	}
	
	if(jdvMatriz[l][c].situacao == 'O'){
	   if(sobrevivencia(l,c) == 1){
	        inserirCelAux(l,c);
	        return 1; //celula adicionada
		}
	} else {
		if(reproducao(l,c) == 1){
			inserirCelAux(l,c);
			return 1;
		}
	}
	
	return -1;
	                
}
	
//Funcao responsavel por verificar se as coordenadas digitadas sao validas
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
 	
 	perguntarDim();
	inicializarMatriz60x60(dim);
	inicializarMatrizAux();
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
				if(qtdGeracao < 1){ //tanto para entradas invalidas quanto para o comando de saida
					mostrarMatriz(dim);
					break;
				}
				perguntarVelocidade();
				if(velocidade < 0){
					mostrarMatriz(dim);
					break;
				}
				limparTela();
				do{
					proximaGeracao(dim,qtdGeracao);
					mostrarMatriz(dim);
					limparTela();
					qtdGeracao = qtdGeracao - 1;
				}while(qtdGeracao > 0 && conf != 'N');
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
