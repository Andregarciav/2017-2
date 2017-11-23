#include "tree.h"


void Cria_arvore(TipoArvore* arvore)
{

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

void InsereNo(char *palavra, char *def, TipoNo *arvore)
{   
    int compara = 0;
    
    compara = strcmp(palavra, arvore->palavra);
    printf("aqui\n");
    //palavra menor que arvore vai para a esquerda
    if(compara < 0)
    {
        if (arvore->esquerda != NULL)
        {
            InsereNo(palavra, def, arvore->esquerda);
        }
        else
        {
            
            TipoNo *novo = CriaNo(palavra, def);
            arvore->esquerda = novo;

        }
    }

    if(compara > 0)
    {
        if (arvore->direita != NULL)
        {
            InsereNo(palavra, def, arvore->direita);
        }
        else
        {
            TipoNo *novo = CriaNo(palavra, def);
            arvore->esquerda = novo;
        }
    }

    if(compara == 0)
    {
        //se Verbete já existe Não faz nada
        return;
    }
}

char *ProcuraNo (char *palavra, TipoNo *arvore)
{
    int compara;
    compara = strcmp(palavra, arvore->palavra);
    if (arvore == NULL)
    {
        Imprime_erros(-4);
    }
    
    else if (compara < 0)
    {
        ProcuraNo(palavra, arvore->esquerda);
    }

    else if (compara > 0)
    {
        ProcuraNo(palavra , arvore->direita);
    }
    else
    {
        return arvore->def;
    }
    return NULL;
}