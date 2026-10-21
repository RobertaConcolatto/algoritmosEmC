/*Exercício 2 — Contagem de vogais com ponteiro
• Crie uma função que receba uma string e retorne a quantidade de
vogais utilizando somente aritmética de ponteiros.
• nt contarVogais(const char *texto);
*/
#include<stdio.h>
#include<string.h>

int contarVogais(const char *texto){
    if (texto == NULL)
    {
        return -1;
    }
    

    int contador = 0;
    while (*texto != '\0')
    {
        switch (*texto)
        {
        case 'A':
        case 'a':    
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            contador++;
            break;
        default:
            break;
        }
        texto++;
    }

    return contador;
}

int main(){
    char texto[50];
    printf("\n=== CONTAR VOGAIS ===");
    printf("\nInforme o texto: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto,"\n")]='\0';

    int quantidadeVogais = contarVogais(texto);
    printf("\nNúmero de vogais no texto: %d", quantidadeVogais);
    return 0;
}