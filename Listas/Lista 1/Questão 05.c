#include <stdio.h>
#include <stdlib.h>

int main(){
    int vetor[5] = {0,2,18,8,10};
    int *ponteiro = vetor;
    int *ponteiro_aux = ponteiro;
    
    for(int i = 0; i < 5; i++){
        if(*(ponteiro+i) > *ponteiro_aux){
            *ponteiro_aux = *(ponteiro+i);
        }
    }

    printf("Maior valor do vetor = %d", *ponteiro_aux);


    return 0;
}