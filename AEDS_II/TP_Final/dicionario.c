#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dicionario.h"
#include "tree.h"


void Ler_entrada(char *Arquivo_entrada)
{
	char *buffer;
	char *comando, *verbo, *conteudo;
	char *add = "# add";
	TipoArvore *dicionario;
	
	buffer = (char*)malloc(MAX*sizeof(char));
	FILE *fp = fopen(Arquivo_entrada , "r");
	if (!fp)
	{
		Imprime_erros(-2);
	}
	
	//cria lista vazia
	Cria_arvore(dicionario);

	//Loop para ler o arquivo de entrada
	while (1)
	{
		fgets(&buffer[0] , MAX , fp);
		
		//sai do while quando terminar de ler o arquivo
		if (feof(fp)) 
		{
			break;
		}
		
		comando = strtok(&buffer[0], " # ");
		verbo = strtok (NULL," #");
		conteudo = strtok (NULL,"#");
		conteudo = &conteudo[1];
		conteudo[strlen(conteudo)-1] = '\0';

		if (strcmp(comando, add))
		{
			printf("entrei\n");
			if(vazia(dicionario))
			{
				dicionario->Raiz = CriaNo(verbo, conteudo);
			}
			else
			{
				InsereNo(verbo, conteudo, dicionario);
			}
		}

	}
	printf("antes\n");
	free(buffer);
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
		
		case -3:
		printf("Erro ao alocar arvore do dicionario.\n\n");
		printf("APLICACAO TERMINADA!!!\n\n");
	}
	exit(1);
}


