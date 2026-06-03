/*Crie um programa que solicite dois nomes e depois escreva-os, mostrando a posição de cada letra. 
*/
#include <stdio.h>
#include <string.h>

int main(){
	char nome1[21], nome2[21];
	int i;
	
	printf("\nInforme um nome: ");
	fgets(nome1, sizeof(nome1), stdin);
	nome1[strcspn(nome1, "\n")]='\0';
	
	printf("\nInforme um nome: ");
	fgets(nome2, sizeof(nome2), stdin);
	nome2[strcspn(nome2, "\n")]='\0';
	
	printf("\n---Primeiro Nome Informado---\n");
	printf("\nLetra\t  Posicao");
	for(i=0; i<strlen(nome1); i++){
		printf("\n%c\t = [%d]",nome1[i], i);
	}
	
	printf("\n\n---Segundo Nome Informado---\n");
	printf("\nLetra\t  Posicao");
	for(i=0; i<strlen(nome2); i++){
		printf("\n%c\t = [%d]",nome2[i], i);
	}
}
