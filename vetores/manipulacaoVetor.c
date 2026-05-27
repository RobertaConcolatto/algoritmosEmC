/* Faça um programa que leia um vetor de 5 posições para números reais e, depois, com
base em um código inteiro lido implemente um menu. Se o código for zero, finalize o
programa; se for 1, mostre o vetor na ordem direta; se for 2, mostre o vetor na ordem
inversa. Se for 3, mostre o maior e o menor elemento e as respectivas posições. Se for 4
mostre a média dos valores. Caso, o código for diferente dos anteriormente citados,
escreva uma mensagem informando que o código é inválido e solicite nova tentativa. Ao
termino de cada operação deve solicitar se o usuário deseja realizar nova operação.*/

#include <stdio.h>

int main() {
    float numero[5], soma = 0, maior, menor, media;
    int opcao, posMaior = 0, posMenor = 0;

    // Leitura do vetor
    for (int i = 0; i < 5; i++) {
        printf("\nInforme o %d numero: ", i + 1);
        scanf("%f", &numero[i]);
    }

    do {
        printf("\n=================== MENU ======================");
        printf("\n|0 - Sair                                     |  ");
        printf("\n|1 - Visualizar vetor                         |");
        printf("\n|2 - Visualizar vetor (ordem inversa)         |");
        printf("\n|3 - Visualizar maior e menor elemento        |");
        printf("\n|4 - Mostrar media                            |");
        printf("\n===============================================");
		printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 0:
                printf("\nPrograma finalizado.\n");
                break;

            case 1:
                printf("\nVetor na ordem direta:\n");

                for (int i = 0; i < 5; i++) {
                    printf("%.2f ", numero[i]);
                }

                printf("\n");
                break;

            case 2:
                printf("\nVetor na ordem inversa:\n");

                for (int i = 4; i >= 0; i--) {
                    printf("%.2f ", numero[i]);
                }

                printf("\n");
                break;

            case 3:
                maior = numero[0];
                menor = numero[0];

                for (int i = 1; i < 5; i++) {

                    if (numero[i] > maior) {
                        maior = numero[i];
                        posMaior = i;
                    }

                    if (numero[i] < menor) {
                        menor = numero[i];
                        posMenor = i;
                    }
                }

                printf("\nMaior elemento: %.2f", maior);
                printf("\nPosicao do maior: %d", posMaior);

                printf("\nMenor elemento: %.2f", menor);
                printf("\nPosicao do menor: %d\n", posMenor);

                break;

            case 4:
                soma = 0;

                for (int i = 0; i < 5; i++) {
                    soma += numero[i];
                }

                media = soma / 5;

                printf("\nMedia dos valores: %.2f\n", media);

                break;

            default:
                printf("\nCodigo invalido! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
```

