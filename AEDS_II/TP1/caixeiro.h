typedef struct Coordenadas
{
		int Cidade;
  	int coord_X;
  	int coord_y;
}city;

#define MAX 20
// vetor que cria as cidades
int *criaCidade(int);
// função que preenche a struct de cidades.
int *PreencheCidades(int, int*);
// função de permutação
int *permutaSemRep(int, int*, city*, FILE*, FILE*);

void prtvet(int, int*, city*, FILE*, FILE*);
double calculaSolucao(int);
//função que lé o arquivo de entrada e gera o de saida
void Learquivo(char*);
//Função que calcula a matriz de adjacencia
double **CriaAdjacencia(int , city *);
//Calcula o caminho
void calculaCaminho ( FILE*, int , double**, FILE* , FILE*);
