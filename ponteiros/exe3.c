/*Exercício 3 — Contagem de vogais
int contarVogais(const char *texto);
• A função deverá:
• verificar se o ponteiro é NULL;
• percorrer a string utilizando o ponteiro;
• retornar a quantidade de vogais. */

#include <stdio.h>
#include <string.h>
int contarVogais(const char *texto)
{
    int contarVogais = 0;
    if (texto == NULL)
    {
        return -1;
    }
    else
    {
        char vogais[] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        while (*texto != '\0')
        {
            for (int i = 0; i < 12; i++)
            {
                if (*texto == vogais[i])
                {
                    contarVogais++;
                }
            }
            texto++;
        }
        return contarVogais;
    }
}
int main()
{
    char texto[30];
    char *ptexto = NULL;
    printf("\nInforme um texto: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0';
    ptexto = texto;
    printf("\nA qauntidade de vogais nesse texto é de: %d", contarVogais(ptexto));
}