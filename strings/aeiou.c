/*Desenvolva um programa que receba do teclado uma mensagem e imprime quantas letras A, E, I, O, U tem
esta mensagem. Considerar minúscula e maiúscula. */

#include <stdio.h>
#include <string.h>

int main(){
	char mensagem[21];
	int quantA=0, quantE=0, quantI=0, quantO=0, quantU=0, tamanho;
	
	printf("Informe um mensagem (máximo de 20 caracteres): ");
	fgets(mensagem,sizeof(mensagem), stdin);
	mensagem[strcspn(mensagem, "\n")]='\0';
	
	tamanho = strlen(mensagem);
	for(int i=0; i<tamanho; i++){
		if( (mensagem[i]=='a') || (mensagem[i]=='A') ){
			quantA++;
		}
		else if( (mensagem[i]=='e') || (mensagem[i]=='E') ){
			quantE++;
		}
		else if( (mensagem[i]=='i') || (mensagem[i]=='I') ){
			quantI++;
		}
		else if( (mensagem[i]=='o') || (mensagem[i]=='O') ){
			quantO++;
		}
		else if( (mensagem[i]=='u') || (mensagem[i]=='U') ){
			quantU++;
		}
		else{
		}
	}
	printf("\n---Resultado---");
	if(quantA>0){
		printf("\nA mensagem tem %d letra/letras A", quantA);
	}
	if(quantE>0){
		printf("\nA mensagem tem %d letra/letras E", quantE);
	}
	if(quantI>0){
		printf("\nA mensagem tem %d letra/letras I", quantI);
	}
	if(quantO>0){
		printf("\nA mensagem tem %d letra/letras O", quantO);
	}
	if(quantU>0){
		printf("\nA mensagem tem %d letra/letras U", quantU);
	}
	if((quantA==0)&&(quantE==0)&&(quantI==0)&&(quantO==0)&&(quantU==0)){
		printf("\nNessa mensagem não tem letras A, E, I, O e U!");
	}
}
