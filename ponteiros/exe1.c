/*int dividir(int dividendo, int divisor, int *quociente, int *resto);
• A função deverá:
• retornar 0 se o divisor for zero;
• retornar 1 se a divisão puder ser realizada;
• informar o quociente e o resto por parâmetros ponteiros. */
#include<stdio.h>

int dividir(int dividendo, int divisor, int *quociente, int *resto){
    if (divisor==0)
    {
        return 0;
    }
    else{
        *quociente = dividendo / divisor;
        *resto = dividendo % divisor;
        return 1;
    }   
}

int main(){
    //a / b = c | a % b = r
    int a, b, c, r, retorno;

    printf("\n --- CALCULAR ---");
    printf("\nInforme um dividendo: ");
    scanf("%d", &a);
    printf("\nInforme um divisor: ");
    scanf("%d", &b);

    retorno= dividir(a,b, &c, &r);

    if (retorno ==0)
    {
        printf("\nNão é possível realizar divisão por zero!!!");
    }
    else{
        printf("\nQuociente: %d", c);
        printf("\nResto: %d", r);
    }
    
}