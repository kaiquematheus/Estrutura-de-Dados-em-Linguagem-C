#include<stdlib.h>
#include <time.h>

//Gera numeros aleatoreos
void preenche(int vetor[], int TAMANHO_VETOR){
	int i;
	srand((unsigned)time(NULL));//time garante elementos aleatorios
	//Preenche o vetor
	for(i = 0; i < TAMANHO_VETOR; i++){
		vetor[i] = rand() % 20 + 1;

	}
}

//Imprime o vetor
void imprimeVetor(int vetor[],int TAMANHO_VETOR){
	int i;
	printf("\n");
	for(i = 0; i < TAMANHO_VETOR; i++){
		printf("[%i] ",vetor[i]);
	}
	printf("\n");
}

//Shell Sort metodo para ordenar os elementos do vetor
void shellSort(int vetor[], int TAMANHO_VETOR){
	int pulo=1;/*Inicia o pulo com o valor 1 para dar inicio aos calculos*/
	while(pulo < TAMANHO_VETOR) {
		pulo = pulo * 3 + 1; /*Calculo para encontrar o valor ideal*/
	}    
	pulo = pulo / 3;/*divide o pulo por 3 para obter o pulo ideal*/ 
	int valor, j,i;    
    	while (pulo > 0) {
	      	for (i = pulo; i < TAMANHO_VETOR; i++) {
			valor = vetor[i]; /* c recebe o valor de elemento na posição [i]*/
            		j = i;
            		while (j >= pulo && vetor[j - pulo] > valor) { /* Compara dois elementos de posições diferentes*/
                		vetor[j] = vetor[j - pulo]; /*troca o segundo elemento com o primeiro*/
                		j = j - pulo;
            		}
            		vetor[j] = valor;/*coloca o valor na posição de [j]*/
        	}
        	pulo = pulo / 2;/*Decrementa o pulo ate o pulo ser igual a 1*/
    }

}
