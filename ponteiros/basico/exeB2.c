/*Leia um número real utilizando um ponteiro e apresente seu dobro. */
#include<stdio.h>

void dobrar(float *numero){
    *numero = *numero *2;
}
int main(){
    float numero;
    float *pnumero = &numero;
    printf("\nNúmero: ");
    scanf("%f", pnumero);
    dobrar(pnumero);
    printf("Dobro: %.1f", numero);
}