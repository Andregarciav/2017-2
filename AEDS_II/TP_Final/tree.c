#include "tree.h"

//cria a arvore que irá receber os nós
void Cria_arvore(TipoArvore* arvore)
{
    //verifica se o ponteiro para arvore é NULL
	if (arvore == NULL)
	{
		Imprime_erros(-3);
	}

    arvore->Raiz = NULL;
    
	return;
}

// cria a arvore apontando para NULL
int vazia(TipoArvore* arvore)
{
    return (arvore->Raiz == NULL);
}

//função retorna tipo nó e cria um nó com os parametros passados
//recebe o verbete e a definição
TipoNo *CriaNo(char *palavra, char* def)
{
    TipoNo *novo;
    novo = (TipoNo*)malloc(sizeof(TipoNo));
    novo->palavra = (char*)malloc(((strlen(palavra))+1)*sizeof(char));
    novo->def = (char*)malloc(((strlen(def))+1)*sizeof(char));
    
    novo->direita = NULL;
    novo->esquerda = NULL;
    
    //É necessario para copiar o conteudo e não o ponteiro
    strcpy(novo->palavra , palavra);
    strcpy(novo->def , def);
    
    return novo;
}

//função que irá incerir o nó na arvore
void InsereNo(char *palavra, char *def, TipoNo *arvore)
{   
    int compara = 0;
    
    //strcmp retorna maior que 0 se o verbete for maior que o ja existente no nó
    //irá fazendo a comparação até encontrar um nó ná arvore vazio
    //fazendo a inserção por arvore binária, ja fica ordenado, mesmo a arvore
    // ficando desbalanceada
    compara = strcmp(palavra, arvore->palavra);
    
    //palavra menor que arvore vai para a esquerda
    if(compara < 0)
    {
        //caso encontre um nó vazio, insere o nó
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

//função criada para procurar a definição de algum verbete
//retorna a string com a definição do verbete
//caso o verbete não exista retorna null
char *ProcuraNo (char *palavra, TipoNo *arvore)
{
    int compara;
    if (arvore == NULL)
    {
        Imprime_erros(-4);
    }
   
    compara = strcmp(palavra, arvore->palavra);
       
    if (compara < 0)
    {
        return ProcuraNo(palavra, arvore->esquerda);
    }

    else if (compara > 0)
    {
        return ProcuraNo(palavra , arvore->direita);
    }
    
    else if (compara == 0)
    {
        return arvore->def;
    }
    return NULL;
}

//função imprime a arvore de maneira ordenada
void ImprimeNo (TipoNo *No, FILE *saida)
{
    if (No->esquerda != NULL)
    {
        ImprimeNo(No->esquerda, saida);
    }
    
    fprintf(saida, "%s # %s", No->palavra, No->def);
    
    if (No->direita != NULL)
    {
        ImprimeNo(No->direita, saida);
    }
}

//função que libera a memoria alocada para cada nó.
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