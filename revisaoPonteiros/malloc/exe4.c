#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum
{
    REPROVADO,
    APROVADO
} Situacao;
typedef struct
{
    int matricula;
    char nome[50];
    float nota1;
    float nota2;
    float media;
    Situacao situacao;
} Aluno;

void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // descarta os caracteres restantes
    }
}

float calcularMedia(float n1, float n2)
{
    return (n1 + n2) / 2;
}

void atualizarSituacao(Aluno *pAluno)
{
    if (pAluno == NULL)
    {
        return;
    }

    if (pAluno->media >= 7)
    {
        pAluno->situacao = APROVADO;
    }
    else
    {
        pAluno->situacao = REPROVADO;
    }
}

int encontrarMaiorMedia(const Aluno turma[], int quantidade)
{
    int iMaior = 0;
    for (int i = 1; i < quantidade; i++)
    {
        if (turma[i].media > turma[iMaior].media)
        {
            iMaior = i;
        }
    }

    return iMaior;
}
int main()
{
    printf("\n=== CADASTRO DINÂMICO DE ALUNO ===");
    int quantidadeAlunos;
    printf("\nInforme a quantidade de alunos: ");
    scanf("%d", &quantidadeAlunos);
    while (quantidadeAlunos <= 0)
    {
        printf("\nInforme uma quantidade válida (maior que zero): ");
        scanf("%d", &quantidadeAlunos);
    }

    Aluno *turma = malloc(quantidadeAlunos * sizeof *turma);
    if (turma == NULL)
    {
        printf("\nFALHA NA ALOCAÇÃO DE MEMÓRIA");
        return -1;
    }

    printf("\n=== CADASTRO DE ALUNOS ===");
    for (int i = 0; i < quantidadeAlunos; i++)
    {
        printf("\n---- ALUNO %d ----", i + 1);
        printf("\nMatrícula: ");
        scanf("%d", &turma[i].matricula);
        limparBuffer();

        printf("\nNome: ");
        fgets(turma[i].nome, sizeof(turma[i].nome), stdin);
        turma[i].nome[strcspn(turma[i].nome, "\n")] = '\0';

        printf("\n++++ Cadastro Notas ++++");
        printf("\nNota 1: ");
        scanf("%f", &turma[i].nota1);
        printf("\nNota 2: ");
        scanf("%f", &turma[i].nota2);
        turma[i].media = calcularMedia(turma[i].nota1, turma[i].nota2);
        atualizarSituacao(&turma[i]);
    }

    printf("\n==== IMPRIMIR ALUNOS ====");
    for (int i = 0; i < quantidadeAlunos; i++)
    {
        printf("\n\n____ ALUNO %d ____", i+1);
        printf("\nMatrícula: %d", turma[i].matricula);
        printf("\nNome: %s", turma[i].nome);
        printf("\nNota1 | Nota2 | Média");
        printf("\n %.2f   %.2f    %.2f", turma[i].nota1, turma[i].nota2, turma[i].media);
        printf("\nSituação: ");
        switch (turma[i].situacao)
        {
        case APROVADO:
            printf("\nAprovado");
            break;
        case REPROVADO:
            printf("\nReprovado");
            break;
        default:
            printf("\nERRO!");
            break;
        }
    }
    int iMaior = encontrarMaiorMedia(turma, quantidadeAlunos);
    printf("\n=== ALUNO COM MAIOR MÉDIA ===");
    printf("\nMatrícula: %d", turma[iMaior].matricula);
    printf("\nNome: %s", turma[iMaior].nome);
    printf("\nMédia: %.2f", turma[iMaior].media);

    free(turma);
    turma = NULL;

    return 0;
}