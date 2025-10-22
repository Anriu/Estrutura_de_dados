#include <stdio.h>
#include <stdlib.h>


int main(){
    
    char nome[]= "Anriu Oliveira";
    char *ponteiro = nome;
    int contador = 0;


    while (*ponteiro != '\0'){
        ponteiro++;
        contador++;
    }
    
    printf("Quantidade de caracteres: %d\n", contador);
    printf("\nPs:Incluindo caracteres de espaco como no nome 'Professor Leandro' tera  17 caracteres ao invez de 16 por conta do espaco entre os dois nomes");


    return 0;
}