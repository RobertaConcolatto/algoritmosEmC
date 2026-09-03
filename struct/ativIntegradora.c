#include <stdio.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nome[50];
    float media;
} Aluno;

void LimparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void imprimirMenu()
{
    printf("\n\n------ MENU ------");
    printf("\n 1 - Apresentar alunos");
    printf("\n 2 - Calcular média da turma");
    printf("\n 3 - Mostrar aluno com maior média");
    printf("\n 4 - Pesquisar aluno por matrícula");
    printf("\n 5 - Contar alunos aprovados");
    printf("\n 6 - Listas alunos com média >= 7.0");
    printf("\n 0 - Sair");
    printf("\nInforme a opção desejada: ");
}

void mostrarAlunoMaiorMedia(Aluno aluno[], int tamanho)
{
    int maiorIndice = 0;
    for (int i = 1; i < tamanho; i++)
    {
        if (aluno[i].media > aluno[maiorIndice].media)
        {
            maiorIndice = i;
        }
    }
    printf("\n\n== ALUNO COM MAIOR MÉDIA ==");
    printf("\nMatrícula: %d", aluno[maiorIndice].matricula);
    printf("\nNome: %s", aluno[maiorIndice].nome);
    printf("\nMédia: %.2f", aluno[maiorIndice].media);
}

void imprimirAlunos(Aluno aluno[], int tamanho)
{
    printf("\n\n============ TURMA =============");
    for (int i = 0; i < tamanho; i++)
    {
        printf("\n\n----------- Aluno %d -----------", i + 1);
        printf("\nMatrícula: %d", aluno[i].matricula);
        printf("\nNome: %s", aluno[i].nome);
        printf("\nMédia: %.2f", aluno[i].media);
        printf("\n--------------------------------");
    }
}

void pesquisarAlunoPorMatricula(Aluno aluno[], int tamanho)
{
    int matricula, encontrou = 0;
    printf("\n === Pesquisar aluno por matrícula === ");
    printf("\nInforme a matrícula que deseja encontrar: ");
    scanf("%d", &matricula);
    for (int i = 0; i < 5; i++)
    {
        if (matricula == aluno[i].matricula)
        {
            printf("\nALUNO ENCONTRADO!");
            printf("\nMatrícula: %d", aluno[i].matricula);
            printf("\nNome: %s", aluno[i].nome);
            printf("\nMédia: %.2f", aluno[i].media);
            encontrou = 1;
        }
    }
    if (encontrou == 0)
    {
        printf("\nMATRÍCULA NÃO ENCONTRADA!");
    }
}

void calcularMediaTurma(Aluno aluno[], int tamanho)
{
    float mediaTurma = 0.0f;
    for (int i = 0; i < tamanho; i++)
    {
        mediaTurma = mediaTurma + aluno[i].media;
    }
    printf("\n\nMÉDIA DA TURMA: %.2f", mediaTurma / tamanho);
}

void contadorAlunosAprovados(Aluno aluno[], int tamanho)
{
    int contadorAprovados = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (aluno[i].media >= 7.0f)
        {
            contadorAprovados++;
        }
    }
    printf("\nQUANTIDADE APROVADOS: %d aluno / alunos", contadorAprovados);
}

void listarAlunosAprovados(Aluno aluno[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (aluno[i].media >= 7.0f)
        {
            printf("\n\n----------- Aluno %d -----------", i + 1);
            printf("\nMatrícula: %d", aluno[i].matricula);
            printf("\nNome: %s", aluno[i].nome);
            printf("\nMédia: %.2f", aluno[i].media);
            printf("\n--------------------------------");
        }
    }
}

int main()
{
    Aluno aluno[5];

    printf("\n===== CADASTRO DE ALUNOS =====");
    for (int i = 0; i < 5; i++)
    {
        printf("\n--- Aluno %d ---", i + 1);
        printf("\nMatrícula: ");
        scanf("%d", &aluno[i].matricula);
        LimparBuffer();
        while (aluno[i].matricula < 0)
        {
            printf("\nInforme um valor válido! Maior que zero");
            printf("\nMatrícula: ");
            scanf("%d", &aluno[i].matricula);
            LimparBuffer();
        }

        printf("\nNome: ");
        fgets(aluno[i].nome, sizeof(aluno[i].nome), stdin);
        aluno[i].nome[strcspn(aluno[i].nome, "\n")] = '\0';
        while (strlen(aluno[i].nome)==0)
        {
            printf("\nResposta vazia!");
            printf("\nNome: ");
            fgets(aluno[i].nome, sizeof(aluno[i].nome), stdin);
            aluno[i].nome[strcspn(aluno[i].nome, "\n")] = '\0';
        }

        printf("\nMédia: ");
        scanf("%f", &aluno[i].media);
        while (aluno[i].media>10 || aluno[i].media<0)
        {
            printf("\nInforme um valor válido! (0 a 10)");
            printf("\nMédia: ");
            scanf("%f", &aluno[i].media);
        }
        
    }
    int opcao;

    do
    {
        imprimirMenu();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            imprimirAlunos(aluno, 5);
            break;
        case 2:
            calcularMediaTurma(aluno, 5);
            break;
        case 3:
            mostrarAlunoMaiorMedia(aluno, 5);
            break;
        case 4:
            pesquisarAlunoPorMatricula(aluno, 5);
            break;
        case 5:
            contadorAlunosAprovados(aluno, 5);
            break;
        case 6:
            listarAlunosAprovados(aluno, 5);
            break;
        case 0:
            printf("\nVolte sempre =) ");
            break;
        default:
            printf("\nInforme um opção válida!");
            break;
        }
    } while (opcao != 0);
}