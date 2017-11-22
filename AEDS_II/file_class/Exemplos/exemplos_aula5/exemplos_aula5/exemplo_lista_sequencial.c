#include<stdio.h>

#define InicioArranjo   0
#define MaxTam          1000

typedef int TipoChave;

typedef int Apontador;

typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;

typedef struct {
  TipoItem Item[MaxTam];
  Apontador Primeiro, Ultimo;
} TipoLista;