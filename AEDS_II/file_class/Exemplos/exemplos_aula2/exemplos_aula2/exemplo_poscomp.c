#include <stdio.h>
//#include <string.h> 


//exemplo poscomp 2009, pula a primeira palavra e imprime o restante
int main (void)
{    
	char texto[]= "foi muito facil\n";    
	int i;     
	for (i = 0; i < strlen(texto); i++)
	{         
		if (texto[i] == ' ') 
			break;    
	}    
	i++;    
	for ( ; i < strlen(texto); i++)         
		printf("%c", texto[i]);    
	return 0;
}