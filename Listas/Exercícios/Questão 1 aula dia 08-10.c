#include <stdio.h>
#include <stdlib.h>

void ler_vetor(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("informe o valor da posicao %d: ", i);
        scanf("%d", vetor+i);
    }
}

void mostra_vetor(int *vetor, int tamanho)
    for(int i = 0; i < tamanho; i++)
        printf("vetor[%d] = %d\n", i,*(vetor+i));
    
    system("pause");


void excluir_elemento(int *vetor, int tamanho, int posicao){
    for(int i = 0; i < tamanho; i++){
        if(i == posicao){
            *(vetor+i) = 0;
        }
    }
}

void alterar_elemento(int *vetor, int tamanho, int posicao, int novo_valor){
    for(int i = 0; i < tamanho; i++){
        if(i == posicao){
            *(vetor+i) = novo_valor;
        }
    }
}

int main(){
    int tamanho = 10;
    int vetor[tamanho];
    int escolha;
    int posicao, novo_valor;

    do{
        system("cls");
        printf("1 - ler_vetor\n2 - mostra_vetor\n3 - excluir_elemento\n4 - alterar_elemento\n5 - sair\n");
        printf("O que deseja?");
        scanf("%d", &escolha);

        switch (escolha){
            case 1:
                ler_vetor(vetor, tamanho);
            break;
            case 2:
                mostra_vetor(vetor, tamanho);
            break;
            case 3:
                printf("Qual posição deseja excluir?: ");
                scanf("%d", &posicao);
                excluir_elemento(vetor, tamanho, posicao);
            break;
            case 4:
                printf("Qual posição deseja alterar?: ");
                scanf("%d", &posicao);
                printf("Qual sera o novo valor?: ");
                scanf("%d", &novo_valor);    
                alterar_elemento(vetor, tamanho, posicao, novo_valor);
            break;
    
        default:
            
            break;
        }  
    } while (escolha != 5);
    system("cls");
    printf("FIM.");

    return 0;
}