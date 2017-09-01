#include <stdio.h>
#include <stdlib.h>
#include "analises.h"

void testaNumeros(int *r , int *n){
  int rep, seq;
  rep = *r;
  seq = *n;
  if (rep < 2 || rep > 10){
    printf("[ERRO] argumento de repeticao!\n");
    return;
  }
  if (seq < 1 || seq > 20){
    printf("[ERRO] argumento de sequencia!\n");
    return;
  }
}

void permutaNumeros (int *r , int *n){
  int i;
  for (i = 0 ; i < *r ; i++){
  printf("%d %d\n", i+1 , *n );
  }
}
