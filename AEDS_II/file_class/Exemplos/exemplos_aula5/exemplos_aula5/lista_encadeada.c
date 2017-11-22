#include "lista_encadeada.h"


void FLVazia(TipoLista *Lista)
{
  Lista->Primeiro = (Apontador) malloc(sizeof(Celula));
  Lista->Ultimo = Lista->Primeiro;
  Lista->Primeiro->prox = NULL;
}

int Vazia(TipoLista Lista)
{
  return (Lista.Primeiro == Lista.Ultimo);
}

TipoItem CriaItem(int x)
{
  TipoItem item;
  item.Chave = x;
  return item;
}

void Insere(TipoItem x, TipoLista *lista, Apontador E)
{
  Apontador novo;

  novo = (Apontador) malloc(sizeof(Celula));
  novo->Item = x;
  novo->prox = E->prox;
  E->prox = novo;
  lista->Ultimo = novo;
}

void RemoveProx(TipoLista *lista, Apontador E)
{
  
  Apontador tmp;

  tmp = E->prox;
  if (tmp != NULL) 
  {
    E->prox = tmp->prox;
    free(tmp);
  } 
  else 
  { 
    E->prox = NULL; 
  }
}

Apontador retornaUltimoElemento(TipoLista x)
{
  return x.Ultimo;
}

void imprimeLista(TipoLista x)
{
  Apontador atual = x.Primeiro;
  while(atual != NULL)
  {
    printf("Elemento: %d\n", atual->Item.Chave);
    atual = atual->prox;
  }
}
