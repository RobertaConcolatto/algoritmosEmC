/* Crie um enum chamado Operacao com as opções: • SOMAR = 1 • SUBTRAIR • MULTIPLICAR • DIVIDIR O programa deverá: 1. ler dois números;  2. solicitar a operação;  3. converter a opção para enum Operacao;  4. utilizar switch para realizar o cálculo;  5. impedir divisão por zero. */
#include <stdio.h>

enum Operacao
{
    SOMAR = 1,
    SUBTRAIR,
    MULTIPLICAR,
    DIVIDIR
};

void imprimirMenu()
{
    printf("\n=========== MENU ===========");
    printf("\n 1 - SOMAR           a + b");
    printf("\n 2 - SUBTRAIR        a - b");
    printf("\n 3 - MULTIPLICAR     a * b");
    printf("\n 4 - DIVIDIR         a / b");
    printf("\n============================");
}

int main()
{
    int opcaoOperacao;
    float a, b, resultado;
    enum Operacao operacao;

    printf("\nInforme um número A: ");
    scanf("%f", &a);
    printf("\nInforme um número B: ");
    scanf("%f", &b);

    imprimirMenu();
    printf("\nInforme a opção desejada: ");
    scanf("%d", &opcaoOperacao);
    while (opcaoOperacao < SOMAR || opcaoOperacao > DIVIDIR)
    {
        printf("\nInforme uma opção válida!");
        printf("\nInforme a opção desejada: ");
        scanf("%d", &opcaoOperacao);
    }

    operacao = (enum Operacao)opcaoOperacao;

    switch (operacao)
    {
    case SOMAR:
    {
        resultado = a + b;
    }
    break;
    case SUBTRAIR:
    {
        resultado = a - b;
    }
    break;
    case DIVIDIR:
    {
        if (b == 0)
        {
            printf("\nNão é possível realizar divisão por zero!");
            do
            {
                printf("\nInforme um novo valor para B (diferente de zero): ");
                scanf("%f", &b);
            } while (b==0);
            resultado = a / b;
        }
    }
    break;
    case MULTIPLICAR:
        resultado = a * b;
        break;
    default:
        printf("\nOpção inválida!");
        break;
    }

    printf("\nRESULTADO: %.2f", resultado);
}