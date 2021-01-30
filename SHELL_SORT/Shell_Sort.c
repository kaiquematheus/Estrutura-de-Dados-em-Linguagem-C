#include<stdio.h>
#include<stdlib.h>
#include "funcoes.c"
#define TAMANHO_VETOR 10 // Define TAMANHO_VETOR com o valor de 10

//Main
int main(int argc, const char * argv[]){
	
	int vetor[TAMANHO_VETOR];/*Criando o vetor de tamanho TAMANHO_VETOR = 10*/

	//Gera numeros aleatoreos
	preenche(vetor,TAMANHO_VETOR);
	
	//Imprime o vetor
	imprimeVetor(vetor,TAMANHO_VETOR);
	
	//Ordena elementos
	shellSort(vetor,TAMANHO_VETOR);

	printf("\nElementos ordenados\n");

	imprimeVetor(vetor,TAMANHO_VETOR);

	printf("\n");

	return 0;
}
