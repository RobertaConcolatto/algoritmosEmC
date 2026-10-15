#include <stdio.h>
#include <string.h>

#define TAM 3

typedef struct Aluno
{
    int matricula;
    char nome[50];
    float media;
} Aluno;

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void lerAluno(Aluno *aluno)
{
    if (aluno == NULL)
    {
        return;
    }
    do
    {
        printf("\nMatrícula: ");
        scanf("%d", &aluno->matricula);

        if (aluno->matricula <= 0)
        {
            printf("\nA matrícula deve ser maior que zero!!!");
        }
    } while (aluno->matricula <= 0);

    limparBuffer();

    printf("\nNome: ");
    fgets(aluno->nome, sizeof(aluno->nome), stdin);
    aluno->nome[strcspn(aluno->nome, "\n")] = '\0';

    printf("\nMédia: ");
    scanf("%f", &aluno->media);
    while (aluno->media > 10 || aluno->media < 0)
    {
        printf("\nInforme um npumero válido!!! (de 0 a 10)");
        printf("\nMédia: ");
        scanf("%f", &aluno->media);
    }
}

void exibirAluno(Aluno aluno)
{
    printf("\n\nMatrícula: %d", aluno.matricula);
    printf("\nNome: %s", aluno.nome);
    printf("\nMédia: %.2f\n", aluno.media);
}

void exibirTurma(const Aluno turma[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        exibirAluno(turma[i]);
    }
}

float calcularMediaTurma(const Aluno turma[], int tamanho)
{
    float somaMedia = 0;

    if (tamanho <= 0)
    {
        return 0;
    }

    for (int i = 0; i < tamanho; i++)
    {
        somaMedia = somaMedia + turma[i].media;
    }

    return somaMedia / tamanho;
}

int pesquisarMatrícula(const Aluno turma[], int tamanho, int matricula)
{
    int encontrou = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (matricula == turma[i].matricula)
        {
            return i;
            encontrou = 1;
        }
    }
    if (encontrou == 0)
    {
        return -1;
    }
}

int contarAprovados(const Aluno turma[], int tamanho)
{
    int contadorAprovados = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (turma[i].media >= 7)
        {
            contadorAprovados++;
        }
    }
    return contadorAprovados;
}

void listarAprovados(const Aluno turma[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (turma[i].media >= 7)
        {
            exibirAluno(turma[i]);
        }
    }
}

int encontrarMaiorMedia(const Aluno turma[], int tamanho)
{
    int indiceMaior = 0;
    for (int i = 1; i < tamanho; i++)
    {
        if (turma[i].media > turma[indiceMaior].media)
        {
            indiceMaior = i;
        }
    }
    return indiceMaior;
}

int main()
{
    Aluno turma[TAM];
    int posicao, posicaoMaiorMedia, matriculaBusca, aprovados;
    float mediaTurma;

    printf("\n === SISTEMA ESCOLAR ===");
    for (int i = 0; i < TAM; i++)
    {
        do
        {
            printf("\n --- Cadastro Aluno %d ---", i + 1);
            lerAluno(&turma[i]);

            posicao = pesquisarMatrícula(turma, i, turma[i].matricula);

            if (posicao != -1)
            {
                printf("Matricula existente. Cadastre novamente.\n");
            }
        } while (posicao != -1);
    }

    printf("\n ============= TODOS OS ALUNOS =============");
    exibirTurma(turma, TAM);

    mediaTurma = calcularMediaTurma(turma, TAM);
    printf("\nMédia da turma: %.2f", mediaTurma);

    posicaoMaiorMedia = encontrarMaiorMedia(turma, TAM);
    printf("\n========== ALUNO COM MAIOR MEDIA ==========\n");
    exibirAluno(turma[posicaoMaiorMedia]);

    aprovados = contarAprovados(turma, TAM);
    printf("\n========== QUANTIDADE DE APROVADOS ==========\n");
    if(aprovados > 0){
        listarAprovados(turma, TAM);
        printf("\nTotal: %d\n", aprovados);
    }
    else{
        printf("\nNenhum aluno aprovado.\n");
    }

    printf("Informe a matricula a ser pesquisada:");
    scanf("%d", &matriculaBusca);

    posicao = pesquisarMatrícula(turma, TAM, matriculaBusca);

    if (posicao == - 1)
    {
        printf("\nMatrícula não encontrada!");
    }
    else{
        printf("==========ALUNO ENCONTRADO=============\n");
        exibirAluno(turma[posicao]);
    }
    
    return 0;
}
