/*7. Matriz dinâmica e somas por linha
Conteúdos: matriz com int **, malloc, calloc, falha parcial e liberação.
Leia linhas e colunas (1 a 5). Aloque um array de ponteiros com malloc e cada linha com calloc. Aloque também
um array de contadores de soma com calloc. Antes da leitura, mostre a matriz zerada; depois, leia inteiros
entre -100 e 100, linha a linha. Exiba a matriz preenchida e a soma de cada linha. Se a criação de uma linha
falhar, libere somente as linhas já criadas e o array de ponteiros. Ao terminar, libere todas as linhas, o array de
ponteiros e as somas.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linhas, colunas;

    printf("\n===== MATRIZES DINÂMICAS =====");
    printf("\nInforme quantidade de linhas (1 a 5): ");
    scanf("%d", &linhas);
    while (linhas > 5 || linhas < 1)
    {
        printf("\nValor inválido, informe novamente!");
        printf("\nInforme quantidade de linhas (1 a 5): ");
        scanf("%d", &linhas);
    }

    printf("\nInforme quantidade de colunas (1 a 5): ");
    scanf("%d", &colunas);
    while (colunas > 5 || colunas < 1)
    {
        printf("\nValor inválido, informe novamente!");
        printf("\nInforme quantidade de colunas (1 a 5): ");
        scanf("%d", &colunas);
    }

    int **matriz = malloc(linhas * sizeof *matriz);
    if (matriz == NULL)
    {
        return 1;
    }
    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = calloc(
            colunas, sizeof *matriz[i]);
        if (matriz[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(matriz[j]);
            }
            free(matriz);
            matriz = NULL;
            return 1;
        }
    }
    printf("\n=== MATRIZ ===");
    for (int i = 0; i < linhas; i++)
    {
        printf("\n");
        for (int j = 0; j < colunas; j++)
        {
            printf("[%d] ", matriz[i][j]);
        }
    }

    int *contadorSoma = calloc(linhas, sizeof *contadorSoma);
    if (contadorSoma == NULL)
    {
        printf("\nFalha na alocação de memória!");
        for (int i = 0; i < linhas; i++)
        {
            free(matriz[i]);
        }
        free(matriz);
        return 1;
    }

    printf("\n======= LER DADOS DA MATRIZ =======");
    printf("\n(informe números entre -100 e 100)");
    for (int i = 0; i < linhas; i++)
    {
        printf("\n--- Linha %d ---", i);
        for (int j = 0; j < colunas; j++)
        {
            printf("\n[%d][%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
            while (matriz[i][j] > 100 || matriz[i][j] < -100)
            {
                printf("\nValor inválido informe novamente!");
                printf("\n[%d][%d] = ", i, j);
                scanf("%d", &matriz[i][j]);
            }

            contadorSoma[i] = contadorSoma[i] + matriz[i][j];
        }
    }

    printf("\n======= EXIBIR MATRIZ =======");
    for (int i = 0; i < linhas; i++)
    {
        printf("\n--- Linha %d ---", i);
        printf("\n");
        for (int j = 0; j < colunas; j++)
        {
            printf("[%d] ", matriz[i][j]);
        }
        printf(" ---> Soma da Linha = [%d]", contadorSoma[i]);
    }

    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    matriz = NULL;
    free(contadorSoma);
    contadorSoma = NULL;

    return 0;
}