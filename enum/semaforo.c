#include <stdio.h>

enum CorSemaforo
{
    VERMELHO = 0,
    VERDE,
    AMARELO
};

void imprimirMenu(void)
{
    printf("\n===== Você deseja? =====");
    printf("\n1 - Avançar");
    printf("\n0 - Encerrar");
    printf("\nInforme a opção desejada: ");
}

int main(void)
{
    enum CorSemaforo corAtual = VERMELHO;
    int opcao;
    do
    {
        switch (corAtual)
        {
        case VERMELHO:
            printf("\nSINAL: Vermelho");
            break;
        case VERDE:
            printf("\nSINAL: Verde");
            break;
        case AMARELO:
            printf("\nSINAL: Amarelo");
            break;
        default:
            printf("\nERRO!");
            break;
        }
        imprimirMenu();
        scanf("%d", &opcao);
        while (opcao > 1 || opcao < 0)
        {
            printf("\nInforme uma opção válida!");
            imprimirMenu();
            scanf("%d", &opcao);
        }

        if (opcao == 1)
        {
            if (corAtual == VERMELHO || corAtual == VERDE)
            {
                corAtual++;
            }
            else
            {
                corAtual = VERMELHO; // Volta de AMARELO para VERMELHO
            }
        }
    } while (opcao != 0);
    return 0;
}