/*Exercício 1 — Ordenação de dois valores
• Crie uma função que receba dois ponteiros para int e organize os
valores em ordem crescente.
• void ordenar(int*a, int *b);
• Não utilize retorno para devolver os valores.*/
#include<stdio.h>
#include<stdlib.h>

void ordenar(int*a, int *b){
    if(a==NULL || b == NULL){
        return;
    }

    if(*a>*b){
        int auxiliar = *a;
        *a = *b;
        *b = auxiliar;
    }
}

int main(){
    int x, y;
    printf("\n === ORDENAR NÚMEROS ===");
    printf("\nNúmero 1: ");
    scanf("%d", &x);
    printf("\nNúmero 2: ");
    scanf("%d", &y);
    ordenar(&x, &y);
    printf("\nOrdem: %d - %d", x, y);
}