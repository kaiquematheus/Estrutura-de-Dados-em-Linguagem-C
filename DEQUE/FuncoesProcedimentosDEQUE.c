//Struct
struct noh{
	int dado;
	struct noh *prox, *ant;
};
typedef struct noh *Fila;

struct Deque{
	int quant;
	struct noh *inicio, *final;
};
typedef struct Deque *DEQUE;

//Cria lista vazia(Nula)
void inicia(DEQUE *deq){
	(*deq) = (DEQUE) malloc(sizeof(struct Deque));
	if(deq != NULL){
		(*deq) ->final = NULL;
		(*deq) ->inicio = NULL;
		(*deq) ->quant = 0;
	}
}

//Limpar lista ou destruir a lista
void limpaLista(DEQUE *deq){
	if(deq != NULL){
		Fila no;
		while((*deq) -> inicio != NULL){
			no = (*deq) -> inicio;
			(*deq) -> inicio = (*deq) -> inicio -> prox;
			free(no);
			(*deq) -> quant--;
		}
	}
}

//Insere no inicio
void insInicio(DEQUE *deq, int valor){
	if(deq != NULL){
		Fila novo = (Fila) malloc(sizeof(struct noh));
		if(novo){
			novo->dado = valor;
			novo->prox = (*deq)->inicio;
			novo->ant = NULL;
			if((*deq)->inicio == NULL) (*deq)->final = novo;
			else(*deq)->inicio->ant = novo;	
			(*deq)->inicio = novo;
			(*deq)->quant++;
		}
	}
}

//Insere no final
void insFinal(DEQUE *deq, int valor){
		if(deq != NULL){
		Fila novo = (Fila) malloc(sizeof(struct noh));		
		if(novo){
			novo->prox = NULL;
			novo->dado = valor;
			if((*deq)->final == NULL){
				(*deq)->inicio = novo;
				novo->ant = NULL;
			}
			else{
				novo->ant = (*deq)->final;
				(*deq)->final->prox = novo;
			}
			(*deq)->final = novo;
			(*deq)->quant++;
		}
	}
}

//Remove no final da lista
void removeFinal(DEQUE *deq){
	if(deq != NULL){
		if((*deq)->final != NULL){
			Fila no = (*deq)->final;
			(*deq)->final = (*deq)->final->ant;
			if((*deq)->final == NULL) (*deq)->inicio = NULL;
			else (*deq)->final->prox = NULL;
			free(no);
			(*deq)->quant--;
		}
	}
}

//Remove no final
void removeInicio(DEQUE *deq){
	if(deq != NULL){
		if((*deq)->inicio != NULL){
			Fila no = (*deq)->inicio;
			(*deq)->inicio = (*deq)->inicio->prox;
			if((*deq)->inicio == NULL) (*deq)->final = NULL;
			else (*deq)->inicio->ant = NULL;
			free(no);
			(*deq)->quant--;
		}
	}
}
//Mostra primeiro elemento do deque
void mostraPrimeiroElemento(DEQUE *deq){
	printf("\nPrimeiro elemento do deq: %d\n", (*deq)->inicio->dado);

}
//Mostra ultimo elemento do deque
void mostraUltimoElemeto(DEQUE *deq){
	printf("\nUltimo elemento do deq: %d\n", (*deq)->final->dado);

}
//Kaíque Matheus R. Cunha
