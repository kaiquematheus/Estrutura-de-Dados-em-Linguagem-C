#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FuncoesProcedimentosFREE.c"

//Main
int main(int argc, const char * argv[]){
	TREE arv;
	int op, valor;
		printf("\nPORFAVOR ANTES DE FAZER QUALQUER AÇÃO INICIA A LISTA COM A OPÇÃO 1\n\n");
	do{
		printf("Ecolha uma das opções!\n");
		printf("(0) Sair\n");
		printf("(1) Iniciar Arvore \n");
		printf("(2) Inserir Elemento na Arvote\n");
		printf("(3) Passeio Infixo\n");
		printf("(4) Passeio Prefixo\n");
		printf("(5) Passeio Posfixo\n");
		printf("(6) Mostra qual o maior elemento da Arvore\n");
		printf("(7) Mostra qual o menor elemento da Arvore\n");
		printf("(8) Remove elemento \n");
		printf("(9) Numero de elementos na Arvore\n");
		printf("(10) Numero de folhas na Arvore\n");
		printf("(11) Saber o nivel de algum elemento\n");
		printf("(12) Mostrar a altura da Arvore \n");
		printf("(13) Mostrar todos os elementos folha\n");
		printf("(14) Mostrar todos os elementso não folha\n");
		printf("(15) Mostra 1 se a arvore for estritamente binária e 0 caso contrario \n");
		printf("(16) Mostrar a soma de todos os elementos da arvore\n");
		printf("(17) Buscar o elemento desejado\n");
		printf("(18) Verifica se um elemento existe na arvore\n");
		printf("\nEscolha a opção:");
		scanf("%d",&op);
		switch(op){

			case 1:
				system("clear");
				arv = NULL;
				printf("Arvore iniciada\n\n");
				printf("Obrigado pro inicializar a lista!!\n\n");
			break;

			case 2://a)
				system("clear");
				printf("\n");
				printf("Inserindo ELEMENTO\n\n");
				printf("Informe o elemento que deseja incerir:");
				scanf("%d",&valor);
			// chamada para inserir elemento na arvore
				insArvore(&arv,valor);
			//	insArvore(&arv,5);
			//	insArvore(&arv,3);
			//	insArvore(&arv,14);
			//	insArvore(&arv,7);
			//	insArvore(&arv,18);
			//	insArvore(&arv,11);
			//	insArvore(&arv,15);
			//	insArvore(&arv,17);
				printf("\n\n");
			break;

			case 3: // j)
				system("clear");
				printf("\nArvore Passeio Infixo: ");
				passeioIn(arv);
				printf("\n\n");
				
			break;

			case 4:// k)
				system("clear");
				printf("\nnArvore Passeio prefixo: ");
				passeioPre(arv);
				printf("\n\n");
			break;

			case 5:// l)
				system("clear");
				printf("\nArvore Passeio posfixo: ");
				passeioPos(arv);
				printf("\n\n");
			break;

			case 6: // c)
				system("clear");
				printf("Maior elemento da Arvore: ");
				printf("[%i]\n\n",maior(&arv)->dado);
			break;

			case 7:// d)
				system("clear");
				printf("\nMenor elemento da Arvore: ");
				printf("[%i]\n\n",menor(&arv)->dado);
			break;

			case 8:// b)
				system("clear");
				printf("Informe o elemento que deseja remover:");
				scanf("%d",&valor);
				printf("Remove o elemento %i",valor);
				remover(&arv,valor);				

			break;

			case 9:// h)
				system("clear");
				printf("Numero de elementos na arvore: ");
				printf("%i ",contarNos(arv));
				printf("\n\n");
				
			break;

			case 10:
				system("clear");
				printf("Numero de folhas na arvore: ");
				printf("%i ",contarFolhas(arv));
				printf("\n\n");
				
			break;

			case 11:// n)
				system("clear");
				printf("Informe o elemento que deseja saber o nivel:");
				scanf("%d",&valor);
				printf("\nO elemento %i tem nivel %i",valor,nivelNoh(arv,valor));
				printf("\n\n");
			break;

			case 12:// m)
				system("clear");
				printf("A Arvore tem altura: %i",altura(arv));
				printf("\n\n");

			break;

			case 13: // o)
				system("clear");
				printf("Elementos folha da arvore: ");
				mostrarFolhas(arv);
				printf("\n\n");			
			break;

			case 14: // p)
				system("clear");
				printf("Elementos Não folha da arvore: ");
				mostrarNaoFolhas(arv);
				printf("\n\n");	
			break;

			case 15:
				system("clear");
				printf("Arvore: %i ",ABBestritamenteBinaria(arv));
				
				printf("\n\n");	
			break;
	
			case 16:// i)
				system("clear");
				printf("Soma dos elementos da arvore: %i",soma(arv));
				printf("\n\n");	
			break;

			case 17:
				system("clear");
				printf("Informe o elemento que deseja :");
				scanf("%d",&valor);
				printf("Elemento : ");
				elementoDesejado(arv,valor);
				printf("\n\n");	
			break;

			case 18:
				system("clear");
				printf("Retorna 1 caso o elemento exista e 0 caso não exista\n");
				printf("Informe o elemento que deseja saber se existe :");
				scanf("%d",&valor);
				printf("Existe: %i",verificaElemento(arv,valor));
				printf("\n\n");	
			break;

			default:
				printf("Fim\n");
		}
	}while(op != 0);
	return 0;
}
//Kaíque Matheus R. Cunha  3° SI
