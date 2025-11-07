#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

typedef struct {
    int idPessoa;
    char nome[100];
    int idade;
    float peso;
    float altura;
} Aluno;

//Função que identifica o sistema operacional e depois limpa a tela do terminal
void limpar_tela() {
    #ifdef _WIN32
        system("cls");       // Windows
    #elif __linux__
        system("clear");     // Linux
    #elif __APPLE__
        system("clear");     // macOS
    #endif
}

//Função que identifica o sistema operacional e pausa o terminal
void pausar_tela() {
    #ifdef _WIN32
        system("pause");     // Windows
    #elif __linux__
        system("read -p \"Pressione ENTER para continuar...\"");  // Linux
    #elif __APPLE__
        system("read -p \"Pressione ENTER para continuar...\"");  // macOS
    #endif
}

//Função que cria o menu na tela, porém é nescessario ter os comandos para utilização de UTF-8
void criar_menu(){
    printf("┌───────────────────────────────────────────────┐\n");
    printf("│               MENU PRINCIPAL                  │\n");
    printf("├───────────────────────────────────────────────┤\n");
    printf("│ 1 - Cadastrar novos alunos                    │\n");
    printf("│ 2 - Listar todos os alunos cadastrados        │\n");
    printf("│ 3 - Buscar um aluno pelo nome                 │\n");
    printf("│ 4 - Buscar um aluno pelo ID (posição no vetor)│\n");
    printf("│ 5 - Remover um aluno pelo nome                │\n");
    printf("│ 6 - Sair do programa                          │\n");
    printf("└───────────────────────────────────────────────┘\n");
}

int cadastrar_aluno(Aluno **alunos, int *quantidade_alunos){
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

int main(){
    //Como set Locale não está funcionando corretamente em alguma maquinas, estou usando o SetConsoleOutputCP
    SetConsoleOutputCP(CP_UTF8); // força saída UTF-8
    SetConsoleCP(CP_UTF8);       // força entrada UTF-8

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
            limpar_tela();
            printf("┌───────────────────────────────────────────────┐\n");
            printf("│              CADASTRAR ALUNO                  │\n");
            printf("└───────────────────────────────────────────────┘\n");
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
   
    return 0;
}