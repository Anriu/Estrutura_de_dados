#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tamanho_string 40


typedef struct {
    char Rua[tamanho_string];
    int numero;
    char complemento[tamanho_string];
    char bairro[tamanho_string];
    char cep[tamanho_string];
    char cidade[tamanho_string];
    char estado[tamanho_string];
    char pais[tamanho_string];

}Endereco;

typedef struct {
    int ddd;
    int numero;
}Telefone;

typedef struct {
    int dia;
    int mes;
    int ano;

}Aniversario;

typedef struct {
    char nome[tamanho_string];
    char email[tamanho_string];    
    Endereco endereco;
    Telefone telefone;
    Aniversario aniversario;
    char observacao[tamanho_string];
}Agenda;

void limpa_tela(){
    system("cls");
}

void cadastra_pessoa(Agenda *agenda, int *controle){

    limpa_tela();
    printf("\n--------------------------------\n");
    printf("INFORME OS DADOS:\n");
    printf("Nome da pessoa: ");
    fgets(agenda[*controle].nome, tamanho_string, stdin);
    printf("Email da pessoa: ");
    fgets(agenda[*controle].email, tamanho_string, stdin);
    printf("\n--------------------------------\n");
    printf("Endereco:\n");
    printf("Rua da pessoa: ");
    fgets(agenda[*controle].endereco.Rua, tamanho_string, stdin);
    printf("Numero da casa: ");
    scanf("%d", &agenda[*controle].endereco.numero);
    printf("Complemento: ");
    fflush(stdin);
    fgets(agenda[*controle].endereco.complemento, tamanho_string, stdin);
    printf("Bairro: ");
    fgets(agenda[*controle].endereco.bairro, tamanho_string, stdin);
    printf("Cep: ");
    fgets(agenda[*controle].endereco.cep, tamanho_string, stdin);
    printf("Cidade: ");
    fgets(agenda[*controle].endereco.cidade, tamanho_string, stdin);
    printf("Estado: ");
    fgets(agenda[*controle].endereco.estado, tamanho_string, stdin);
    printf("Pais: ");
    fgets(agenda[*controle].endereco.pais, tamanho_string, stdin);
    printf("\n--------------------------------\n");
    printf("Telefone:\n");
    printf("DDD: ");
    scanf("%d", &agenda[*controle].telefone.ddd);
    printf("Numero: ");
    scanf("%d", &agenda[*controle].telefone.numero);
    
    (*controle)++;
}

void imprime_pessoa(Agenda *agenda, int indice){
    printf("Nome: %s\n", agenda[indice].nome);
    printf("Email: %s\n", agenda[indice].email);
}

void imprime_endereco(Agenda *agenda, int indice){
    printf("Endereco:\n");
    printf("Rua: %s\n", agenda[indice].endereco.Rua);
    printf("Numero: %d\n", agenda[indice].endereco.numero);
    printf("Complento: %s\n", agenda[indice].endereco.complemento);
    printf("Bairro: %s\n", agenda[indice].endereco.bairro);
    printf("Cep: %s\n", agenda[indice].endereco.cep);
    printf("Cidade: %s\n", agenda[indice].endereco.cidade);
    printf("Estado: %s\n", agenda[indice].endereco.estado);
    printf("Pais: %s\n", agenda[indice].endereco.pais);
}

void imprime_telefone(Agenda *agenda, int indice){
    printf("Telefone: %d - %d", agenda[indice].telefone.ddd,agenda[indice].telefone.numero);
}

void imprime_dados(Agenda *agenda, int indice){
    printf("Dados da Pessoa:");
    imprime_pessoa(agenda,indice);
    imprime_endereco(agenda,indice);
    imprime_telefone(agenda,indice);

}

void busca_nome(Agenda *agenda, int tamanho){
    char nome_fornecido[tamanho_string];
    
    printf("Qual nome deseja procurar: ");
    fgets(nome_fornecido, tamanho_string, stdin);
    nome_fornecido[strcspn(nome_fornecido, "\n")] = '\0';

    for(int i = 0; i < tamanho; i++){
        if (strncmp(nome_fornecido, agenda[i].nome, strcspn(nome_fornecido, " ")) == 0) {
            imprime_dados(agenda, i);
        }
    }
       
}

void busca_mes(Agenda *agenda, int tamanho){
    printf("Informe o mes que deseja buscar: ");
    int mes;
    scanf("%d", &mes);
    
    for(int i = 0; i <tamanho; i++){
        if(mes == agenda[i].aniversario.mes){
            imprime_dados(agenda, i);
        }
    }
}

void busca_dia_mes(Agenda *agenda, int tamanho){
    printf("Informe o dia que deseja buscar: ");
    int dia;
    scanf("%d", &dia);
    printf("Informe o mes que deseja buscar: ");
    int mes;
    scanf("%d", &mes);
    
    for(int i = 0; i <tamanho; i++){
        if(dia == agenda[i].aniversario.dia && mes == agenda[i].aniversario.mes){
            imprime_dados(agenda, i);
        }
    }
}


int main(){
    int tamanho = 3;
    int controle = 0;
    Agenda agenda[tamanho];

    cadastra_pessoa(agenda, &controle);


    //busca_nome(agenda, tamanho);
    
    return 0;
}