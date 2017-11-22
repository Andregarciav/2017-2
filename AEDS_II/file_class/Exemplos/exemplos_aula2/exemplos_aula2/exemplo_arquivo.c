#include <stdio.h>



//exemplo de leitura e escrita com arquivos
int main()
{
	FILE *inFile; // variável handle ou ponteiro para o arquivo
	FILE *outFile;
	char str[60];
	//abre o arquivo para leitura (r) ou gravacao (w)
	inFile = fopen("arquivo.txt", "r"); 
	outFile = fopen("saida.txt", "w");

	/*
	if ((inFile = fopen("arquivo.txt", “r”)) == NULL)
	{ 
    	printf("Nao consegui abrir o arquivo de entrada.\n"); 
    	exit(1); 
	}

	if ((outFile = fopen("saida.txt", “w”)) == NULL)
	{ 
    	printf("Nao consegui abrir o arquivo de saida.\n"); 
    	exit(1); 
	}
	*/
	
	fscanf(inFile, "%60[^\n]", &str);

	fprintf(outFile, "A frase lida foi: %s\n", str);

	printf("A frase lida foi: %s\n", str);

	fclose(inFile);
	fclose(outFile);
}


//exemplo do uso da função getchar
/*
int main() 
{
	FILE *f;
	char ch;

    f = fopen("arquivo.txt","r");

    while ((ch = fgetc(f)) != EOF)
        printf("%c", ch);
    printf("\n");
    fclose(f);

    return 0;
}
*/