/* faz lista ficar vazia */
void FLVazia(TipoLista *Lista)
{
  Lista->Primeiro = InicioArranjo;
  Lista->Ultimo = Lista->Primeiro;
}  /* FLVazia */

/* testa se a lista está vazia */
int Vazia(TipoLista *Lista)
{
  return (Lista->Primeiro == Lista->Ultimo);
}  /* Vazia */

void Insere(TipoItem x, TipoLista *Lista)
{
  if (Lista->Ultimo >= MaxTam) 
     printf("Lista esta cheia\n");
  else 
  { 
     Lista->Item[Lista->Ultimo] = x;
     Lista->Ultimo++;
  }
}  /* Insere */

void Insere(TipoItem x, TipoLista *Lista)
{
  if (Lista->Ultimo >= MaxTam) 
     printf("Lista esta cheia\n");
  else 
  { 
     Lista->Item[Lista->Ultimo] = x;
     Lista->Ultimo++;
  }
}  /* Insere */


void Retira(Apontador p, TipoLista *Lista, TipoItem *Item) {
  int Aux;

  if (Vazia(Lista) || p >= Lista->Ultimo) { 
    printf("Erro: Posicao nao existe\n");
    return;
  }
  *Item = Lista->Item[p];
  Lista->Ultimo--;
  for (Aux = p+1; Aux <= Lista->Ultimo; Aux++)
    Lista->Item[Aux - 1] = Lista->Item[Aux];
}


void Imprime(TipoLista *Lista)
{
  Apontador i;

  for (i = Lista->Primeiro; i < Lista->Ultimo; i++)
     
     printf("%d\n", Lista->Item[i].Chave);
}


