#include <stdio.h>
#include <stdlib.h>
#include "FuncoesProcedimentosDEQUE.c"

//Main
int main(int argc, const char * argv[]){
	DEQUE deq;
	
	//Inicia a lista
	inicia(&deq);

	//Insere elementos no inico da lista
	insInicio(&deq,30);
	insInicio(&deq,20);
	insInicio(&deq,10);

	//Insere elementos no final da lista
	insFinal(&deq,40);
	insFinal(&deq,50);
	insFinal(&deq,60);

	//Remove elementos no final da lista
	removeFinal(&deq);

	//Remove elementos no inicio da lista
	removeInicio(&deq);

	//Mostra o primeiro elemento da lista
	mostraPrimeiroElemento(&deq);

	//Mostra o ultimo elemento da lista
	mostraUltimoElemeto(&deq);

	//Limpa a lista;
	limpaLista(&deq);

	return 0;
}
//Kaíque Matheus R. Cunha
