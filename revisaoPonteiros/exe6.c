/*6. Vetor com crescimento controlado
Conteúdos: ponteiro duplo, níveis de indireção, malloc, realloc seguro e free.
Leia n (1 a 20). Implemente int criarVetor(int **v, int n), que recebe um ponteiro inicialmente NULL e reserva
um array de int com malloc. Leia n inteiros entre -100 e 100. Leia a quantidade adicional k (1 a 20) e amplie o
bloco para n+k elementos com realloc, usando ponteiro temporário. Preencha a nova parte com os k valores
lidos e mostre todos os valores e a média. Em falha de realloc, libere o bloco original e encerre. Não utilize
aliases do bloco após realloc.*/

#include <stdio.h>
#include <stdlib.h>

int criarVetor(int **v, int n)
{
    *v = malloc(n * sizeof **v);
    if (*v == NULL)
    {
        printf("Não foi possível reservar memória.\n");
        return -1;
    }
}

int main()
{
    int n;
    int *vetor;
    printf("\nInforme n (1 a 20):");
    scanf("%d", &n);
    while (n > 20 || n < 1)
    {
        printf("\nInforme um número válido de 1 a 20!!!");
        printf("\nInforme n (1 a 20):");
        scanf("%d", &n);
    }
    criarVetor(&vetor, n);
    printf("\n--- LER %d VALORES INTEIROS ---", n);
    for (int i = 0; i < n; i++)
    {
        printf("\nInforme valor (entre -100 e 100): ");
        scanf("%d", &vetor[i]);
        while (vetor[i] > 100 || vetor[i] < -100)
        {
            printf("\nINFORME UM VALOR VÁLIDO (-100 A 100)!");
            printf("\nInforme valor: ");
            scanf("%d", &vetor[i]);
        }
    }
    int k;
    printf("\nInforme a quantidade adicional k(1 a 20): ");
    scanf("%d", &k);
    while (k > 20 || k < 1)
    {
        printf("\nInforme um número válido de 1 a 20!!!");
        printf("\nInforme k (1 a 20):");
        scanf("%d", &k);
    }
    int *temporario = realloc(vetor, (n + k) * sizeof *vetor);
    if (temporario == NULL)
    {
        printf("Não foi possível redimensionar.\n");
        free(vetor);
        vetor = NULL;
        return -1;
    }
    else
    {
        vetor = temporario;
    }
    printf("\n--- LER %d VALORES INTEIROS ---", k);
    for (int i = n; i < (n + k); i++)
    {
        printf("\nInforme valor (entre -100 e 100): ");
        scanf("%d", &vetor[i]);
        while (vetor[i] > 100 || vetor[i] < -100)
        {
            printf("\nINFORME UM VALOR VÁLIDO (-100 A 100)!");
            printf("\nInforme valor: ");
            scanf("%d", &vetor[i]);
        }
    }
    float somaMedia = 0, media;
    for (int i = 0; i < (n + k); i++)
    {
        printf("\nVetor[%d] = %d", i, vetor[i]);
        somaMedia = somaMedia + vetor[i];
    }
    media = (float)somaMedia / (n + k);
    printf("\nMédia: %.1f", media);

    free(vetor);
    vetor = NULL;
    temporario = NULL;

    return 0;
}