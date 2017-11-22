#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (void) 
{

	char str1[] = "abcd ";
	char str2[] = "abcd ";
	int cmp;

	cmp = strcmp(str1, str2);   // retorna 0

	printf("%d\n", cmp );

	str2[4] = 'e';
	str1[4] = 'a';
	cmp = strcmp(str1, str2);   // retorna -1

	printf("%d\n", cmp );

  	str2[4] = 'f';
	cmp = strcmp(str1, str2);   // retorna 1
	printf("%d\n", cmp );

	return 0;
}