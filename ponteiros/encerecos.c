#include <stdio.h>
int main(void)
{
    int numero = 25;
    float media = 8.5f;
    printf("Valor de numero: %d\n", numero);
    printf("Endereco de numero: %p\n", (void *)&numero);
    printf("Valor de media: %.1f\n", media);
    printf("Endereco de media: %p\n", (void *)&media);
    return 0;
}
