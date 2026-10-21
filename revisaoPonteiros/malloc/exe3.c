/*Exercício 3 — Array dinâmico e média
• Leia a quantidade de notas, reserve um array dinâmico e apresente:
• as notas informadas;
• a média;
• a maior nota;
• a menor nota;
• a quantidade de notas acima da média.*/
#include<stdio.h>
#include<stdlib.h>

int main(){
    int quantidadeNotas;
    printf("\nInforme a quantidade de notas: ");
    scanf("%d", &quantidadeNotas);

    if (quantidadeNotas<= 0)
    {
        printf("\nQuantidade inválida!!!");
        return -1;
    }
    
    //alocação de memória
    float *vetorNotas = malloc(quantidadeNotas * sizeof *vetorNotas);
    if (vetorNotas == NULL)
    {
        printf("\nFalha na alocação!");
        return 1;
    }
    
    //leitura
    float somaMedia=0, media;
    for (int i = 0; i < quantidadeNotas; i++)
    {
        printf("\nInforme a nota %d: ", i+1);
        scanf("%f", &vetorNotas[i]);
        somaMedia = somaMedia + vetorNotas[i];
    }   
    printf("\nNOTAS CADASTRADAS!!!");

    //processamento
    int iMaior=0, iMenor=0, contadorAcimaMedia = 0;
    media = somaMedia/quantidadeNotas;
    for (int i = 0; i < quantidadeNotas; i++)
    {
        if (vetorNotas[i]>vetorNotas[iMaior])
        {
            iMaior = i;
        }
        if (vetorNotas[i]<vetorNotas[iMenor])
        {
            iMenor = i;
        }
        
        if (vetorNotas[i]>=media)
        {
            contadorAcimaMedia++;
        }
    } 
    
    //saída
    printf("\n=== NOTAS CADASTRADAS ===");
    for (int i = 0; i < quantidadeNotas; i++)
    {
        printf("\nNota %d: %.2f", i+1, vetorNotas[i]);
    }
    printf("\nMÉDIA: %.2f", media);
    printf("\nMAIOR NOTA: %.2f", vetorNotas[iMaior]);
    printf("\nMENOR NOTA: %.2f", vetorNotas[iMenor]);
    printf("\nQUANTIDADE DE NOTAS ACIMA DA MÉDIA: %d", contadorAcimaMedia);
    
    free(vetorNotas);
    vetorNotas = NULL;

    return 0;
}