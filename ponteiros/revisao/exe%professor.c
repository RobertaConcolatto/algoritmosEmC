#include <stdio.h>
#include <string.h>

#define TAM 3

typedef struct {
    int matricula;
    char nome[50];
    float media;
} Aluno;

void limparBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF){
    }
}

void lerAluno(Aluno *aluno){
    if(aluno == NULL){
        return;
    }

    do{
        printf("Matricula: ");
        scanf("%d", &aluno->matricula);

        if(aluno->matricula <=0){
            printf("A matrícula deve ser maior que zero.");
        }
    }while(aluno->matricula <=0);

    limparBuffer();

    printf("Nome: ");
    fgets(aluno->nome, sizeof(aluno->nome), stdin);
    aluno->nome[strcspn(aluno->nome, "\n")] = '\0';

    do{
        printf("Média: ");
        scanf("%f", &aluno->media);

        if(aluno->media < 0.0f || aluno->media > 10.0f){
            printf("A média deve estar entre 0 e 10.\n");
        }
    } while(aluno->media < 0.0f || aluno->media > 10.0f);
}

void exibirAluno(Aluno aluno){
    printf("Matricula: %d\n", aluno.matricula);
    printf("Nome: %s\n", aluno.nome);
    printf("Média: %.1f\n\n", aluno.media);
}

void exibirTurma(const Aluno turma[], int quantidade){
    for(int i = 0; i < quantidade; i++){
        exibirAluno(turma[i]);
    }
}

float calcularMediaTurma(const Aluno turma[], int quantidade){
    float soma = 0.0f;

    if(quantidade <= 0){
        return 0.0f;
    }

    for(int i = 0; i < quantidade; i++){
        soma += turma[i].media;
    }

    return soma / quantidade;
}

int buscarMatricula(const Aluno turma[], int quantidade, int matricula){
     for(int i = 0; i < quantidade; i++){
        if(turma[i].matricula == matricula){
            return i;
        }
    }
    return -1;
}

int contarAprovados(const Aluno turma[], int quantidade){
    int contador = 0;

    for(int i = 0; i < quantidade; i++){
        if(turma[i].media >= 7.0f){
            contador++;
        }
    }
    return contador;
}

void listarAprovados(const Aluno turma[], int quantidade){
    for(int i = 0; i < quantidade; i++){
        if(turma[i].media >= 7.0f){
            exibirAluno(turma[i]);
        }
    }
}

int encontrarMaiorMedia(const Aluno turma[], int quantidade){
    if(quantidade <=0){
        return -1;
    }

    int indiceMaior = 0;

    for(int i = 1; i < quantidade; i++){
        if(turma[i].media > turma[indiceMaior].media){
            indiceMaior = i;
        }
    }
    return indiceMaior;
}

int main(){
    Aluno turma[TAM];
    int posicao, matriculaBusca;

    for(int i = 0; i < TAM; i++){
        do{
            printf("Cadastro do aluno %d\n", i+1);
            lerAluno(&turma[i]);

            posicao = buscarMatricula(turma,i,turma[i].matricula);

            if(posicao != -1){
                printf("Matricula existente. Cadastre novamente.\n");
            }
        } while (posicao != -1);
    }

    printf("\n========= TODOS OS ALUNOS ============\n");
    exibirTurma(turma, TAM);

    float mediaTurma = calcularMediaTurma(turma, TAM);
    printf("Média da turma: %.1f\n", mediaTurma);

    int indiceMaior = encontrarMaiorMedia(turma, TAM);
    printf("========== ALUNO COM MAIOR MEDIA ==========\n");
    exibirAluno(turma[indiceMaior]);

    int aprovados = contarAprovados(turma, TAM);
    printf("========== QUANTIDADE DE APROVADOS ==========\n");
    if(aprovados > 0){
        listarAprovados(turma, TAM);
        printf("Total: %d\n", aprovados);
    }
    else{
        printf("Nenhum aluno aprovado.\n");
    }

    printf("Informe a matricula a ser pesquisada:");
    scanf("%d", &matriculaBusca);

    posicao = buscarMatricula(turma, TAM, matriculaBusca);
    if(posicao == -1){
        printf("Matricula não encontrada.\n");
    }
    else{
        printf("==========ALUNO ENCONTRADO=============\n");
        exibirAluno(turma[posicao]);
    }
    return 0;
}