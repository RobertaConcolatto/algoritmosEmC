/*Leia duas strings. Se as strings forem iguais escreva “strings iguais”. Caso contrário, concatene as duas strings
e imprima a string resultante em maiúsculo. sem a função strupr()*/

#include <stdio.h>
#include <string.h>
int main() {
	char texto1[20], texto2[20], concatenacao[40];
	char alfabeto[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char alfabeto_maiusculo[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'};
	
	printf("\nInforme a primeira string: ");
	fgets(texto1, sizeof(texto1), stdin);
	texto1[strcspn(texto1, "\n")]='\0';

	printf("\nInforme a segunda string: ");
	fgets(texto2, sizeof(texto2), stdin);
	texto2[strcspn(texto2, "\n")]='\0';

	if(strcmp(texto1,texto2)==0) {
		printf("\nStrings iguais!");
	} else {
		strcpy(concatenacao, texto1);

		strcat(concatenacao, texto2);

		for(int i=0; i<strlen(concatenacao); i++) {
			
			for(int j=0; j<26; j++){
				if(concatenacao[i]==alfabeto[j]){
					concatenacao[i]=alfabeto_maiusculo[j];
				}
			}
		}
		printf("\n %s", concatenacao);
	}

	return 0;
}
