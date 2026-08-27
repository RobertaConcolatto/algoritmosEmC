#include<stdio.h>
enum diasSemana{
        DOMINGO = 1,
        SEGUNDA,
        TERCA,
        QUARTA,
        QUINTA,
        SEXTA,
        SABADO
    };

int main(){
    int num;
    enum diasSemana dia;
    printf("\nInforme um número de 1 a 7: ");
    scanf("%d", &num);

    while (num>7||num<1)
    {
        printf("\nInforme uma opção válida!");
        printf("\nInforme um número de 1 a 7: ");
        scanf("%d", &num);
    }
    dia = (enum diasSemana) num;
    switch (dia)
    {
    case DOMINGO:
        printf("\nDOMINGO");
        break;
    case SEGUNDA:
        printf("\nSEGUNDA");
        break;
    case TERCA:
        printf("\nTERÇA");
        break;
    case QUARTA:
        printf("\nQUARTA");
        break;
    case QUINTA:
        printf("\nQUINTA");
        break;
    case SEXTA:
        printf("\nSEXTA");
        break;
    case SABADO:
        printf("\nSÁBADO");
        break;
    }
    printf("\nDia da semana: %d", dia);

    return 0;
}