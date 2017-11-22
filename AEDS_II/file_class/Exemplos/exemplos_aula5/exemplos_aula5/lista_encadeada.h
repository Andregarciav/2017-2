#include<stdio.h>
#include<stdlib.h>

typedef int TipoChave;

typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;

typedef struct Celula_str *Apontador;

typedef struct Celula_str {
  TipoItem Item;
  Apontador prox;
} Celula;

typedef struct {
  Apontador Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista);

int Vazia(TipoLista Lista);

TipoItem CriaItem(TipoChave x);

void Insere(TipoItem x, TipoLista *lista, Apontador E);

void RemoveProx(TipoLista *lista, Apontador E);

Apontador retornaUltimoElemento(TipoLista x);

void imprimeLista(TipoLista x);