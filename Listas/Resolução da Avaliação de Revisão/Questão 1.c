#include <stdio.h>
#include <stdlib.h>

void calcularEstatisticas(int vetor[], int tamanhoAtual, int *valorMinimo, int *valorMaximo, int *mediaTruncada){

    *valorMinimo = vetor[0];
    *valorMaximo = vetor[0];
    int auxMaior, auxMenor;
    int soma = 0, contador = 0;

    for(int i = 0; i < tamanhoAtual; i++){
       
        if(*valorMinimo > vetor[i]){
            *valorMinimo = vetor[i];
            auxMenor = i;
        }

        if(*valorMaximo < vetor[i]){
            *valorMaximo = vetor[i];
            auxMaior = i;
        }
    }

    for(int i = 0; i < tamanhoAtual; i++){
        if( i != auxMaior && i != auxMenor){
            soma += vetor[i];
            contador++;
        }
    }
    
    if(contador != 0){
        *mediaTruncada = soma /contador;
    }
    
}



int main(){
 
    int tamanhoAtual;
    int valorMinimo;
    int valorMaximo;
    int mediaTruncada;

    printf("Qual o tamanho deseja para o vetor? ");
    scanf("%d", &tamanhoAtual);
    int vetor[tamanhoAtual];

    for(int i = 0; i < tamanhoAtual; i++){
        system("cls");
        printf("Preencha o vetor de %d casas:\n", tamanhoAtual);
        printf("Valor da casa %d: ", i);
        scanf("%d",&vetor[i]);
    }


    calcularEstatisticas(vetor, tamanhoAtual, &valorMinimo, &valorMaximo, &mediaTruncada);
    

    system("cls");
    printf("Valor minimo = %d\n",valorMinimo);
    printf("Valor maximo = %d\n",valorMaximo);
    printf("Media truncada = %d\n",mediaTruncada);

    return 0;
}