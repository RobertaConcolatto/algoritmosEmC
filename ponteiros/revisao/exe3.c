/*3. Análise e inversão de um array
Conteúdos: arrays, sizeof, const, aritmética de ponteiros e parâmetros de saída.
Leia cinco inteiros entre -100 e 100 em um array fixo. Implemente uma função que receba o array e seu
tamanho e informe soma, menor e maior por ponteiros de saída. Implemente outra função para inverter o
array usando dois ponteiros. No processamento, na inversão e na exibição, não utilize vetor[i]. Obtenha o
tamanho com sizeof no main e passe-o às funções.*/
#include <stdio.h>
#define TAM 5

void analisar(const int *vetor, int tamanho,
              int *soma, int *menor, int *maior)
{
    if (vetor == NULL || tamanho <= 0 || soma == NULL || menor == NULL || maior == NULL)
    {
        return;
    }

    *soma = 0;
    *menor = *vetor; // recebe o primeiro elemento do vetor
    *maior = *vetor;

    const int *p = vetor; // recebe o endereço do primeiro elemento do vetor

    while (p < vetor + tamanho)
    {
        *soma = *soma + *p;

        if (*p < *menor)
        {
            *menor = *p;
        }

        if (*p > *maior)
        {
            *maior = *p;
        }

        p++;
    }
}

void inverter(int *vetor, int tamanho)
{
    if (vetor == NULL || tamanho <= 0)
    {
        return;
    }

    int *inicio = vetor;
    int *fim = vetor + tamanho - 1;

    while (inicio < fim)
    {
        int auxiliar = *inicio;
        *inicio = *fim;
        *fim = auxiliar;

        inicio++;
        fim--;
    }
}

void exibir(const int *vetor, int tamanho)
{
    const int *p = vetor;
    while (p < vetor + tamanho)
    {
        printf("[%d] ", *p);
        p++;
    }
    printf("\n");
}
int main()
{
    int vetor[TAM] = {0}, tamanho, soma = 0, maior = 0, menor = 0;
    tamanho = sizeof vetor / sizeof *vetor;
    int *p = vetor;

    printf("\n === Informe os elementos do vetor === ");
    while(*p < vetor + tamanho){
        printf("\nInforme um valor entre -100 e 100: ");
        scanf("%d", p);

        if( *p < -100 || *p > 100 ){
            printf("Valor fora do intevalo.Os valores devem estar entre -100 e 100.\n");
            return 1;
        }
        p++;
    }

    printf("\nArray Original: ");
    exibir(vetor, tamanho);

    analisar(vetor, tamanho, &soma, &menor, &maior);
    printf("\nSoma: %d", soma);
    printf("\nMenor: %d", menor);
    printf("\nMaior: %d", maior);

    inverter(vetor, tamanho);

    printf("\nArray invertido: ");
    exibir(vetor, tamanho);

    return 0;
}