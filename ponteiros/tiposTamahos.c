#include <stdio.h>
int main(void)
{
    int *pInt = NULL;
    double *pDouble = NULL;
    printf("Tamanho de int: %zu bytes\n", sizeof(int));
    printf("Tamanho de double: %zu bytes\n", sizeof(double));
    printf("Tamanho de pInt: %zu bytes\n", sizeof(pInt));
    printf("Tamanho de pDouble: %zu bytes\n", sizeof(pDouble));

    return 0;
}