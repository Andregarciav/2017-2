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
  for (i=0 ; i < N ; i++)
  {
    Vetorcidades[i] = 1;
  }
  return Vetorcidades;
}

//Calcula a distância entre duas cidades
float calculadistancia(city *Map, int city1, int city2)
{
  float distancia;
  distancia = sqrt(pow((Map[city1-1].coord_X-Map[city2-1].coord_X) , 2) + pow((Map[city1-1].coord_y-Map[city2-1].coord_y) , 2));
  return distancia;
}

//função de gerar a permutação
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

//imprime as coordenadas de cada cidade.
void prtvet(int n, int *v, city *Map , FILE *arq_out , FILE *arq_out1)
{
	int i;
  int j;
	for ( i = 0; i < n; i++)
  {
    j=v[i];
    fprintf(arq_out , "(%d,%d)\t", Map[j-1].coord_X , Map[j-1].coord_y);
    fprintf(arq_out1, "%d ", Map[j-1].Cidade );
  }
	fprintf(arq_out , "\n");
  fprintf(arq_out1, "%d\n", Map[v[0]-1].Cidade);
}

//calcula o numero de soluções e imprime.
double calculaSolucao(int Numsol)
{
  double fat, i;
   fat = 1;
   for (i = 1; i <= Numsol; i++)
   {
     fat = fat * i;
   }
   //printf("%lf\n", fat);
   return fat;
}

// Função de leitura de arquivo e envio de dados para as funções
void Learquivo (char *file)
{
  char buffer[MAX];
  int NumCity , *Cidades, sol;
  double **Matriz;
  FILE *arq = fopen ( file , "r");
  //tratamento de error
  city *Map;
  char saida[30] , saida1[30], saida2[30]; //tem que ser vetor
  if (arq == NULL)
  {
    printf("Erro ao abrir arquivo!!!\n");
    return;
  }
  fgets ( buffer , 3 , arq);
  NumCity = atoi (buffer);
  sol = (int)calculaSolucao(NumCity);
  printf("%d\n", sol);
  Cidades = criaCidade(NumCity);
  Map = (city*)malloc(NumCity*sizeof(city));
  for (i=0 ; i < NumCity ; i++)
  {
    fscanf(arq , "%d %d %d", &Map[i].Cidade , &Map[i].coord_X , &Map[i].coord_y);
  }
  Matriz = CriaAdjacencia(NumCity , Map);
  //copia a string que formará o nome de saída
  sprintf(saida , "instancia_%d_p1.txt", NumCity); //sprintf não aceita ponteiro
  sprintf(saida1 , "instancia_%d_p2.txt", NumCity); //sprintf não aceita ponteiro
  sprintf(saida2 , "instancia_%d_p3.txt", NumCity); //sprintf não aceita ponteiro
  //abre o arquivo de saída
  FILE *arq_out = fopen(saida , "w");
  FILE *arq_out1 = fopen("controle" , "w");
  FILE *arq_out2 = fopen(saida2 , "w");
  //verifica se o arquivo de saída foi aberto
  if (arq_out == NULL || arq_out1 == NULL || arq_out2 == NULL)
  {
    printf("Erro ao criar arquivo de saida");
    return;
  }
  //imprime no arquivo o numero de soluções na primeira linha
  fprintf(arq_out, "%d\n", sol);
  fprintf(arq_out1, "%d\n", sol);
  //chama a função que gera as permutações
  printf("Arquivo %s, criado com sucesso\n\nCalculando Rotas ........\nSalvando em arquivo\n\n", saida);
  permutaSemRep(NumCity , Cidades, Map , arq_out , arq_out1);
  //Fecha o arquivo p1
  fclose(arq_out);
  printf("Arquivo salvo com sucesso.\n\n\n");
  //Fecha o arquivo de controle
  fclose(arq_out1);
  //Abre o arquivo de controle para leitura
  arq_out1 = fopen("controle" , "r");
	//Abre o arquivo de saída como gravação
  arq_out = fopen(saida1 , "w");
  calculaCaminho(arq_out1 ,  NumCity , Matriz, arq_out2 , arq_out);
  fclose(arq_out2);
  free(Map);
  fclose (arq);
}
//Calcula o tamanho do caminho
void calculaCaminho ( FILE *arq_out1,  int NumCity , double **Matriz, FILE* arq_out2, FILE* arq_out)
{
  int j = 0;
  int k = 0;
  int aux = 0;
  int leituras = 0;
  char linha[MAX];
  int *Vetor;
  double acumula = 0;
  double compara = 0;
  compara = calculaSolucao(13);
  Vetor = (int*)malloc(NumCity*sizeof(int));
  fgets(linha , MAX , arq_out1);
  leituras = atoi(linha);
  for (aux = 0 ; aux < leituras ; aux++)
  {
    acumula = 0;
    fgets(linha , MAX , arq_out1);
    Vetor[0] = atoi(strtok(linha, " "));
    if ( linha == NULL ) break;
    for (i=1 ; i < NumCity ; i++)
    {
      Vetor[i] = atoi(strtok(NULL, " "));
    }

    i = 0;
    while(i < NumCity)
    {
      j = Vetor[i];
      k = Vetor[i+1];
      acumula += Matriz[j][k];
      i++;
    }
    if (acumula <= compara)
    {
      compara = acumula;
      for (i = 0 ; i < NumCity ; i++)
      {
          fprintf(arq_out, "%d ", Vetor[i]);
      }
    }
    fprintf(arq_out2, "%lf\n", acumula);
    fprintf(arq_out, "%lf\n", acumula);
  }
  free(Vetor);
}

double **CriaAdjacencia(int NumeroCidades, city *Map)
{
  int i ,  j ;
  double **M = (double**)malloc(NumeroCidades*sizeof(double*));
  for ( i = 1; i <= NumeroCidades; i++)
  {
    M[i]=(double*)malloc(NumeroCidades*sizeof(double));
    for (j = 1; j <= NumeroCidades; j++)
    {
      M[i][j] = calculadistancia(Map , i , j);
    }
  }
  return M;
}
