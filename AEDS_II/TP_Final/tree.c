#include "tree.h"


void Cria_arvore(TipoArvore* arvore)
{
	
	arvore = (TipoArvore*)malloc(sizeof(TipoArvore));

	if (arvore == NULL)
	{
		Imprime_erros(-3);
	}

    arvore->Raiz = NULL;
    
	return;
}


int vazia(TipoArvore* arvore)
{
    return (arvore->Raiz == NULL);
}

TipoNo *CriaNo(char *palavra, char* def)
{
    TipoNo *novo;
    novo = (TipoNo*)malloc(sizeof(TipoNo));
    novo->direita = NULL;
    novo->esquerda = NULL;
    novo->palavra = palavra;
    novo->def = def;
    return novo;
}

void InsereNo(char *palavra, char *def, TipoArvore *arvore)
{   
    int compara = 0;
    
    compara = strcmp(palavra, arvore->Raiz->palavra);
    printf("entrei\n");
    //palavra menor que arvore vai para a esquerda
    if(compara < 0)
    {
        printf("entrei\n");
    }
}