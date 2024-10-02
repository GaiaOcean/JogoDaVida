/* Model.h
*/



#ifndef JDV_BGLL_MODEL_H
#define JDV_BGLL_MODEL_H

#include <stdio.h>

typedef struct{
	char situacao; // "." se estiver vazio ou morto, "O" se tiver ocupado.
}Mundo;

Mundo Tab[60][60];
Mundo TabAux[60][60];

void inicializarMundo(Mundo Tab[60][60], Mundo TabAux[60][60], int tamanho);
void mostrarMundo(Mundo Tab[60][60], Mundo TabAux[60][60], int tamanho);

#endif