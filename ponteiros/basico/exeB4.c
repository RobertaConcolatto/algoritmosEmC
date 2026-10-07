/*Escreva uma função que receba um ponteiro para int e transforme um valor negativo em
positivo.*/
#include<stdio.h>

void inverter(int *num){
    *num = *num * -1;
}
int main(){
    int num = -5;
    int *pnum = &num;

    
    inverter(pnum);
    printf("\nNovo número: %d", num);
}