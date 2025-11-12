typedef struct {
    int idPessoa;
    char nome[100];
    int idade;
    float peso;
    float altura;
} Aluno;

int cadastrar_aluno(Aluno **alunos, int *quantidade_alunos);
void listar_todos_alunos(Aluno *alunos, int quantidade_alunos);
void buscar_aluno_por_nome(Aluno *alunos, int quantidade_alunos);