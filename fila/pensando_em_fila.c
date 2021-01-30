#define TAMANHO 10

struct f{
    int dados[TAMANHO];
    int first;
};

typedef struct f FILA;

//
// INIT EMPTY FULL  INS  RAM ATEND
//

int disponivel(FILA f){
    return f.dados[f.first];
}

int empty(FILA f){ // verifica se a pilha tem algum elemento
    return !(f.first+1);//se o resultado for 0 vai retornar a negação de 0 que é 1 então quer dizer que a fila esta vazia. Se o resultado for maior ou igual a 1 então retorna a negação de 1 que é 0 então quer dizer que a fila contem elementos e não esta vazia
    //return (f.fim == -1);
}


int full(FILA f){//verifica se a fila esta cheia
    return (f.first == TAMANHO - 1);// se o f.fim for igual a TAMANHO -1 então a fila não tem mais espaço caso contrario a fila ainda tem espaço.
    //return (TAMANHO -f.fim + 1) // se o resultado de TAMANHO -f.fim+1 for igual a 0 quer dizer que a fila esta cheia caso o resultado diferente de zero que dizer qua a fila ainda tem espaço
}

void init(FILA *f){// inicia a fila
    (*f).first = -1; //
    //f->first=-1;
}

void ins(FILA *f, int elem){// para colocar o elemento na fila
   int i = f->first;
   if(!full(*f)){
        while(i>0){
             f->dados[i+1] = f->dados[i--];
        }
        f->dados[0] = elem;
   }
}
   
void tira(FILA *f){ // retira elemento da fila
    if(!empty(*f)){
        f->first = f->first - 1;
    }
}


