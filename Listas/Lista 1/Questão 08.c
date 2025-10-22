#include <stdio.h>
#include <stdlib.h>


int main(){
    int vetor[5] = {0,2,4,8,10};
    int *ponteiro = vetor;
    int vetor_aux[5];
    int *ponteiro_aux = vetor_aux;
    int incial = 4;
    
    for(int i = 0; i < 5; i++){
        *(ponteiro_aux + incial) = *(ponteiro+ i);
        incial--;
    }

    printf("Vetor Original:  ");
    for(int i = 0; i < 5; i++){
        printf("%d ", *(ponteiro+ i));
    }

    printf("\n");
    printf("Vetor invertido: ");
    for(int i = 0; i < 5; i++){
        printf("%d ", *(ponteiro_aux+ i));
    }

      
    return 0;
}