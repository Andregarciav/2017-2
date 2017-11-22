#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dicionario.h"

void Ler_entrada(char *Arquivo_entrada)
{
	char buffer[MAX];
	char *comando;
	char *add = "# add";
	dici *dicionario;
	dicionario = (dici*)malloc(sizeof(dici));

	FILE *fp = fopen(Arquivo_entrada , "r");
	if (!fp)
	{
		Imprime_erros(-2);
	}
	
	while (!feof(fp))
	{
		fgets(&buffer[0] , MAX , fp);
		if (feof(fp)) break;
		printf("%s\n",buffer);
		comando = strtok(&buffer[0], " # ");
		dicionario->palavra = strtok (NULL," #");
		dicionario->def = strtok (NULL,"#");
		printf ("%s\n", comando);
		// if (strcmp(comando, add))
		// {
		// 	dicionario->def = &dicionario->def[1];
		// 	printf("%s (Verbete)\n\n%s (Significado)\n\n", dicionario->palavra, dicionario->def);
		// 	return;
		// }

	}
	printf("antes\n");

	printf("APOS\n");
}

void Imprime_erros(int error)
{
	switch (error)
	{
		case -1:
		printf("Numero de argumentos invalidos!\n\n");
		printf("Favor verificar!!!\n\n");
		printf("./dicionario <entrada> <saida> <arquivo de dicionario>\n\n");
		printf("APLICACAO TERMINADA!!!\n\n");
		break;
		case -2:
		printf("Erro ao tentar abrir o arquivo de entrada.\n\n");
		printf("APLICACAO TERMINADA!!!\n\n");
		break;
	}
	exit(1);
}
