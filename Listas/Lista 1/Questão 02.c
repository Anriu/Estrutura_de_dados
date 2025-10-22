#include <stdio.h>
#include <stdlib.h>


void troca_valores(int *v1, int *v2){
    //Variavel auxilar para que um dos valores não seja perdido
    int aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}


int main(){

    int valor1, valor2;

    printf("Informe um valor: ");
    scanf("%d", &valor1);
    printf("Informe um valor: ");
    scanf("%d", &valor2);


    printf("V1 - %d V2 - %d\n", valor1, valor2);

    //Passando as variaveis como referencia
    troca_valores(&valor1, &valor2);
    
    printf("V1 - %d V2 - %d\n", valor1, valor2);


    return 0;
}