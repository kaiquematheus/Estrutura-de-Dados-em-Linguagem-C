#include <stdio.h>
#include "pensando_em_fila.c"

int main(int argc, const char * argv[]){
    int num, i;
    FILA fila;
    init(&fila);

    printf("1 - Entrar na fila");
    printf("2 - Atender Cliente");
    printf("3 - Verificar fila");
 /*   printf("");
    printf("");
   */ 
    printf("Escola uma das opções: ");
    scanf("%i", &num);
    switch (num){
        case 1: 
                printf("Numero do cliente");
                scanf("%d", &i);
                ins(&fila, i);
        break;
        
        case 2: 
                printf("");
        break;
        
        case 3: 
                printf("");
        break;
            
        case 4: 
                printf("");
        break;
        default:
             printf("Fim");
               
    
    
    }
        
return 0;
}
