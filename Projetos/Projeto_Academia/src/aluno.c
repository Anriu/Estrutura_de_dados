#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cadastrar_aluno(Aluno **alunos, int *quantidade_alunos){
    limpar_tela();
    printf("┌───────────────────────────────────────────────┐\n");
    printf("│              CADASTRAR ALUNO                  │\n");
    printf("└───────────────────────────────────────────────┘\n");
    Aluno novoAluno;

    printf("ID do Aluno: ");
    scanf("%d", &novoAluno.idPessoa);

    printf("Nome: ");
    scanf(" %[^\n]", novoAluno.nome);

    printf("Idade: ");
    scanf("%d", &novoAluno.idade);

    printf("Altura: ");
    scanf("%f", &novoAluno.altura);

    printf("Peso: ");
    scanf("%f", &novoAluno.peso);

    Aluno *auxiliar = realloc(*alunos, (*quantidade_alunos + 1) * sizeof(Aluno));
    if (auxiliar == NULL) {
        printf("Erro ao alocar memória.\n");
        return 0; // Falha
    }

    *alunos = auxiliar;

    // Copia o aluno preenchido para o final do vetor
    (*alunos)[*quantidade_alunos] = novoAluno;
    (*quantidade_alunos)++;

    return 1; // Sucesso
}

void listar_todos_alunos(Aluno *alunos, int quantidade_alunos){
    limpar_tela();
    if (quantidade_alunos == 0) {
        printf("┌──────────────────────────────────────────────────────────────┐\n");
        printf("│      Nenhum aluno cadastrado até o momento.                  │\n");
        printf("└──────────────────────────────────────────────────────────────┘\n");
        return;
    }

    printf("Alunos Cadastrados\n");
    
    printf("┌──────────────┬───────────────────────────────────────────────────┬────────┬──────────────┬──────────────┐\n");
    printf("│ ID           │ Nome                                              │ Idade  │ Peso (kg)    │ Altura (m)   │\n");
    printf("├──────────────┼───────────────────────────────────────────────────┼────────┼──────────────┼──────────────┤\n");

    for (int i = 0; i < quantidade_alunos; i++) {
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';
        printf("│ %-12d │ %-50.50s│ %-6d │ %-12.2f │ %-12.2f │\n",alunos[i].idPessoa,alunos[i].nome,alunos[i].idade,alunos[i].peso,alunos[i].altura);
    }

    printf("└──────────────┴───────────────────────────────────────────────────┴────────┴──────────────┴──────────────┘\n");
}

void buscar_aluno_por_nome(Aluno *alunos, int quantidade_alunos){
	
}