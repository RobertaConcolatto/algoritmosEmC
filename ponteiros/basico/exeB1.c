/*Declare duas variáveis int e dois ponteiros. Faça cada ponteiro apontar para uma variável e
altere os dois valores por meio deles. */

#include <stdio.h>

int main(){
    int a = 5, b = 10, auxiliar;
    int *pa = &a, *pb = &b;

    printf("\na: %d, b: %d", a,b);
    auxiliar = *pa;
    *pa = *pb;
    *pb = auxiliar;
    printf("\na: %d, b: %d", a,b);
}