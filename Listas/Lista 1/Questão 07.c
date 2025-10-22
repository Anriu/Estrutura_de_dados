#include <stdio.h>
#include <stdlib.h>

void soma_vetor(int *vetor, int *soma){
    for(int i = 0; i < 6; i++){
        *soma += *(vetor+i);
    }
}

int main(){
    int vetor[] = {0,2,4,8,10,0};
    int soma = 0;

    soma_vetor(vetor, &soma);
    printf("Soma do vetor e de %d", soma);
      
    return 0;
}