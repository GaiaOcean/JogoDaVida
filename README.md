# PROJETO JOGO DA VIDA

O jogo da vida foi criado pelo cientista John Conway e objetiva simular o processo de evolução celular, de modo a reproduzir, através de regras simples, as alterações e mudanças em grupos de seres vivos.

### Linguagens utilizadas:
<img src = "https://img.shields.io/badge/C-248a3f?style=for-the-badge&logo=c&logoColor=white" />

### Desenvolvido por:
[@luanagbrm](https://github.com/luanagbrm) [@GaiaOcean](https://github.com/GaiaOcean) [@bialim](https://github.com/bialim) [@Ferri-js](https://github.com/Ferri-js) 

## OBJETIVOS

- Objetiva-se criar um programa em C para simular o jogo da vida em 6 etapas pré-estabelecidas e 12 requisitos funcionais.
- Dividir as funcionalidas do programa no método MCV(Model-View-Controller).
- Apresentar os seres em uma matriz com a dimensão definida pelo usuário.
- Cada posição da matriz é uma célula que pode ter um “O” (para representar um ser vivo) ou um ponto “.” para indicar “vazio” ou “morto”. Cada célula tem um
máximo de 8 células vizinhas (que podem ser representadas pelo caracter “+”).
- Gerar a geração seguinte a partir das regras do jogo de reprodução, sobrevivência e morte.

## REQUISITOS FUNCIONAIS

<b>REQ01</b>: O sistema deve permitir ao usuário a definição do tamanho do mundo (mínimo10 e máximo 60) procurando sempre caber numa tela texto sem retorno de nova linha.Inicialmente o mapa vazio será constituído de pontos (‘.’) para identificar cada possível localização de célula. 

<b>REQ02</b>:O sistema deve permitir ao usuário definir os seres vivos da primeira geração da simulação (isto é: definir as coordenadas de cada célula). Caso a célula já existe, dar a opção de exclui-la do mapa. 

<b>REQ03</b>: O sistema deverá permitir ao usuário: apresentar o mapa das células vivas atuais(apresentadas com o caracter ‘O’).

<b>REQ04</b>: O sistema deverá ter a opção (sim/não) para que sejam também apresentadas as células vizinhas-mortas (apresentadas com o caracter ’+’).(“vizinhas-mortas” são todas as células vizinhas a qualquer célula viva). 

<b>REQ05</b>: O sistema deverá permitir ao usuário limpar todas as células do mundo (limpar totalmente o mapa).

<b>REQ06</b>:  O sistema deverá permitir ao usuário iniciar a simulação da evolução das células em sequencia de gerações utilizando uma matriz auxiliar para a próxima geração imediata.

<b>REQ07</b>: O sistema deverá permitir ao usuário estipular uma determinada quantidade de gerações a serem simuladas, sempre identificando-as e apresentando-as na tela. 

<b>REQ08</b>: O sistema deverá permitir ao usuário definir a velocidade de sucessão das
gerações. No caso de velocidade zero, então a simulação deverá ser passo-a-passo conforme acionado pelo operador, sempre visualizando as gerações que se sucedem. 

<b>REQ09</b>: O sistema deverá ser aprimorado substituindo a matriz auxiliar por uma listas implesmente ligada usando alocação dinâmica de memória, o que dispensa o dimensionamento prévio de espaço para a memória auxiliar e otimiza todo o processo.

<b>REQ10</b>: O sistema deverá apresentar na tela logo abaixo do mapa, as listas das células vivas e das vizinhas-mortas.

<b>REQ11</b>: O sistema deverá permitir ao usuário salvar as gerações iniciais de células vivas em arquivo, gravadas sucessivamente. 

<b>REQ12</b>: O sistema deverá permitir ao usuário carregar cada geração previamente
armazenada no arquivo de forma sucessiva conforme seu comando. 

##





















