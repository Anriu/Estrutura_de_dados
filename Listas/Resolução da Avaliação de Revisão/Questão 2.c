#include <stdio.h>
#include <stdlib.h>

int inserirElemnto(int vetor[], int capacidadeMaxima, int *tamanhoAtual, int novoValor, int indiceInsercao){
	
	int *ponteiro = vetor;
	
	//Verifica se a posicao informada existe
	if(indiceInsercao <= capacidadeMaxima && indiceInsercao >= 0){
		if(*tamanhoAtual < capacidadeMaxima){
			
			for(int i = *tamanhoAtual; i > indiceInsercao; i--){
				//Desloca os valores apatir da posicao informada 1 casa à direita
				*(ponteiro + i) = *(ponteiro + i - 1);
			}
			//Posiciona o novo valor no indice correto
			*(ponteiro + indiceInsercao) = novoValor;
			//atualiza o tamanho do vetor
			(*tamanhoAtual)++;
			//Funcao pode ser execultada pois existem posicoes livre e a posicao é válida
			return 1;
		}
			
	}
	//Nao existem posições livres ou a posição foi invalida
	return 0;	
}

int main(){
	
	int capacidadeMaxima;
	int tamanhoAtual = 0;
	int novoValor;
	int indiceIsercao;
    int tamanhoInicial;
	
	
	printf("Informe o tamanho do vetor: ");
	scanf("%d",&capacidadeMaxima);
	
	//cria o vetor com o tamanho desejado
	int vetor[capacidadeMaxima];

    printf("Tamanho maximo do vetor %d, quantos valores deseja colocar? ", capacidadeMaxima);
    scanf("%d", &tamanhoInicial);

    for(int i = 0; i < tamanhoInicial; i++){
        system("cls");
        printf("Preencha o vetor de %d casas:\n", tamanhoAtual);
        printf("Valor da casa %d: ", i);
        scanf("%d",&vetor[i]);
        tamanhoAtual++;
    }
	

	printf("informe o novo valor: ");
	scanf("%d",&novoValor);
	
	printf("informe o indice onde o valor sera inserido: ");
	scanf("%d",&indiceIsercao);
	
	
	//Se a funcao poder ser execultada retorna o valor 1, caso contrario retorna 0
	int valida = inserirElemnto(vetor,capacidadeMaxima,&tamanhoAtual,novoValor,indiceIsercao);
	
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