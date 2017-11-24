#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoNo{
	struct TipoNo *direita;
	struct TipoNo *esquerda;
	char *palavra;
	char *def;
}TipoNo;

typedef struct TipoArvore{
    TipoNo *Raiz;
}TipoArvore;

void Cria_arvore(TipoArvore*);

int vazia(TipoArvore*);

TipoNo *CriaNo(char *palavra, char* def);

void Imprime_erros(int);

void InsereNo(char*, char*, TipoNo*);

char *ProcuraNo (char *, TipoNo *);

void ImprimeNo (TipoNo *, FILE*);

void FreeNo(TipoNo *);
