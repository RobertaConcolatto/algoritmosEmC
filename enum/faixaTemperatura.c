#include <stdio.h>
enum FaixaTemperatura {
    MUITO_FRIO,
    FRIO,
    AGRADAVEL,
    QUENTE,
    MUITO_QUENTE
};

int main(void){
    enum FaixaTemperatura faixa;
    float temperatura;
    
    printf("Informe uma temperatura: ");
    scanf("%f", &temperatura);
    if(temperatura<10.0){
        faixa = MUITO_FRIO;
    }
    else if (temperatura>=10 && temperatura<18)
    {
        faixa = FRIO;
    }
    else if (temperatura>=18 && temperatura<=25)
    {
        faixa = AGRADAVEL;
    }
    else if (temperatura>25 && temperatura<=32)
    {
        faixa = QUENTE;
    }
    else{
        faixa = MUITO_QUENTE;
    }
    
    printf("Temperatura: ");
    switch (faixa)
    {
    case MUITO_FRIO:
        printf("Muito frio");
        break;
    case FRIO: 
        printf("Frio");
        break;
    case AGRADAVEL:
        printf("Agradável");
        break;
    case QUENTE:
        printf("Quente");
        break;
    case MUITO_QUENTE:
        printf("Muito quente");
        break;
    default:
        printf("\nErro!");
        break;
    }
    return 0;
}