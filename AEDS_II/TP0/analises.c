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

//função de gerar a permutação alterar para voltar ao normal
int *permutaSemRep(int a, int *v, city *Map, FILE* saida , FILE* saida1)
{
	int i=1, j, k, z;

	while (i >= 0)
	{
		z = 1;
		i = a-1;
		v[i]++;
		while (i >= 0 && v[i] > a)
		{
			v[i] = 1;
			i--;
			if (i >= 0) v[i]++;

		}
	  for (j=0; j<a-1; j++)
		  for (k=j+1; k<a; k++)
		    if (v[k] == v[j])
        {
          z=0;
          break;
        }


    	if (z) prtvet(a, v, Map, saida , saida1);
	}
  return 0;
}