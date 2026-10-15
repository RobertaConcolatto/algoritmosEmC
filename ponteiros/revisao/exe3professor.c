#include <stdio.h>

#define TAM 5

void analisar(const int *vetor, int tamanho, int *soma, int *menor, int *maior){
    if(vetor == NULL || tamanho <=0 || soma == NULL || menor == NULL || maior == NULL){
        return;
    }

    *soma = 0;
    *menor = *vetor;
    *maior = *vetor;

    const int *p = vetor;

    while(p < vetor + tamanho){
        *soma += *p;

        if(*p < *menor){
            *menor = *p;
        }
        if(*p > *maior){
            *maior = *p;
        }
        p++;
    }
}

void inverter(int *vetor, int tamanho){
    if(vetor == NULL || tamanho <=0){
        return;
    }

    int *inicio = vetor;
    int *fim = vetor + tamanho -1;

    while (inicio < fim){
        int auxiliar = *inicio;
        *inicio = *fim;
        *fim = auxiliar;

        inicio++;
        fim--;
    }
}

void exibir(const int *vetor, int tamanho){
    const int *p = vetor;

    while(p < vetor + tamanho){
        printf("[%d] ", *p);
        p++;
    }
    printf("\n");
}

int main(){
    int vetor[TAM] = {0};
    int tamanho = sizeof vetor / sizeof *vetor; // 20 / 4 = 5
    int soma = 0, menor = 0, maior = 0;
    int *p = vetor;

    while(*p < vetor + tamanho){
        printf("Informe um valor entre -100 e 100: ");
        scanf("%d", p);

        if( *p < -100 || *p > 100 ){
            printf("Valor fora do intevalo.Os valores devem estar entre -100 e 100.\n");
            return 1;
        }
        p++;
    }
    printf("Array original:");
    exibir(vetor, tamanho);

    analisar(vetor, tamanho, &soma, &menor, &maior);
    printf("Soma: %d\n", soma);
    printf("Menor: %d\n", menor);
    printf("Maior: %d\n", maior);

    inverter(vetor, tamanho);

    printf("Array invertido:");
    exibir(vetor, tamanho);

    return 0;
}