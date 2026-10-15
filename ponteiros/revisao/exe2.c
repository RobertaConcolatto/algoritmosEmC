/*2. Ordenação e resultados por ponteiros
Conteúdos: endereço, desreferência, lvalue, funções por valor e por ponteiro, parâmetros de saída, NULL,
sizeof e %p.
Leia dois inteiros entre -100 e 100. Implemente void tentarAlterar(int valor), que atribui 999 apenas à cópia
recebida; void ordenar(int *a, int *b), que organiza os valores em ordem crescente; e void calcular(int a, int b,
int *soma, int *produto). Proteja os parâmetros ponteiros contra NULL. Mostre o primeiro valor após
tentarAlterar, os valores ordenados, soma e produto. Mostre também &a, o endereço armazenado em um
ponteiro p para a, &p, sizeof a e sizeof p. Explique por quê &a e p coincidem e por que tamanhos e endereços
podem variar.
*/
#include <stdio.h>

void tentarAlterar(int valor)
{
    valor = 999;
    printf("\nDestro da função tentarAlterar: %d", valor);
}

void ordenar(int *a, int *b)
{
    if (a == NULL || b == NULL) // testar se os ponteiros foram inicializados corretamene
    {
        return;
    }

    if (*a > *b)
    {
        int auxiliar = *a;
        *a = *b;
        *b = auxiliar;
    }
}

void calcular(int a, int b, int *soma, int *produto){
    if(soma != NULL){
        *soma = a + b;
    }

    if(produto != NULL){
        *produto = a * b;
    }
}

int main()
{
    int a = 0, b = 0, soma = 0, produto = 0;
    int *p = &a;

    printf("Informe o primeiro valor entre -100 e 100: ");
    scanf("%d", &a);

    printf("Informe o segundo valor entre -100 e 100: ");
    scanf("%d", &b);
    if( a < -100 || a > 100 || b < -100 || b > 100){
        printf("Os valores devem estar entre -100 e 100.\n");
        return 1;
    }
    tentarAlterar(a);
    printf("\nPrimeiro valor após tentarAlterar = %d", a);

    ordenar(p,&b);
    printf("\n Valores ordenados: %d - %d", a, b);

    calcular(a,b,&soma,&produto);
    printf("\n Soma = %d", soma);
    printf("\n Produto = %d", produto);

    printf("\nEndereço de A: %p", (void *)&a);
    printf("\nEndereço armazenado em p: %p", (void *)p );
    printf("\nEndereço de P: %p", (void *)&p);
    printf("\nTamanho de A: %zu bytes", sizeof a);
    printf("\nTamanho de P: %zu bytes", sizeof(p));

    /*
    Pois &a é oq está armazenado em p
    porque uma coisa é tamanho do tipo de dados e o tamanho dos endereços é outra
    */
    return 0;
}