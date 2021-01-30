// struct
struct noh{
	int dado;
	struct noh *prox;
};
typedef struct noh *LLCSE;
	
//Inicia a lista
void inicia(LLCSE *L){
	*L= NULL;
}

//Procedimento para inserir no inicio
void insInicio(LLCSE *L, int vr){
	LLCSE novo = (LLCSE) malloc(sizeof(struct noh));
	LLCSE  aux = *L;
	if(novo){
		novo->dado = vr;
		if(!*L){
			*L= novo;
			novo->prox = *L;	
		}else{
			for(aux= *L; aux->prox!=*L;aux=aux->prox);
				novo->prox = *L;
				aux->prox = novo;
		}
	}
	*L = novo;
}

//Procedimento para inserir no final
void insFinal(LLCSE *L, int vr){
	LLCSE novo = (LLCSE) malloc(sizeof(struct noh));
	LLCSE aux = *L;
		if(novo){
			novo->dado = vr;
			if(!*L){
				*L = novo;
				novo->prox = *L;
				
			}else{
				for(aux=*L;aux->prox!= *L;aux=aux->prox);
				novo->prox = *L;
				aux->prox = novo;	
			}
		}
}
//Insere elementos ordenados
void insOrdenado(LLCSE *L, int valor){
	LLCSE aux = *L;
	LLCSE novo = (LLCSE) malloc(sizeof(struct noh));
	novo->dado = valor;
	if(*L){
		if(aux->dado >= valor){
			for(aux = *L;aux->prox != *L; aux=aux->prox);
			novo->prox = *L;
			*L = novo;
			aux->prox = *L;
		}
		while(aux->prox != *L && aux->dado < valor){
			if(aux->dado < valor && (aux->prox)->dado >= valor){
				novo->prox= aux->prox;				
				aux->prox = novo;
			}
			aux=aux->prox;		
		}
		if(aux->prox == *L && aux->dado <= valor){
			aux->prox = novo;
			novo->prox = *L;
		}
	}else{
		if(*L == NULL){
			*L = novo;
			novo->prox = *L;
		}
	}
}
//Remove o elemento do inicio
void removeInicio(LLCSE *L){
	if(*L){
		LLCSE aux = *L,aux2;
		if(aux->prox != *L ){
			for(aux2=*L; aux2->prox != *L; aux2 = aux2->prox);
			*L = aux->prox;
			free(aux);
			aux2->prox= *L;
		}else{
			if(aux->prox == *L){
				*L= NULL;
				free (aux);
			}			
		}
	}
}


//Remove o elemento do final
void removeFinal(LLCSE *L){
	if(*L){
		LLCSE aux=*L,aux2;
		if(aux->prox == *L){
			*L= NULL;
			free(aux);	
		}else{
			for(aux = *L; aux->prox != *L; aux=aux->prox){
				aux2 = aux;
			}
			aux2->prox = *L;
			free(aux);
		}
	}else{
		printf(" Não há lista!\n");
	}
}
//Remove o elemento pelo valor
void removPorValor(LLCSE *L, int valor){
	if(*L){
		LLCSE aux = *L,aux2 = NULL;
		if(aux->dado == valor && aux->prox !=*L){
			for(aux2=*L; aux2->prox != *L; aux2 = aux2->prox);
				*L = aux->prox;
				free(aux);
				aux2->prox= *L;
		}
		
		while(aux->prox != *L){
			aux2 = aux;
			aux = aux->prox;
			if(aux->dado == valor && aux->prox != *L){
				aux2->prox = aux->prox;
				free(aux);
				aux=aux2;
			}
			if(aux->dado == valor && aux->prox == *L){
				aux2->prox = *L;
				free(aux);
			}
		}
		aux=*L;
		if(aux->dado == valor){
			*L = *L;
			free(aux);
		}
	}else{
		printf("\nNão e possivel remorver um elemento por valor!\n");
		printf("Não exitste lista!\nPorfavor crie uma lista!!\n");
	}
}

//Separa a lista a partir de um valor informado
void separaListaValor(LLCSE *L, LLCSE *LS, int valor){
	if(*L){
		LLCSE aux = *L,aux2= NULL;
		if(aux->dado == valor){
			*LS = aux;
			for(aux = *L; aux->prox != *L; aux=aux->prox);
			aux->prox = *LS;			
			*L =NULL;
		}else{
			while(aux->dado != valor){
				aux2=aux; aux=aux->prox;
				if(aux->dado == valor){
					*LS = aux;
					aux2->prox = *L;
					for(aux2 = *LS; aux2->prox != *L; aux2=aux2->prox);
					aux2->prox = *LS;
				}
			}
		}
	}else{
		printf("\nNão e possivel separa a lista pelo valor!\n");
		printf("Não exitste lista!\nPorfavor crie uma lista!!\n");
	}
}

//Separa a lista a partir de um indice informado
void separaListaIndice(LLCSE *L, LLCSE *LS, int indice){
	if(*L){
		LLCSE aux = *L;
		LLCSE aux2 = NULL;
		//indice = indice -1;
		int cont = 0;
		if(cont == indice){
			*LS = aux;
			for(aux = *L; aux->prox != *L; aux=aux->prox);
			aux->prox = *LS;			
			*L =NULL;
		}
		while(cont != indice || aux == *L){
			aux2=aux; aux=aux->prox;
			cont ++;
			if(cont == indice){
				*LS = aux;
				aux2->prox = *L;
				for(aux2 = *LS; aux2->prox != *L; aux2=aux2->prox);
				aux2->prox = *LS;
			}	
		}
	}
}
//Concatene duas listas
void juntandoDuasListas(LLCSE *L, LLCSE *LS){
	if(*L){
		LLCSE aux,aux2;
		for(aux = *L; aux->prox != *L; aux=aux->prox);
			aux->prox = *LS;
		for(aux2 = *LS; aux2->prox != *LS; aux2=aux2->prox);
		aux2->prox = *L;
		*LS = NULL;
	}else{
		if(*LS){
			LLCSE aux;
			*L=*LS;
			for(aux = *L; aux->prox != *L; aux=aux->prox);
			aux->prox = *L;
		}
	}
}

//Limpar a lista
void limpaLista(LLCSE *L){
	if(*L){
		LLCSE aux = *L;
		LLCSE aux2=*L;
		while(aux->prox!=*L){
			aux2 = aux;
			free(aux);
			aux=aux2->prox;
		}
	free(aux);
	*L=NULL;
	}
}

//Ordena lista crescente
void ordenaListCrescente (LLCSE *L, LLCSE *LS){
	LLCSE aux = *L;
	limpaLista(LS);
	while (aux->prox != *L){
		insOrdenado(LS,aux->dado);
		aux = aux->prox;
	}
	insOrdenado(LS,aux->dado);
	limpaLista(L);
	*L = *LS;
	*LS = NULL;
}

//Inverte a lista
void inverterLista (LLCSE *L,LLCSE *LS){
	LLCSE aux =NULL, aux2 = *L;
	int i;
	if (*L){
		while (aux2->prox != *L){
			aux2 = aux2->prox;
		}
		aux2->prox = NULL;
	
		while (*L != NULL){
			if (*LS){
				aux = *L;
				*L = (*L)->prox;
				aux->prox = *LS;
				*LS = aux;				
			}else{
				*LS = *L;
				*L = (*L)->prox;
				(*LS)->prox = NULL;
			}
		}
	}
	aux2 = *LS;
	while (aux2->prox != *L){
		aux2 = aux2->prox;
	}
	aux2->prox = *LS;

	*L = *LS;
	*LS = NULL;
}

// Mostrar os elementos da lista
void imprimir(LLCSE L){
	LLCSE aux = L;
	if(L != NULL){
		while(aux->prox != L){
			printf("[%d] ",aux->dado);
			aux = aux->prox;
		}
		printf("[%d]\n",aux->dado);
	}else{
		 printf(" Não a lista!");
	}
}

//Kaíque Matheus R. Cunha  3° SI
