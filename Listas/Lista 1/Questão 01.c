#include <stdio.h>
#include <stdlib.h>


int main(){

    int valor = 50;
    int *ponteiro = &valor;

    //Usando o * para ver qual o valor da variavel que o ponteiro aponta
    printf("Valor da variavel: %d\n", *ponteiro);

    //Sem o uso do * ou & para ver qual o endereço de memoria que o ponteiro aponta
    printf("Endereco da variavel: %p\n", ponteiro);


    return 0;
}