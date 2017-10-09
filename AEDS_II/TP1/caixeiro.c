#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*Declaração da biblioteca
 *criada para o problema.
 */
#include "caixeiro.h"
//Como sempre é chamado e inicializado a variavel de controle i
//declara i globalmente
int i;

//Cria o vetor com as cidades
int *criaCidade(int N)
{
  int *Vetorcidades;
  Vetorcidades = (int*)malloc(N*sizeof(int));
  for (i=0 ; i < N ; i++){
    Vetorcidades[i] = i+1;
  }
  return Vetorcidades;
}
//Preenche a struct de dados das cidades
/*int *PreencheCidades(int N , int *Vetorcidades)
{
  city *Map;
  Map = (city*)malloc(N*sizeof(city));
  for (i=0 ; i < N ; i++)
  {
    scanf("%d %d %d", &Map[i].Cidade , &Map[i].coord_X , &Map[i].coord_y);
  }
  permutaSemRep(N , Vetorcidades, Map);
  free(Map);
  return 0;
}*/
//Calcula a distância entre duas cidades
float calculadistancia(city *Map, int city1, int city2)
{
  float distancia;
  distancia = sqrt(pow((Map[city1-1].coord_X-Map[city2-1].coord_X) , 2) + pow((Map[city1-1].coord_y-Map[city2-1].coord_y) , 2));
  return distancia;
}
//função de gerar a permutação
int *permutaSemRep(int a, int *v, city *Map)
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

    	if (z) prtvet(a, v, Map);
	}
  return 0;
}
//imprime as coordenadas de cada cidade.
void prtvet(int n, int *v, city *Map)
{
	int i;
  int j;
	for ( i = 0; i < n; i++)
  {
    j=v[i];
    printf("(%d,%d)\t", Map[j-1].coord_X , Map[j-1].coord_y);
  }
	printf("\n");
}

//calcula o numero de soluções e imprime.
int calculaSolucao(int Numsol)
{
  int fat, i;
   fat = 1;
   for (i = 1; i <= Numsol; i++) fat = fat * i;
   printf("%d\n", fat);
   return Numsol;
}

// Função de leitura de arquivo e envio de dados para as funções
void Learquivo (char *file)
{
  char buffer[MAX];
  int NumCity , *Cidades, sol;
  FILE *arq = fopen ( file , "r");
  //tratamento de error
  city *Map;
  if (arq == NULL)
  {
    printf("Erro ao abrir arquivo!!!\n");
    return;
  }
  fgets ( buffer , 3 , arq);
  NumCity = atoi (buffer);
  sol = calculaSolucao(NumCity);
  Cidades = criaCidade(NumCity);
  Map = (city*)malloc(NumCity*sizeof(city));
  for (i=0 ; i < NumCity ; i++)
  {
    fscanf(arq , "%d %d %d", &Map[i].Cidade , &Map[i].coord_X , &Map[i].coord_y);
  }
  permutaSemRep(NumCity , Cidades, Map);
  free(Map);
  fclose (arq);
}
//Calcula o tamanho do caminho
// int calculaCaminho(city *Map, int NumCity, int *VetorDeCidades)
// {
//   int i;
//   for ( i=0 ; i < NumCity ; i++);
// }
