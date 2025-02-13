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

#include "JVida_BGLL_Projeto_Controller.h"
#include <time.h>
#include <stdlib.h>

void gerarSeres(int linhas, int colunas,int dim){       
    carregaVivo(linhas,colunas);
    alterarSituacaoVivo();
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

void limparGeracao(){
	if(qtdConf > 0){
		if(rconfirma() == 0)
		    return;
	}
	qtdConf = 0;  ///nenhuma configuracao gravada
	ultimarecup = -1;
	deletaConf();
	
}
	
//verifica as possibilidades de acao para a coordenada informada, de forma que,
//se a coordenada estiver vazia, ela e' ocupada e se estiver ocupada, pode ser esvaziada
int inserirOuRetirarCel(int linhas, int colunas, int dim) {
    if (jdvMatriz[linhas][colunas].situacao == '.' || jdvMatriz[linhas][colunas].situacao == '+') {
        gerarSeres(linhas, colunas, dim);
        armazenarInfoVizinhos();
        qtdCelViva++;  
        return 1;  // celula inserida
    }
    else if (jdvMatriz[linhas][colunas].situacao == 'O') {
    	 if(retirarCel(linhas, colunas, dim) == 1){
    	 	excluiVivo(linhas, colunas);
    	 	tornarVizinhoVivoOuMorto(linhas, colunas);
			tornarVazio(linhas, colunas);
			armazenarInfoVizinhos();
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

void definirEArmazenarVizinhosLista(int l, int c){
	
	int quantidadeDeVizinhos = jdvMatriz[l][c].qtdVizinhos;

	for(int i = 0; i < jdvMatriz[l][c].qtdVizinhos; i++){
		int linhaVizinho = jdvMatriz[l][c].infoVizinhos[i].linha;
		int colunaVizinho = jdvMatriz[l][c].infoVizinhos[i].coluna;
		
		if(jdvMatriz[linhaVizinho][colunaVizinho].situacao != 'O'){
			carrega1Morto(linhaVizinho, colunaVizinho);
			jdvMatriz[linhaVizinho][colunaVizinho].situacao = VIZINHO;
		}
			
	}
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

//---------------------FUNCIONALIDADES PARA LISTAS----------------------


void gerarSeresLista(int linhas, int colunas){       
	carregaVivo(linhas, colunas);
}

void iniciarListas(){
	liberaLista(pvivo, totvivo);
	liberaLista(pmorto, totmorto);
	liberaLista(pvivoprox, totvivoprox);
	
	pvivo = pmorto = pvivoprox = NULL;
	totvivo = totmorto = totvivoprox = 0;
}

void liberaLista(TipoCel *aux, int tot){
    if(aux == NULL || tot == 0)
    	return;
    TipoCel *aux2;
    do{
    	aux2 = aux;
    	aux = aux->prox;
    	free(aux2);
	}while(aux != NULL);
}

int inserirCelLista(int linhas, int colunas){
    gerarSeresLista(linhas, colunas);
    return 1;  // celula inserida
}

//-----------------FUNCIONALIDADES PARA NOVAS GERACOES----------------

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

void alterarSituacaoVivo(){
	TipoCel *aux;
	aux = pvivo;
	if(totvivo > 0){
		while (aux->prox != NULL)
		{
			jdvMatriz[aux->lin][aux->col].situacao = VIVO;
			aux = aux->prox;
		}
		jdvMatriz[aux->lin][aux->col].situacao = VIVO;
	}
}

void armazenarInfoVizinhos(){
	liberaLista(pmorto, totmorto);
	pmorto = NULL;
	totmorto = 0;
	
	TipoCel *aux;
	aux = pvivo;
	if(totvivo > 0){
		while (aux->prox != NULL)
		{
			definirEArmazenarVizinhosLista(aux->lin, aux->col);
			aux = aux->prox;
		}
		definirEArmazenarVizinhosLista(aux->lin, aux->col);
	}
}

void alterarSituacaoVizinhoMorto(){
	TipoCel *aux;
	aux = pmorto;
	if(totmorto > 0){
		while (aux->prox != NULL)
		{
			jdvMatriz[aux->lin][aux->col].situacao = VIZINHO;
			aux = aux->prox;
		}
		jdvMatriz[aux->lin][aux->col].situacao = VIZINHO;
	}
}


//Funcao responsavel por criar a proxima geracao de celulas


void proximaGeracao(int dim,int qtdGeracao) {
	iniciarListas();
	
    	for (int i = 0; i < dim; i++) {
	    	for (int j = 0; j < dim; j++) {
	    		definirSituacaoCelula(i,j);
	    	}
		}
	    
	    limparMapa(dim);
	    alterarSituacaoVivo();
	    armazenarInfoVizinhos();
	    alterarSituacaoVizinhoMorto();
        mostrarMatriz(dim);
        geracaoAtual++;
		qtdCelViva = contarVivas(dim);  
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
    
    // enquanto a diferenca entre o lt2 e o lt1 for menor que o atraso, continua no loop
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
		return 0; //nada alterado na lista
	}
	
	if(jdvMatriz[l][c].situacao == 'O'){
	   if(sobrevivencia(l,c) == 1){
	        inserirCelLista(l,c);
	        return 1; //celula adicionada
		}
	} else {
		if(reproducao(l,c) == 1){
			inserirCelLista(l,c);
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

//percorre a lista verificando se as coordenadas ja existem retornando verdadeiro ou falso
int verificaMorto(int i, int j){
	
	TipoCel *aux = pmorto;
	while(aux != NULL){
		if(aux -> lin == i  && aux -> col == j ){ //verifica se a celula ja existe
			return 1;
		}
		aux = aux -> prox;
	}
	return -1; // a cel nao foi encontrada
	
}

void carregaVivo(int i, int j){
	TipoCel *aux = (TipoCel *)malloc(sizeof(TipoCel));
	if(aux == NULL){
		return;
	}
	aux->lin = i;
	aux->col = j;
	
	if(totvivo == 0){
		pvivo = aux;
		pvivo->prox = NULL;
	}
	else{
		aux->prox = pvivo;
		pvivo = aux;
	}
	totvivo++;
}


void excluiVivo(int i, int j){
	TipoCel *aux, *aux2;
	aux = pvivo;
	aux2 = aux;
	if(totvivo > 0){
		while(aux->lin != i || aux->col != j){
			aux2 = aux;
			aux = aux->prox;
		}
		if(aux->lin == i && aux->col == j){
			if(aux2 == aux)
				pvivo = aux->prox;
			else
				aux2->prox = aux->prox;
			free(aux);
		}
		totvivo--;
	}
}

//funcao para limpar a lista de cel morta
void excluiMortos() {
	
    TipoCel *aux = pmorto;

    while (aux != NULL) {
        TipoCel *aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }

    pmorto = NULL;
    totmorto = 0;//reseta a qtd de cel morta
}

void carregaMorto(int i, int j){
	if((i < 0) || (j < 0))
		return;
	if((i >= dim) || (j >= dim))
		return;
	if(jdvMatriz[i][j].situacao == VIVO)
		return;
	if(verificaMorto(i,j) == 1)
		return;
	
	TipoCel *aux = (TipoCel*)malloc(sizeof(TipoCel));
	if(aux == NULL){
		return;
	}
	aux->lin = i;
	aux->col = j;

	if(totmorto == 0){
		pmorto = aux;
		pmorto->prox = NULL;
	}
	else{
		aux->prox = pmorto;
		pmorto = aux;
	}
	totmorto++;
}

int carrega1Morto(int i, int j){
	
	if(jdvMatriz[i][j].situacao == 'O')
		return 1;//celula viva
	
	if(verificaMorto(i,j) == 1)
		return 2;//celula morta
		
	carregaMorto(i,j);
	
	return 0;
}

//-----------------------------FUNCIONALIDADES PARA SALVAR E RECUPERAR----------------

int validarGravacao(){
	
	if (totvivo == 0) {
		apresentaMensagemDeErro(10);
        return 10;  
    }
    
    return -1;
}
//funcao utilizada para gravar as celulas da geracao salva
void gravaCelulas(){ 
    int cursorMaxLista, cursorCelulasVivas;
    cursorMaxLista = qtdConf;  
	
    TipoCel *aux = pvivo;
    cursorCelulasVivas = 0;
    
    // preenche a lista Lvivo com as cel vivas
    do {
        Lvivo.L[cursorCelulasVivas].lin = aux->lin;
        Lvivo.L[cursorCelulasVivas].col = aux->col;
        cursorCelulasVivas++;
        aux = aux->prox;
    } while (aux != NULL);
    

    Lvivo.tamanhoList = totvivo;
    Lvivo.dim = dim;
    LConfig[cursorMaxLista].TL = Lvivo;  
    LConfig[cursorMaxLista].i = linhas;
    LConfig[cursorMaxLista].j = colunas;
    
    LConfig[cursorMaxLista].geracao = geracaoAtual; 

    
    FILE *fp = fopen("CONFIG_INIC", "ab"); //"ab" impede subescricao dos arquivos salvos
    if (fp == NULL) {
        apresentaMensagemDeErro(6);
        return;
    }

    // salva a config no arquivo
    if (fwrite(&LConfig[cursorMaxLista], sizeof(TipoLista), 1, fp) != 1) {
        apresentaMensagemDeErro(7);
        fclose(fp);
        return;
    }

    fclose(fp);
    qtdConf++;  
    apresentarMensamDeSucesso(1);
}

//recupera as informacoes salvas no gravarCelulas
int carregaConfig() {
	
    FILE *fp = fopen("CONFIG_INIC", "rb");
    if (fp == NULL) {
        return 6;
    }

    int k = 0;
    qtdConf = 0;  // reinicia a  qtdConf 

   
    while (fread(&LConfig[k], sizeof(TipoLista), 1, fp) == 1) { // Ler as config salvas
		qtdConf++;  // incrementa a qtd de config carregadas
        k++;
        if (k >= 50) {  
            break;
        }
        
    }
	
    fclose(fp);
    return -1;
}

//apaga todas as informacoes salvas
void deletaConf(){
	if(remove("CONFIG_INIC")!= 0){
		return;
	}
	qtdConf = 0;

}

//recupera tds as celulas vivas de uma gravacao
void recuperarCels(){
	int k, ni;
	
	if(qtdConf == 0){
		apresentaMensagemDeErro(2);
		     return;	
	} 

	iniciarListas();
	k = ultimarecup + 1;
	
	if(k >= qtdConf){
		k = 0;
		Lvivo = LConfig[k].TL;
		ultimarecup = k;
    }
    qtdCelViva = Lvivo.tamanhoList;
    
    for(ni = 0; ni < Lvivo.tamanhoList; ni++){
		gerarSeres(Lvivo.L[ni].lin, Lvivo.L[ni].col,dim);
	}
}

//mostra a geracao salva 
void atualizarMapaRecuperado(int geracaoMostrada){ 
	
	for(int i = 0; i < LConfig[geracaoMostrada].TL.tamanhoList; i++){
		int linha = LConfig[geracaoMostrada].TL.L[i].lin;
		int coluna = LConfig[geracaoMostrada].TL.L[i].col;
		
		jdvMatriz[linha][coluna].situacao = VIVO;
	}
    
}
//remove o arquivo de configuracões iniciais
void deletaConfig(){
	 if(remove("CONFIG_INIC") != 0){
 			apresentaMensagemDeErro(4);
 			return;
     	}else{
     		apresentaMensagemDeErro(5);
		 }

 	qtdConf = 0;
}
int deleteConfig(){
	 if(remove("CONFIG_INIC") != 0){
 			return 3;
     	}
 	qtdConf = 0;
 	return 5;
}
//mostra tds as geracoes salvas sucessivamente
void jdvMatrizesSalvas() {
	
    if (qtdConf == 0) {
        apresentaMensagemDeErro(9);
        return;
    }
    int opcao;

    int geracaoMostrada = 0;
    int mensagemDeErro = -1;

    do{
    	limparMapa(dim);
        Lvivo = LConfig[geracaoMostrada].TL;
        atualizarMapaRecuperado(geracaoMostrada);
        mostrarMatriz(dim);
        qtdCelViva = contarVivas(dim);
        mostrarInformacoesSave(geracaoMostrada,qtdCelViva);
        
        if(mensagemDeErro != -1){
        	apresentaMensagemDeErro(mensagemDeErro);
		}
		
		mensagemDeErro =-1;
        opcao = continuarMostrandoGeracoes();
        
        if (opcao == 3) {            // Configura o jogo para continuar a partir da geracao selecionada
            recuperarCels();                
            armazenarInfoVizinhos();        
            break;                         
        }
        
        if(opcao == 0){
        	alterarSituacaoVivo();
    		//alterarSituacaoVizinhoMorto();
        	break;
		}
        	
        if(opcao == 1){
        	if (geracaoMostrada < qtdConf - 1){
                geracaoMostrada++; // vai para a prox geracao
            } else {
                mensagemDeErro = 13;  // Nao ha prox geracao
            }
		}
        	
        if(opcao == 2){
        	if(geracaoMostrada > 0){
                geracaoMostrada--;  // Volta para a geracao anterior
            }else{
                mensagemDeErro = 12;  // Nao ha geracao anterior
            }
		}    
        	 
    }while (geracaoMostrada < qtdConf || opcao != 0);
    
    limparTela();
    limparMapa(dim);
    alterarSituacaoVivo();
    alterarSituacaoVizinhoMorto();
}

//---------FUNCIONALIDADES DO MENU---------
void jogarMenu(){

	int opcao;
 	perguntarDim();
	inicializarMatriz60x60(dim);
    limparTela();
 	mostrarMatriz(dim);
 	
 	int mensagemDeErro = -1;
	viz = false;

 	do{
 		if(mensagemDeErro != -1){
 			apresentaMensagemDeErro(mensagemDeErro);	
		}
		mensagemDeErro = -1;
 		opcao = menu();
 		
        switch(opcao){
            case 1:
            	limparTela();
                mostrarMatriz(dim);
                break;
            case 2:
                limparMapa(dim);
                iniciarListas();
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
			case 6:
				if(validarGravacao() == 10){
					mensagemDeErro = 10;
					mostrarMatriz(dim);
					break;
				}
				limparTela();
				mostrarMatriz(dim);
				gravaCelulas();
				break;	
			case 7:
				opcaoCarregarMenu = 7;
		        mensagemDeErro = carregaConfig(); 	
				if(mensagemDeErro != 6){
					limparMapa(dim);
					jdvMatrizesSalvas();
				}
				opcaoCarregarMenu = 0;
				mostrarMatriz(dim);		
				break;
			case 8:
			    mensagemDeErro = deleteConfig();
			    if(mensagemDeErro != 3){
			    	rconfirma();
			    	limparGeracao();
				}
		
				mostrarMatriz(dim);
				opcaoCarregarMenu = 0;
				break;
            case 0:
                interacoesMenu(opcao);
				exit(0);
            default:
                interacoesMenu(opcao);
        }
    } while (opcao != 0);
}
