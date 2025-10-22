#include <stdio.h>
#include <stdlib.h>

int main(){
    int vetor[5] = {0,2,4,8,10};
    int *ponteiro = vetor;

    for(int i = 0; i < 5; i++){
        printf("Posicao %d = %d\n", i, *(ponteiro + i));
    }

    return 0;
}