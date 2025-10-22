#include <stdio.h>
#include <stdlib.h>

void somar(int *vetor, int *soma){
    int *ponteiro = vetor;
    for(int i = 0; i < 6; i++){
        *soma += *(ponteiro + i);
    }
}

int main(){
    int vetor[] = {1,5,8,4,2,1};
    int resultado = 0; 
   
    somar(vetor, &resultado);
    printf("%d", resultado);

    return 0;
}