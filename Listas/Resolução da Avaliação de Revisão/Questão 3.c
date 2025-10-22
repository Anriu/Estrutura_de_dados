#include <stdio.h>
#include <stdlib.h>

int removerPrimeiraOcorrencia(int vetor[], int *tamanhoAtual, int valorAlvo){
    
    //Iniciando a variavel primeiraOcorrencia com um valor fora do vetor para ter certeza que a posiçao do valor alvo pertence ao vetor
    int primeiraOcorrencia = *tamanhoAtual + 1;
    int *ponteiro = vetor;

    for(int i = 0; i < *tamanhoAtual; i++){
        if(vetor[i] == valorAlvo){
            primeiraOcorrencia = i;
            break;
        }
    }

    (*tamanhoAtual)--;
    if( primeiraOcorrencia != (*tamanhoAtual + 1)){
        for(int i = primeiraOcorrencia; i < *tamanhoAtual; i++){
		    //Desloca os valores apatir da posicao informada 1 casa à direita
		    *(ponteiro + i) = *(ponteiro + i + 1);
	    }
        return 1;
    } 
    
    return 0;
    
}

int main(){
    
    int tamanhoMaximo;
    int tamanhoAtual = 0;
    int valorAlvo;
    int tamanhoInicial;

    printf("Informe o tamanho do vetor: ");
	scanf("%d",&tamanhoMaximo);
	//cria o vetor com o tamanho desejado
    int vetor[tamanhoMaximo];


	printf("Tamanho maximo do vetor %d, quantos valores deseja colocar? ", tamanhoMaximo);
    scanf("%d", &tamanhoInicial);

    for(int i = 0; i < tamanhoInicial; i++){
        system("cls");
        printf("Preencha o vetor de %d casas:\n", tamanhoMaximo);
        printf("Valor da casa %d: ", i);
        scanf("%d",&vetor[i]);
        tamanhoAtual++;
    }

    printf("informe o valor alvo: ");
    scanf("%d", &valorAlvo);

    int valida = removerPrimeiraOcorrencia(vetor,&tamanhoAtual,valorAlvo);

    if(valida == 1){
        //possivel
        system("cls");
        printf("Vetor: ");
        for(int i = 0; i < tamanhoAtual; i++){
            printf(" %d ", vetor[i]);
        }
        printf("\ntamanho atual = %d", tamanhoAtual);
    } else{
        system("cls");
        //não possivel
        printf("Nao foi possivel realizar a oprecao");
    }

	return 0;
}