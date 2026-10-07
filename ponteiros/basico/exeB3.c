/*3. Crie um array com dez inteiros e imprima os valores utilizando apenas *(vetor + i). 
*/
#include<stdio.h>

void imprimirVetor(int vetor[], int tamanho){
    for (int i = 0; i < 10; i++)
    {
        printf("\nVetor %d: [%d]", i, *(vetor+i));
    }
    
}
int main(){
    int vetor[] = {1,2,3,4,5,6,7,8,9,10};

    imprimirVetor(vetor, 10);
}