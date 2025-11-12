#include <stdio.h>
#include <locale.h>
#include "utilitarios.h"

//Função que identifica o sistema operacional e depois limpa a tela do terminal
void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

//Função que identifica o sistema operacional e pausa o terminal
void pausar_tela() {
    #ifdef _WIN32
        system("pause");
    #else
        printf("Pressione ENTER para continuar...");
        getchar(); getchar(); // garante leitura correta após scanf
    #endif
}

void locale_UTF(){
    // Configuração de locale/UTF-8
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #else
        setlocale(LC_ALL, "C.UTF-8"); // Linux/macOS
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
