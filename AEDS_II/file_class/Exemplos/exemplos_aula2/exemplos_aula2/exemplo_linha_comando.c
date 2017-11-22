#include <stdio.h>

int main(int argc, char *argv[]) 
{ 
	int i, vezes;
	vezes = atoi(argv[2]);
	for (i = 0; i < vezes; i++)
		printf("%s\n", argv[1]);
	return 0;
}
