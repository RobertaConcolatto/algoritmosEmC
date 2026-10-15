/*4. Cópia dinâmica e análise de texto
Conteúdos: fgets, strings, terminador nulo, const, ponteiros, malloc, free e toupper.
Leia uma linha de até 79 caracteres, contendo apenas caracteres ASCII (sem acentos). Remova o
. Implemente tamanhoString, contarVogais e copiarTexto com percurso por ponteiros, sem strlen ou strcpy.
REVISÃO
Algoritmos e Programação II
Prof. Marcos Corino
Vogais são a, e, i, o, u, em qualquer caixa; NULL deve produzir zero nas
duas consultas. Aloque uma cópia dinâmica com tamanho + 1, copie incluindo o terminador e transforme
apenas a cópia em maiúsculas usando toupper. Mostre original, tamanho, vogais e cópia. Libere a cópia.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int tamanhoString(const char *texto)
{
    int tamanho = 0;

    if (texto == NULL)
    {
        return 0;
    }

    while (*texto != '\0')
    {
        tamanho++;
        texto++;
    }
    return tamanho;
}

int contarVogais(const char *texto)
{
    int contador = 0;
    if (texto == NULL)
    {
        return 0;
    }

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
        default:
            break;
        }

        texto++;
    }
    return contador;
}

void copiarTexto(char *destino, const char *origem)
{
    if (destino == NULL || origem == NULL)
    {
        return;
    }

    while (*origem != '\0')
    {
        *destino = *origem;
        destino++;
        origem++;
    }

    *destino = '\0';
}

int main()
{
    char original[80];
    char *copia = NULL;
    int tamanho, vogais;

    printf("\nDigite um texto de até 79 caracteres: ");
    if (fgets(original, sizeof(original), stdin) == NULL)
    {
        printf("\nNão foi possível ler o texto!");
        return 1;
    }

    original[strcspn(original, "\n")] = '\0';

    tamanho = tamanhoString(original);
    vogais = contarVogais(original);

    copia = malloc((tamanho + 1) * sizeof *copia);
    if (copia == NULL)
    {
        printf("Não foi possivel alocar memória para a cópia do texto.\n");
        return 1;
    }

    copiarTexto(copia, original);

    char *p = copia;

    while (*p != '\0')
    {
        *p = (char) toupper((unsigned char) *p);
        p++;
    }
    

    printf("\nOriginal: %s", original);
    printf("\nTamanho: %d", tamanho);
    printf("\nVogais: %d", vogais);
    printf("\nCopia: %s", copia);

    free(copia);
    copia = NULL;
    p = NULL;

    return 0;
}