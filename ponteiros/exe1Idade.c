#include<stdio.h>

int main(){
    int idade = 13;
    int *ptr = &idade;

    printf("\nValor variável idade: %d", idade);
    printf("\nValor acessado pelo ponteiro: %d", *ptr);
    printf("\nEndereço variável idade: %p",(void *)&idade);
    printf("\nEndereço armazenadono ponteiro ptr: %p",(void *)ptr);
}