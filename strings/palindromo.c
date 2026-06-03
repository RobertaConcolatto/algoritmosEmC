/*Leia uma string e verifique se ela é um palíndromo (ex: "radar", "ana", "ovo").
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
	char palavra [10];
	int i, j;
	bool palindromo = true;
	
	printf("\nInforme uma palavra: ");
	fgets(palavra, sizeof(palavra), stdin);
	palavra[strcspn(palavra,"\n")]='\0';
	
	i = 0; // i = inicio palavra
	j = strlen(palavra) - 1; // j = fim da palavra
	do{
		if(palavra[i]==palavra[j]){
			i++;
			j--;
		}
		else{
			palindromo = false;
			break;
		}
	}while(i!=j && j>i);
	
	if(palindromo){
		printf("\n A palavra %s é um palindromo!", palavra);
	}
	else{
		printf("\n A palavra %s não é um palindromo!", palavra);
	}
	
	return 0;
}
