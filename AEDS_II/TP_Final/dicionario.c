#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dicionario.h"

void Ler_entrada(char *Arquivo_entrada)
{
	char *buffer;
	char *comando;
	char *add = "# add";
	dici *dicionario;
	buffer = malloc(MAX*sizeof(char));

	FILE *fp = fopen(Arquivo_entrada , "r");
	if (!fp)
	{
		Imprime_erros(-2);
	}
	
	while (!feof(fp))
	{
		fgets(buffer , MAX , fp);
		comando = strtok(buffer, " # ");
		dicionario->palavra = strtok (NULL," # ");
		dicionario->def = strtok (NULL," # ");
		if (strcmp(comando, add))
		{
			 printf("DEU\n");
			 return;
		}
		printf("%s\n",buffer);

	}
	printf ("%s\n", comando);
	free(buffer);
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
