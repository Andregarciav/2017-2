// apresenta simples exemplos de utilização do leitura no terminal
#include <stdio.h>

//exemplo 1: utilização básica do scanf


int main()
{

	int num = 0;
	char letra;
	char ch;
	char s[10];
	char frase[20];
	
	printf("Digite um numero inteiro: ");
	scanf("%d", &num);//inteiro
	printf("%d\n", num);

	//observacao: colocar um espaco em branco antes do %c para não receber o caracter de escape da leitura anterior
	printf("Digite um caracter e um numero inteiro: ");
	scanf(" %c%d", &letra, &num);//caracter e inteiro
	printf("%c e %d\n", letra, num);

	//observacao: colocar um espaco em branco antes do %c para não receber o caracter de escape da leitura anterior
	printf("Digite um caracter: ");
	scanf(" %c", &ch);//caracter
	printf("%c\n",ch);

	printf("Digite uma palavra: ");
	scanf("%s", s); // string
	printf("%s\n", s);

	printf("Digite uma frase: ");
	scanf(" %[^\n]", frase); // string
	printf("%s\n", frase);

	return 0;

}