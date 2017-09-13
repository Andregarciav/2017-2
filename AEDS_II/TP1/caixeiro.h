typedef struct Coordenadas
{
		int Cidade;
  	int coord_X;
  	int coord_y;
}city;


int *criaCidade(int);
int *PreencheCidades(int, int*);
int *permutaSemRep(int, int*, city*);
void prtvet(int, int*, city*);
void calculaSolucao(int);
