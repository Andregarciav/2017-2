#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dicionario.h"
#include "tree.h"


void Ler_entrada(char *Arquivo_entrada, char* Arquivo_saida, char* Arquivo_dicionario)
{
	//inicialização de variáveis
	char *buffer;
	char *comando, *verbo, *conteudo;
	char add[] = "add";
	char search[] = "search";
	char sort[] = "sort";
	
	//Inicialização da struct arvore - Foi criado uma TAD só para ela
	TipoArvore *dicionario = NULL;
	
	//Alocando o buffer a ser utilizado 
	buffer = (char*)malloc(MAX*sizeof(char));
	
	//aloca o TipoArvore 
	dicionario = (TipoArvore*)malloc(sizeof(TipoArvore));
	
	//Abre o arquivo de entrada para leitura e testa
	FILE *fp_in = fopen(Arquivo_entrada , "r");
	if (!fp_in)
	{
		Imprime_erros(-2);
	}
	
	//Abre o arquivo de saida e testa
	FILE *fp_out = fopen(Arquivo_saida , "w");
	if (!fp_in)
	{
		Imprime_erros(-6);
	}

	//Abre o arquivo de dicionario para escrita
	FILE *fp_dici = fopen(Arquivo_dicionario , "w");
	if (!fp_dici)
	{
		Imprime_erros(-7);
	}

	//cria arvore vazia
	Cria_arvore(dicionario);
	
	//Loop para ler o arquivo de entrada
	while (1)
	{
		//armazena no buffer linha a linha
		fgets(buffer, MAX , fp_in);
		
		//sai do while quando terminar de ler o arquivo
		if (feof(fp_in)) 
		{
			Imprime_erros(0);
			break;
		}
		
		//captura do buffer um dos 3 comandos
		/*
		 *	add - Insere verbete no dicionario com respetivo significado.
		 *
		 *	search - Procura verbete no dicionárioprintf("Arquivo de entrada lido!!\n");
		 *			 Nesse ponto foi feito a escolha de finalizar a aplicação
		 *			 caso não encontre verbete.
		 *
		 *	sort - Imprime o dicionário ordenado.
		 */
		comando = strtok(buffer, " # "); //retorna a string até a chave inserida 
		
		//se comando = 'add'
		if (strcmp(comando, add) == 0)
		{
			//captura verbete a ser adicionado ao dicionário.
			verbo = strtok (NULL," # ");
			//captura o significado do verbete 
			conteudo = strtok (NULL,"#");
			
			//verifica se a arvore está vazia, se sim cria o nó raiz
			if(vazia(dicionario))
			{
				dicionario->Raiz = CriaNo(verbo, conteudo);
			}
			
			//se não chama a função de inserção de nós.
			else
			{
				InsereNo(verbo, conteudo, dicionario->Raiz);
			}
		}
		
		//se comando = 'search' chama a função ProcuraNo que faz a busca na arvore binária
		if (strcmp(comando, search) == 0)
		{
			verbo = strtok (NULL," #");
			verbo[strlen(verbo)-1] = '\0';
			
			//A função Procura nó retorna uma string do significado do verbete
			conteudo = ProcuraNo(verbo, dicionario->Raiz);
			
			//se a função retornar NULL, o verbete não existe no dicionario.
			if (conteudo == NULL)
			{
				Imprime_erros (-5);
			}
			//impime em arquivo o verbete e seu significado
			fprintf(fp_out ,"%s # %s", verbo , conteudo);
		}

		//se comando = 'sort' chama a função ImprimeNo
		/*
		 *	A função recebe como parametro onde irá imprimir
		 */
		comando[strlen(comando)-1] = '\0';
		 
		if (strcmp(comando, sort) == 0)
		{
			ImprimeNo(dicionario->Raiz, fp_dici);
		}
	}
	//Libera a memoria alocada do buffer
	free(buffer);
	
	//função Libera a memoria alocada pelos nós
	FreeNo(dicionario->Raiz);
	
	//Libera a memória alocada pela arvore
	free(dicionario);
	
	//fecha os arquivos de saida
	fclose(fp_in);
	fclose(fp_out);
	fclose(fp_dici);
}

void Imprime_erros(int error)
{
	char e=1;//sair do programa
	switch (error)
	{
		case 0:
		printf("Arquivo de entrada lido!!\n");
		printf("Gerado arquivo de saida!!\n");
		printf("Gerado Arquivo dicionario!!\n");
		printf("APLICACAO TERMINADA!!!\n\n");
		e=0;
		break;

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
		printf("Erro, Arvore nao encotrada.\n\n");
		break;

		case -5:
		printf("Erro, verbete não encotrado no dicionario.\n\n");
		break;

		case -6:
		printf("Erro ao tentar abrir o arquivo de saida.\n\n");
		printf("APLICACAO TERMINADA!!!\n\n");
		break;

		case -7:
		printf("Erro ao tentar abrir o arquivo de dicionário.\n\n");
		printf("APLICACAO TERMINADA!!!\n\n");
		break;
	}
	if(e)exit(1);
}


