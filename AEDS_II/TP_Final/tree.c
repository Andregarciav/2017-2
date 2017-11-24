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
    novo->palavra = (char*)malloc(((strlen(palavra))+1)*sizeof(char));
    novo->def = (char*)malloc(((strlen(def))+1)*sizeof(char));
    
    novo->direita = NULL;
    novo->esquerda = NULL;
    
    strcpy(novo->palavra , palavra);
    strcpy(novo->def , def);
    
    return novo;
}

void InsereNo(char *palavra, char *def, TipoNo *arvore)
{   
    int compara = 0;
    
    compara = strcmp(palavra, arvore->palavra);
    printf("%d compara insere no.\n", compara);
    printf("%s Palavra.\n", palavra);
    printf("%s Palavra na arvore.\n", arvore->palavra);
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
        if ( arvore->direita != NULL )
        {
            InsereNo(palavra, def, arvore->direita);
        }
        else
        {
            TipoNo *novo = CriaNo(palavra, def);
            arvore->direita = novo;
        }
    }

   
}

char *ProcuraNo (char *palavra, TipoNo *arvore)
{
    int compara;
    if (arvore == NULL)
    {
        Imprime_erros(-4);
    }
    printf("%s, %s\n",palavra, arvore->palavra);
    compara = strcmp(palavra, arvore->palavra);
    printf("%d valor compara\n\n", compara);
   
    if (compara < 0)
    {
        return ProcuraNo(palavra, arvore->esquerda);
    }

    else if (compara > 0)
    {
        return ProcuraNo(palavra , arvore->direita);
    }
    else
    {
        return arvore->def;
    }
    return NULL;
}

void ImprimeNo (TipoNo *No, FILE *saida)
{
    if (No->esquerda != NULL)
    {
        ImprimeNo(No->esquerda, saida);
    }
    
    fprintf(saida, "%s # %s\n", No->palavra, No->def);
    
    if (No->direita != NULL)
    {
        ImprimeNo(No->direita, saida);
    }
}

void FreeNo (TipoNo *No)
{
    if (No->esquerda != NULL)
    {
        FreeNo(No->esquerda);
    }
    
    free(No);
    
    if (No->direita != NULL)
    {
        FreeNo(No->direita);
    }
}