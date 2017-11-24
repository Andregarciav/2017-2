#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dicionario.h"
#include "tree.h"


void Ler_entrada(char *Arquivo_entrada, char* Arquivo_saida)
{
	char *buffer;
	char *comando, *verbo, *conteudo;
	char add[] = "# add";
	char search[] = "# search";
	TipoArvore *dicionario = NULL;
	
	buffer = (char*)malloc(MAX*sizeof(char));
	

	dicionario = (TipoArvore*)malloc(sizeof(TipoArvore));
	
	FILE *fp_in = fopen(Arquivo_entrada , "r");
	if (!fp_in)
	{
		Imprime_erros(-2);
	}
	FILE *fp_out = fopen(Arquivo_saida , "w");
	if (!fp_in)
	{
		Imprime_erros(-6);
	}
	
	//cria lista vazia
	Cria_arvore(dicionario);
	if (dicionario == NULL)
		exit(1);

	//Loop para ler o arquivo de entrada
	while (1)
	{
		fgets(buffer, MAX , fp_in);
		
		//sai do while quando terminar de ler o arquivo
		if (feof(fp_in)) 
		{
			break;
		}
		
		//printf("%s\n captura buffer\n",buffer);
		comando = strtok(buffer, "# ");
		printf("%s\n captura comando\n",buffer);
		comando[strlen(comando)]='\0';
		printf("%s\n captura comando\n",buffer);
		//caso comando seja = '# add'
		if (strcmp(comando, add))
		{
			verbo = strtok (NULL," #");
			conteudo = strtok (NULL,"#");
			conteudo = &conteudo[1];
			//conteudo[strlen(conteudo)-1] = '\0';
			if(vazia(dicionario))
			{
				dicionario->Raiz = CriaNo(verbo, conteudo);
			}
			else
			{
				InsereNo(verbo, conteudo, dicionario->Raiz);
			}
			printf("Entrou add");
		}
		
		if (strcmp(comando, search))
		{
			verbo = strtok (NULL," #");
			
			printf("%s , %s entrou search\n",comando , verbo);
			conteudo = ProcuraNo(verbo, dicionario->Raiz);
			if (conteudo == NULL)
			{
				Imprime_erros (-5);
			}
			fprintf(fp_out ,"%s # %s", verbo , conteudo);
		}
	}
	
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
		
		case -3:
		printf("Erro ao alocar arvore do dicionario.\n\n");
		printf("APLICACAO TERMINADA!!!\n\n");
		break;

		case -4:
		printf("Erro, verbete nao encotrado.\n\n");
		break;//tentar função que imprime em arquivo não encontrado 

		case -5:
		printf("Erro ao tentar procurar verbete.\n\n");
		break;

		case -6:
		printf("Erro ao tentar abrir o arquivo de saida.\n\n");
		printf("APLICACAO TERMINADA!!!\n\n");
		break;
	}
	exit(1);
}


