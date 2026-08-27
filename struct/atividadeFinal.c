#include <stdio.h>
#include <string.h>

enum SituacaoAluno
{
    MATRICULADO,
    TRANCADO,
    FORMADO
};

struct Aluno
{
    int matricula;
    char nome[50];
    float media;
    enum SituacaoAluno situacao;
};

void LimparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{
    struct Aluno aluno;
    printf("\nMatrícula: ");
    scanf("%d", &aluno.matricula);
    LimparBuffer();
    while (aluno.matricula < 0)
    {
        printf("\nInforme uma  resposta válida! (maior que zero)");
        printf("\nMatrícula: ");
        scanf("%d", &aluno.matricula);
        LimparBuffer();
    }

    printf("\nNome: ");
    fgets(aluno.nome, sizeof(aluno.nome), stdin);
    aluno.nome[strcspn(aluno.nome, "\n")] = '\0';
    while (strlen(aluno.nome) == 0)
    {
        printf("\nRESPOSTA VAZIA!");
        printf("\nNome: ");
        fgets(aluno.nome, sizeof(aluno.nome), stdin);
        aluno.nome[strcspn(aluno.nome, "\n")] = '\0';
    }

    printf("\nMédia: ");
    scanf("%f", &aluno.media);
    while (aluno.media > 10.0 || aluno.media < 0.0)
    {
        printf("\nInforme uma  resposta válida! (0 a 10)");
        printf("\nMédia: ");
        scanf("%f", &aluno.media);
    }

    int opcao;
    printf("\n-- SITUAÇÃO DO ALUNO --");
    printf("\n| 0 - Matriculado     |");
    printf("\n| 1 - Trancado        |");
    printf("\n| 2 - Formado         |");
    printf("\n-----------------------");
    printf("\nInforme a situação: ");
    scanf("%d", &opcao);
    while (opcao > 2 || opcao < 0)
    {
        printf("\nOpção inválida!");
        printf("\nInforme a situação: ");
        scanf("%d", &opcao);
    }
    aluno.situacao = (enum SituacaoAluno)opcao;

    printf("\n\n==== Cadastro Aluno ====");
    printf("\nMatrícula: %d", aluno.matricula);
    printf("\nNome: %s", aluno.nome);
    printf("\nMédia: %.2f", aluno.media);
    printf("\nSituação: ");
    switch (aluno.situacao)
    {
    case MATRICULADO:
        printf("Matriculado");
        break;
    case TRANCADO:
        printf("Trancado");
        break;
    case FORMADO:
        printf("Formado");
        break;
    default:
        break;
    }
    printf("\n========================");
    return 0;
}