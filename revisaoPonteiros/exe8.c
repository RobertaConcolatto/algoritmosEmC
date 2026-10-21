/*8. Cadastro dinâmico de alunos
Conteúdos: questão integradora com enum, typedef, structs, strings, funções, ponteiros, busca, filtros e
memória dinâmica.
Implemente um cadastro com menu: 1 cadastrar, 2 listar, 3 pesquisar, 4 atualizar notas, 5 relatório e 0 sair. Use
enum Situacao (REPROVADO, APROVADO) e typedef struct Aluno com matricula, nome[50], nota1, nota2,
media e situacao. A média é aritmética; aprovação exige média >= 7. O cadastro começa vazio, cresce um
registro por vez com realloc seguro e aceita até 50 alunos. Matrículas positivas e únicas; nomes não vazios com
até 49 caracteres; notas de 0 a 10. O limite serve à revisão e não substitui a alocação dinâmica. Use funções
para leitura, cálculo, atualização por Aluno*, exibição por const Aluno*, busca (Aluno* ou NULL), inclusão
(Aluno**), listagem e relatório. O relatório apresenta média da turma, maior média (primeiro em empate),
quantidade e lista dos aprovados. Liste mensagem para cadastro vazio, matrícula ausente ou duplicada.
Atualize somente as notas, recalculando média e situação. Libere o cadastro ao sair, inclusive em erro de
leitura. Não mantenha ponteiros retornados pela busca entre operações que redimensionam o cadastro.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum Situacao
{
    APROVADO,
    REPROVADO
} Situacao;

typedef struct Aluno
{
    int matricula;
    char nome[50];
    float nota1;
    float nota2;
    float media;
    Situacao situacao;
} Aluno;

void exibirMenu()
{
    printf("\n===== MENU =====");
    printf("\n 1 - Cadastrar");
    printf("\n 2 - Listar");
    printf("\n 3 - Pesquisar");
    printf("\n 4 - Atualizar");
    printf("\n 5 - Relatório");
    printf("\n 0 - Sair");
    printf("\n================");
}

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
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

int pesquisarMatricula(const Aluno aluno[], int quantidade, int matricula)
{
    int encontrou = -1;
    for (int i = 0; i < quantidade; i++)
    {
        if (matricula == aluno[i].matricula)
        {
            encontrou = i;
        }
    }
    return encontrou;
}

void criarAluno(Aluno *aluno, Aluno vetorAluno[], int quantidade)
{
    if (aluno == NULL)
    {
        return;
    }
    int encontrar = -1;
    printf("\nMatrícula: ");
    scanf("%d", &aluno->matricula);
    limparBuffer();
    while (encontrar > 0)
    {
        encontrar = pesquisarMatricula(vetorAluno, quantidade, aluno->matricula);
        if (encontrar >= 0)
        {
            printf("\nEssa matrícula já existe no sistema!");
            printf("\nMatrícula: ");
            scanf("%d", &aluno->matricula);
        }
    }

    printf("\nNome: ");
    fgets(aluno->nome, sizeof(aluno->nome), stdin);
    aluno->nome[strcspn(aluno->nome, "\n")] = '\0';

    printf("\n--- CADASTRO DE NOTAS ---");
    printf("\nNota 1: ");
    scanf("%f", &aluno->nota1);
    while (aluno->nota1 > 10 || aluno->nota1 < 0)
    {
        printf("\nInforme um número válido de 0 a 10!");
        printf("\nNota 1: ");
        scanf("%f", &aluno->nota1);
    }

    printf("\nNota 2: ");
    scanf("%f", &aluno->nota2);
    while (aluno->nota2 > 10 || aluno->nota2 < 0)
    {
        printf("\nInforme um número válido de 0 a 10!");
        printf("\nNota 2: ");
        scanf("%f", &aluno->nota2);
    }

    aluno->media = calcularMedia(aluno->nota1, aluno->nota2);
    atualizarSituacao(aluno);
}

void exibirAluno(const Aluno *aluno)
{
    if (aluno == NULL)
    {
        return;
    }

    printf("\nMatrícula: %d", aluno->matricula);
    printf("\nNome: %s", aluno->nome);
    printf("\nNota1 | Nota2 | Média");
    printf("\n %.2f   %.2f    %.2f", aluno->nota1, aluno->nota2, aluno->media);
    printf("\nSituação: ");
    switch (aluno->situacao)
    {
    case APROVADO:
        printf("Aprovado\n\n");
        break;
    case REPROVADO:
        printf("Reprovado\n\n");
        break;
    default:
        printf("ERRO!\n\n");
        break;
    }
}

void atualizarNotas(Aluno *aluno)
{
    printf("\nInforme nova nota 1: ");
    scanf("%f", &aluno->nota1);
    while (aluno->nota1 > 10 || aluno->nota1 < 0)
    {
        printf("\nInforme um número válido de 0 a 10!");
        printf("\nNova nota 1: ");
        scanf("%f", &aluno->nota1);
    }

    printf("\nInforme nova nota 2: ");
    scanf("%f", &aluno->nota2);
    while (aluno->nota2 > 10 || aluno->nota2 < 0)
    {
        printf("\nInforme um número válido de 0 a 10!");
        printf("\nNova nota 2: ");
        scanf("%f", &aluno->nota2);
    }

    aluno->media = calcularMedia(aluno->nota1, aluno->nota2);
    atualizarSituacao(aluno);
}

int main()
{
    printf("\n====== CADASTRO DINÂMICO DE ALUNOS ======");
    int opcao;
    int contadorAlunos = 0;
    Aluno *aluno = NULL;

    do
    {
        exibirMenu();
        printf("\nOpção: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
        {
            if (contadorAlunos >= 50)
            {
                printf("\nNúmero máximo de alunos cadastrados!");
            }
            else
            {
                Aluno *temporario = realloc(
                    aluno,
                    (contadorAlunos + 1) * sizeof *aluno);

                if (temporario == NULL)
                {
                    printf("\nFalha na realocação de memória!");
                    free(aluno);
                    return 1;
                }

                aluno = temporario;

                criarAluno(&aluno[contadorAlunos], aluno, contadorAlunos);
                contadorAlunos++;
            }
        }
        break;
        case 2:
        {
            if (contadorAlunos == 0)
            {
                printf("\nNão existem alunos cadastrados!!!!");
            }
            else
            {
                printf("\n==== LISTAR ====");
                for (int i = 0; i < contadorAlunos; i++)
                {
                    printf("\n_____ Aluno %d _____", i + 1);
                    exibirAluno(&aluno[i]);
                }
            }
        }
        break;
        case 3:
        {
            if (contadorAlunos == 0)
            {
                printf("\nNão existem alunos cadastrados!!!!");
            }
            else
            {
                int matricula, posicao;
                printf("\n==== PESQUISAR ====");
                printf("\nInforme o número de matrícula que deseja pesquisar: ");
                scanf("%d", &matricula);
                posicao = pesquisarMatricula(aluno, contadorAlunos, matricula);
                if (posicao < 0)
                {
                    printf("\nMatrícula não encontrada!!!");
                }
                else
                {
                    printf("\n____Matrícula encontrada____");
                    exibirAluno(&aluno[posicao]);
                }
            }
        }
        break;
        case 4:
        {
            if (contadorAlunos == 0)
            {
                printf("\nNão existem alunos cadastrados!!!!");
            }
            else
            {
                int matricula, posicao;
                printf("\n==== ATUALIZAR NOTAS ====");
                printf("\nInforme o número de matrícula do aluno que deseja alterar notas: ");
                scanf("%d", &matricula);
                posicao = pesquisarMatricula(aluno, contadorAlunos, matricula);
                if (posicao < 0)
                {
                    printf("\nMatrícula não encontrada!!!");
                }
                else
                {
                    printf("\n____Matrícula encontrada____");
                    exibirAluno(&aluno[posicao]);
                    atualizarNotas(&aluno[posicao]);
                    exibirAluno(&aluno[posicao]);
                }
            }
        }
        break;
        case 5:
        {
            if (contadorAlunos == 0)
            {
                printf("\nNão existem alunos cadastrados!!!!");
            }
            else
            {
                printf("\n==== RELATÓRIO ====");
            }
        }
        break;
        case 0:

            break;
        default:
            break;
        }
    } while (opcao != 0);

    return 0;
}