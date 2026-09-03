#include <stdio.h>
#include <string.h>

struct Aluno
{
    char nome[30];
    float media;
};

void LimparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{
    struct Aluno aluno[5];
    float maiorMedia, somaMedia=0.0;
    int indiceMaior;

    for (int i = 0; i < 5; i++)
    {
        printf("\n==CADASTRO DE ALUNO %d==", i + 1);
        printf("\nInforme o nome: ");
        fgets(aluno[i].nome, sizeof(aluno[i].nome), stdin);
        aluno[i].nome[strcspn(aluno[i].nome, "\n")] = '\0';

        printf("\nInforme a media: ");
        scanf("%f", &aluno[i].media);
        LimparBuffer();

        somaMedia = somaMedia +aluno[i].media;
        if (i == 0)
        {
            maiorMedia = aluno[i].media;
            indiceMaior = i;
        }
        if (aluno[i].media > maiorMedia)
        {
            maiorMedia = aluno[i].media;
            indiceMaior = i;
        }
    }

    printf("\n-------- TURMA --------");
    printf("\nMédia da Turma: %.2f\n", somaMedia/5);

    for (int i = 0; i < 5; i++)
    {
        printf("\nNome: %s\t\t", aluno[i].nome);
        printf("Média: %.2f", aluno[i].media);
        if (aluno[i].media == maiorMedia)
        {
            printf(" | MAIOR MÉDIA!");
        }
    }
    printf("\n\n-- Aluno Com Maior Média --");
    printf("\nNome %s", aluno[indiceMaior].nome);
    printf("\nMédia: %.2f", aluno[indiceMaior].media);

    return 0;
}