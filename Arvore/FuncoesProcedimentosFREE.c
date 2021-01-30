#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//Struct
struct noh{
	int dado;
	struct noh *esq, *dir;
};
typedef struct noh *TREE;

//Insere elemento
void insArvore(TREE *arv, int valor){
	if(*arv == NULL){
		*arv = (TREE) malloc(sizeof(struct noh));
		(*arv)->dado = valor;
		(*arv)->esq = NULL;
		(*arv)->dir = NULL;
	}else{
		if(valor < (*arv)->dado){
			insArvore(&((*arv)->esq),valor);
		}else{
			insArvore(&((*arv)->dir),valor);
		}
	}
}

//Faz o Passeio Infixo imprimindo os elementos na tela
void passeioIn(TREE arv){
	if(arv != NULL){
		passeioIn(arv->esq);
		printf("[%i] ",arv->dado);
		passeioIn(arv->dir);
	}	
}

//Faz o Passeio Prefixo imprimindo os elementos na tela
void passeioPre(TREE arv){
	if(arv != NULL){
		printf("[%i] ",arv->dado);
		passeioPre(arv->esq);
		passeioPre(arv->dir);
	}
}

//Faz o Passeio Posfixo imprimindo os elementos na tela
void passeioPos(TREE arv){
	if(arv!=NULL){
		passeioPos(arv->esq);
		passeioPos(arv->dir);
		printf("[%i] ",arv->dado);
	}
}

//Retorna o maior elemento da arvore
TREE maior(TREE *arv){
	TREE p;
	p = *arv;
	if(*arv){
		if(p->dir==NULL){
			*arv=(*arv)->esq;
			return p;
		}
	}
	return maior(&((*arv)->dir));
}

//Retorna o menor elemento da arvore
TREE menor(TREE *arv){
	if(*arv){
		if((*arv)->esq){
			return menor(&((*arv)->esq));
		}else{
			return *arv;
		}
	}else{
		return NULL;
	}
}

//Remove o elemento da arvore
int remover(TREE *arv,int valor){
	TREE p;
	if(*arv){
		if(valor==(*arv)->dado){
			p=*arv;
			if((*arv)->esq==NULL){
				*arv=(*arv)->dir;
			}else{
				if((*arv)->dir==NULL){
					*arv=(*arv)->esq;
				}else{
					p=maior(&((*arv)->esq));					
					(*arv)->dado=p->dado;
				}
				free(p);
			}
			
		}else{
			if(valor < (*arv)->dado){
				remover(&((*arv)->esq),valor);
			}else{
				remover(&((*arv)->dir),valor);
			}
		}
	}else{
		return 0;
	}
}
//Encontra o numero de Nos da arvore
int contarNos(TREE arv){
	int cont;
	if(arv == NULL){
		return 0;
	}else{
		 return 1 + contarNos(arv->esq) + contarNos(arv->dir);
	}
}

//Encontra o numero de folhas da arvore
int contarFolhas(TREE arv){
	if(arv == NULL){
		return 0;
	}
	if(arv->esq == NULL && arv->dir == NULL){
		return 1;
	}   
	return contarFolhas(arv->esq) + contarFolhas(arv->dir);
}

//Mostra elementos folhas da arvore
void mostrarFolhas(TREE arv){
	if(arv != NULL){
		mostrarFolhas(arv->esq);
		mostrarFolhas(arv->dir);
		if(arv->esq == NULL && arv->dir == NULL){	
			printf("[%i] ",arv->dado);
		}
	}	
}

//Mostra elementos não folhas da arvore
void mostrarNaoFolhas(TREE arv){
	if(arv != NULL){
		mostrarNaoFolhas(arv->esq);
		mostrarNaoFolhas(arv->dir);
		if(arv->esq != NULL || arv->dir != NULL){	
			printf("[%i] ",arv->dado);
		}
	}	
}

//Retorna o nivel de qualquer elemento da arvore
int nivelNoh (TREE arv,int valor){
	
	if (arv->dado == valor){
		return 0;
	}else{
		return 1  + (arv->dado > valor? nivelNoh(arv->esq,valor) : nivelNoh(arv->dir,valor));
	}
}

//Verifica qual e maior
int verificaQualEoMaior(int num1, int num2){
	if(num1 > num2){
		return num1;
	}else{
        	return num2;
	}
}

// Retorna a altura da arvore
int altura(TREE arv){
   	if((arv== NULL) || (arv->esq == NULL && arv->dir == NULL)){
       		return 0;
   	}else{
       		return 1 + verificaQualEoMaior(altura(arv->esq),altura(arv->dir));
	}
}

int soma(TREE arv) {
    	if (arv == NULL){
    		return 0;
	}else{
   		return soma(arv->esq) + soma(arv->dir) + (0+arv->dado);
	}
}

int ABBestritamenteBinaria(TREE arv){
	if(arv != NULL){
		if(arv->esq == NULL && arv->dir == NULL){
			return 1;
		}else{				
			return 0 + (ABBestritamenteBinaria(arv->esq) && ABBestritamenteBinaria(arv->dir));
		}
	}else{		
	}
}

void elementoDesejado(TREE arv,int valor){
	if(arv != NULL){
		if(arv->dado == valor){
			printf("%i",arv->dado);
		}
		elementoDesejado(arv->esq,valor);
		elementoDesejado(arv->dir,valor);	
	}
}

int verificaElemento(TREE arv,int valor){
	int aux = NULL;
	if(arv != NULL){
		if(arv->dado == valor){
			aux = arv->dado;
		}
		verificaElemento(arv->esq,valor);
		verificaElemento(arv->dir,valor);
		
	}
	if(aux == valor){
		return 1;
	}else{
		return 0;
	}
}
//Kaíque Matheus R. Cunha  3° SI
