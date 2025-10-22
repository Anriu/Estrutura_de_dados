#include <stdio.h>
#include <stdlib.h>

void soma_valores(int *v1, int *v2, int *soma){
    *soma = *v1 + *v2;
}

int main(){

    int valor1, valor2, soma = 0;

    printf("Informe um valor: ");
    scanf("%d", &valor1);
    printf("Informe um valor: ");
    scanf("%d", &valor2);


    //Passando as variaveis como referencia
    soma_valores(&valor1, &valor2, &soma);
    
    printf("\n");
    printf("%d + %d = %d\n", valor1, valor2, soma);


    return 0;
}