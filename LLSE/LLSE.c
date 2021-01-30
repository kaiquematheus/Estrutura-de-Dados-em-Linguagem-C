#include <stdio.h>
#include <stdlib.h>
#include "FuncoesProcedimentos.c"

// main
int main(int argc, const char * argv[]){
	LLSE ll,lls;
	int op,valor;
	
	
		printf("\nPORFAVOR ANTES DE FAZER QUALQUER AÇÃO INICIA A LISTA COM A OPÇÃO 1\n\n");
	do{
		printf("Ecolha uma das opções!\n");
		printf("(0) Sair\n");
		printf("(1) Iniciar a lista\n");
		printf("(2) Inserir no inico da lista\n");
		printf("(3) Inserir no final da lista\n");
		printf("(4) Inserir um elemento na ordem correta\n");
		printf("(5) Remover o primeiro elemento da lista\n");
		printf("(6) Remover o ultimo elemento da lista\n");
		printf("(7) Remover o um elemento pelo valor\n");
		printf("(8) Dividir a lista a partir de um valor\n");
		printf("(9) Dividir a lista a partir de um indice\n");
		printf("(10) Concatenar duas listas\n");
		printf("(11) Ordena uma lista em ordem crescente\n");
		printf("(12) Inverter a Lista\n");
		printf("(13) Limpar a Lista\n");
		printf("(14) Mostrar a lista\n");
		printf("\nEscolha a opção:");
		scanf("%d",&op);
		switch(op){
			case 1:
				
			// chamada para iniciar a lista
				inicia(&ll);		//Letra (a)
				inicia(&lls);
				system("clear");
				printf("Lista iniciada\n\n");
				printf("Obrigado pro inicializar a lista!!\n\n");
			break;

			case 2:
				system("clear");
				printf("\nLista: ");
				imprimir(ll);
				printf("\n\n");
				printf("Inserindo no inico da lista\n\n");
				printf("Informe o elemento que deseja incerir:");
				scanf("%d",&valor);
			// chamada para inserir no inicio da lista
				insInicio(&ll,valor);
				printf("\n\n");
	
			break;

			case 3:
				system("clear");
				printf("\nLista: ");
				imprimir(ll);
				printf("\n\n");
				printf("Inserindo no final da lista\n\n");
				printf("Informe o elemento que deseja incerir:");
				scanf("%d",&valor);
			//chamada para inserir no final da lista
				insFinalLLSE(&ll,valor);
				printf("\n\n");
			break;

			case 4:
				system("clear");
				printf("\nLista: ");
				imprimir(ll);
				printf("\n\n");
				printf("Inserindo um elemento na ordem correta\n\n");
				printf("Informe o elemento que deseja incerir:");
				scanf("%d",&valor);
			//Chamada para inserir um elemento na ordem correta
				insOrdenadoLLSE(&ll,valor);	//Letra (d)
				printf("\n\n");
	
			break;

			case 5:
				system("clear");
				printf("Removendo o primeiro elemento da lista\n");
			//chamada para remover elemento do inicio da lista	
				removInicio(&ll);
				printf("\n\n");
	
			break;

			case 6:
				system("clear");
				printf("Removendo o ultimo elemento da lista\n");
			//chamada para remover elemento do final da lista	
				removFinal(&ll);
				printf("\n\n");
	
			break;
	
			case 7:
				system("clear");
				printf("Removendo o um elemento pelo valor\n");
				printf("\nLista: ");
				imprimir(ll);
				printf("\n\n");
				printf("Qual elemento deseja retirar: ");
				scanf("%d",&valor);
			//chamada para remover elemento desejado
				removPorValor(&ll,valor);				
				printf("\n\nNova lista: ");
				imprimir(ll);
				printf("\n\n");
	
			break;

			case 8:
				system("clear");
				printf("Separando a lista a partir de um valor\n");
				printf("\n");
				imprimir(ll);
				printf("\n");	
				printf("A partir de qual valor deseja separar a lista: ");			
				scanf("%d",&valor);
			//epare uma lista, a partir de um valor informado
				separaListaValor(&ll,&lls,valor);
				printf("\nLista Primaria: ");
				imprimir(ll);
				printf("\n\nLista Secundaria: ");
				imprimir(lls);
				printf("\n\n");
				
			break;

			case 9:
				system("clear");
				printf("Dividindo a lista a partir de um indice\n");
				printf("\n\n");
				imprimir(ll);
				printf("\n\n");	
				printf("A partir de qual indice deseja separar a lista: ");			
				scanf("%d",&valor);
			//Chamada para separar a lista por indice
				separaListaIndice(&ll,&lls,valor);
				printf("\nLista Primaria: ");
				imprimir(ll);
				printf("\n\nLista Secundaria: ");
				imprimir(lls);
				printf("\n\n");
				
			break;

			case 10:
				system("clear");
				printf("Concatenando duas listas\n");
				printf("\nLista Primaria: ");
				imprimir(ll);
				printf("\n\nLista Secundaria: ");
				imprimir(lls);
				printf("\n\n");
			//Concatena duas listas
				juntandoDuasListas(&ll,&lls); // Letra (m)
				printf("\nLista Concatenada: ");
				imprimir(ll);
				printf("\n\n\n");
	
			break;

			case 11:
				system("clear");
				printf("\nLista: ");
				imprimir(ll);
				printf("\n\n");
				printf("Ordenando lista em ordem crescente No momento não esta funcionando!\n\n");
			//chamanda para Ordenar uma lista em ordem crescente
				//ordenaListCrescente(&ll);
				//printf("\nLista ordenada: ");
				//imprimir(ll);
				//printf("\n\n");
	
			break;

			case 12:
				system("clear");
				printf("\nLista: ");
				imprimir(ll);
				printf("\n\n");
				printf("Invertendo Lista!\n\n");
				inverteLista(&ll,&lls);	
			break;

			case 13:
				system("clear");
				printf("\nLista: ");
				imprimir(ll);
				printf("\n\n");
				printf("Limpando a Lista!\n\n");
				limpaLista(&ll);
			break;

			case 14:
				system("clear");
				printf("\nImprime a lista\n");
			// chamada para imprime a lista
				printf("\nLista: ");
				imprimir(ll);
				printf("\n\n\n");
			break;

			
			default:
				printf("Fim\n");
		}
	}while(op != 0);
	return 0;
}
//Kaíque Matheus R. Cunha  3° SI
