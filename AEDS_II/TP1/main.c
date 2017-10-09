#include <stdio.h>
#include <stdlib.h>
//biblioteca para medir o tempo de execução
#include <time.h>
/*Declaração da biblioteca
 *criada para o problema.
 */
#include "caixeiro.h"

//chamada principal do código
int main(int argc, char **argv){
  //variável que recebe do arquivo o numero de cidades a serem visitadas
	//variaveis para medir o tempo de execução.
	clock_t TempoInicio, TempoFim;
	double TempoDecorrido;
	//int NumeroCidades;
	//int *Cidades;
	char *file;
	file = argv[1];
	//tratamento de erro
	if(argc!=2)
	{
		printf("Erro de Argumentos\n");
		return 0;
	}
	//começa a contar o tempo de execução
	TempoInicio = clock();
	// recebe os dados das cidades do arquivo
	Learquivo(file);
	//termina a temporização
	TempoFim = clock();
	TempoDecorrido = (double)(TempoFim - TempoInicio) / CLOCKS_PER_SEC;
	printf("Tempo decorrido em segundos: %lf.\n", TempoDecorrido);
	TempoDecorrido /= 60;
	printf("Tempo decorrido em minutos: %lf.\n", TempoDecorrido);
	// cria um vetor com as cidades.
	//Cidades = criaCidade(NumeroCidades);
	//Preenche os dados das cidades
	//PreencheCidades(NumeroCidades , Cidades);
	//libera memória de alocação dinâmica
	//free(Cidades);
	return 0;
}
