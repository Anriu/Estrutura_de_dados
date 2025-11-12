#include <stdio.h>
#include <stdlib.h>
#include "utilitarios.h"
#include "aluno.h"

int main(){ 
    locale_UTF();

    Aluno *aluno = NULL;
    int quantidade_alunos = 0;
    int escolha = 0;

    do{
        limpar_tela();
        criar_menu();
        printf("O que deseja fazer? : ");
        scanf("%d", &escolha);

        switch (escolha){
        case 1:

            if(cadastrar_aluno(&aluno,&quantidade_alunos) == 1){
                printf("cadastro realizado com sucesso!\n");
                pausar_tela();
            }else{
                printf("Erro ao cadastrar!\n");
                pausar_tela();
            }
            break;
        
        case 2:
            listar_todos_alunos(aluno, quantidade_alunos);
            pausar_tela();
            break;
        
        case 3:
            buscar_aluno_por_nome(aluno, quantidade_alunos);
            break;
        
        case 4:
            
            break;
        
        case 5:
            
            break;
        
        case 6:
            limpar_tela();
            break;

        default:
            printf("Valor inválido tente novamente\n");
            break;
        }

    }while (escolha != 6);

    free(aluno);
    return 0;
}