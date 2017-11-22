#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (void) 
{
	char s[10];
	int tamanho;	

	strcpy(s, "Bom dia!");
	tamanho = strlen(s); 	// 9

	printf("Tamanho strlen: %d\n", tamanho);

	tamanho = sizeof(s); 	// 10 (Não usar!) 

	printf("Tamanho sizeof: %d\n", tamanho);

	return 0;
}