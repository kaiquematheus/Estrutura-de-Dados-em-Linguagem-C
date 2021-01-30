//struct 
struct noh {
	int dado;
	struct noh *ant, *prox;
};
typedef struct noh *LLDE;

// Funções e Parocedimentos
	
//Inicia a lista
void inicia(LLDE *L){
	*L = NULL;
}

//Insere no Inicio
void insreInicioLLDE(LLDE *L, int valor){
	LLDE aux=*L;
	LLDE novo = (LLDE) malloc(sizeof(struct noh));
	if(*L){
		novo->dado = valor;		
		novo->prox=aux;
		aux->ant=novo;
		novo->ant = NULL;
		*L = novo;	
	}else{
		if(*L == NULL){
			novo->dado = valor;
			novo->prox =NULL;
			novo->ant = NULL;
			*L = novo;
		}
	}
}

//Insere no final
void insFinalLLDE(LLDE *L, int valor){
	LLDE aux = *L;
	LLDE novo = (LLDE) malloc (sizeof(struct noh));	
	if(*L==NULL){
		novo->dado = valor;
		novo->prox = NULL;
		novo->ant = NULL;
		*L = novo;
	}else{
		while(aux->prox != NULL){
			aux=aux->prox;
		}
		novo->dado = valor;
		aux->prox = novo;
		novo->ant = aux;
		novo->prox = NULL;
	}
}

// Insere elementos ordenados
void insOrdenadoLLDE(LLDE *L, int valor){
	LLDE aux = *L;
	LLDE novo = (LLDE) malloc(sizeof(struct noh));
	novo->dado = valor;
	if(*L){
		
		if(aux->dado >= valor && aux->ant == NULL){
			novo->prox= aux;
			aux->ant = novo;
			novo->ant = NULL;
			*L = novo;
		}
		while(aux->prox != NULL && aux->dado < valor){
			
			if(aux->dado < valor && (aux->prox)->dado >= valor){
				novo->prox = aux->prox;
				aux->prox = novo;
				novo->ant = aux;
			}
			aux=aux->prox;
		}		
		if(aux->ant != NULL && aux->prox == NULL){
			aux->prox = novo;
			novo->ant= aux;
			novo->prox = NULL;
		}
	}else{
		if(*L == NULL){
			novo->ant = NULL;
			novo->prox = NULL;
			*L = novo;
		}
	}
}

// Remove o elemento no inicio da lista
void removeInicio(LLDE *L){
	if(*L){
		LLDE aux = *L;
		*L = aux->prox;
		aux->ant = NULL;
		free (aux);
	}else{
		printf("\nNão e possivel remover no final!\n");
		printf("Não á elementos na lista!");
	}
}

//Remove o elemento do final da lista
void removeFinal(LLDE *L){
	if(*L){
		LLDE aux = *L,aux2;
		if(*L==NULL){
			free(aux);
		}else{
			while(aux->prox != NULL){
				aux=aux->prox;
			}
			aux2=aux->ant;
			aux2->prox = NULL;
			free (aux);
		}
	}else{
		printf("\nNão e possivel remover no final!\n");
		printf("Não á elementos na lista!");
	}
}

// Remove por Valor
void removePorValor(LLDE *L, int valor){
	if(*L){
		LLDE aux = *L;
		//Caso seja o Primeiro
		while(aux != NULL){
			if(aux->dado == valor && aux->prox == NULL && aux->ant == NULL){
				*L = NULL;				
				free (aux);
			}
			if(aux->dado == valor && aux->prox != NULL && aux->ant !=NULL){
				(aux->ant)->prox = aux->prox;
				(aux->prox)->ant = aux->ant;
				free (aux);
			}
			if(aux->dado == valor && aux->prox == NULL && aux->ant != NULL){
				(aux->ant)->prox = NULL;
				free (aux);
			}
			if(aux->dado == valor && aux->prox != NULL && aux->ant == NULL){
				*L = aux->prox;
				(aux->prox)->ant = NULL;
				aux->prox = NULL;				
				free (aux);
				aux = *L;
			}else{
				aux=aux->prox;
			}
		}
	}else{
		printf("\nNão e possivel remover no final!\n");
		printf("Não á elementos na lista!");
	}
}
//Separa uma lista a partir de um valor informado
void separaListaValor(LLDE *L, LLDE *LS, int valor){
	if(*L){
		LLDE aux = *L, aux2 = NULL;
		while(aux != NULL){
			//Caso esse valor esteja na primeira posição
			if(aux->dado == valor && aux->ant == NULL){
				*LS = *L;
				*L = NULL;
			}
			if(aux->dado == valor && aux->ant != NULL){
				*LS = aux;
				(aux->ant)->prox = NULL;
				aux->ant = NULL;
			}
			aux=aux->prox;
		}
	}else{
		printf("\nNão e possivel separa a lista pelo valor!\n");
		printf("Não exitste lista!\nPorfavor crie uma lista!!\n");
		
	}

}

//Separa uma lista a partir do indece
void separaListaIndice(LLDE *L, LLDE *LS, int indice){
	if(*L){
		LLDE aux = *L,aux2 = NULL;
		indice = indice -1;
		int cont = 0;
		if(cont == indice && aux->ant == NULL){
			*LS = aux;
			*L = NULL;
		}	
		while(cont != indice || aux == NULL){
			cont++;
			aux=aux->prox;
			if(cont == indice){
				*LS = aux;
				(aux->ant)->prox = NULL;			
			}
			
		}
	}else{
		printf("\nNão e possivel separa a lista pelo indice!\n");
		printf("Não exitste lista!\nPorfavor crie uma lista!!\n");
	}
}

// Concatena duas listas
void juntandoDuasListas(LLDE *L, LLDE *LS){
	LLDE aux,aux2;
	if(*L){
		for(aux = *L; aux->prox !=NULL; aux=aux->prox);
		aux2 = *LS;
		aux->prox= aux2;
		aux2->ant = aux;
		*LS = NULL;
	}else{
		if(*L){
			*L=*LS;
		}
	}
}

//Ordena Elementos da Lista

void ordenaListaCrescente(LLDE *L, LLDE *LD){
	
}


//Limpa a lista
void limpaLista(LLDE *L){
	if(*L){
		LLDE aux = *L;
		while(aux->prox != NULL){
			(aux->prox)->ant = NULL;
			*L = aux->prox;
			aux->prox = NULL;
			free(aux);
			aux=*L;
		}
		free(aux);
		*L= NULL;
	}
}

// Inverte a Lista
void inverteLista(LLDE *L, LLDE *LDS){
	if(*L){
		LLDE aux;
		for(aux=*L;aux->prox!=NULL;aux=aux->prox){
			insreInicioLLDE(LDS,aux->dado);
		}
		(insreInicioLLDE(LDS,aux->dado));
		limpaLista(L);
		//free(aux);
		aux = *LDS;
		*L = aux;
		*LDS = NULL;
	}
}

// Imprime os elemento da lista
void imprimir(LLDE L){
	if(L){
		LLDE aux = L;
		if(aux != NULL){
			printf("[%d] ",aux->dado);
			imprimir(aux->prox);
		}else{
			printf("\n");
		}
	}	
}
//Kaíque Matheus R. Cunha  3° SI
