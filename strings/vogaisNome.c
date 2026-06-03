/*Escrever um programa que receba um nome e depois conte o número de vogais existentes nele. O também
deverá imprimir o número total de caracteres do nome, quantas vogais e a respectiva porcentagem das
vogais em relação ao total de caracteres. */
#include <stdio.h>
#include <string.h>

int main(){
	char nome[21], letra;
	int quantV=0, tamanho;
	
	printf("Informe um nome (máximo de 20 caracteres): ");
	fgets(nome,sizeof(nome), stdin);
	nome[strcspn(nome, "\n")]='\0';
	
	tamanho = strlen(nome);
	for(int i=0; i<tamanho; i++){
		letra=nome[i];
		switch(letra){
			case 'a':
			case 'A': 
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'u':
			case 'U':
				quantV++;
			break;
		}
	}
	printf("\n---Resultado---\n");
	printf("\nNumero de caracteres: %d", tamanho);
	printf("\nQuantidade de vogais: %d", quantV);
	if (tamanho > 0) {
        printf("\nPorcentagem de vogais em relacao ao total de caracteres: %.2f%%", ((float)quantV/tamanho)*100.0);
    } else {
        printf("\nNenhum caractere digitado.\n");
    }
	
}
