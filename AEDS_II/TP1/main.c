#include <stdio.h>
#include <stdlib.h>
/*Declaração da biblioteca
 *criada para o problema.
 */
#include "caixeiro.h"

//chamada principal do código
int main(){
  //variável que recebe do arquivo o numero de cidades a serem visitadas
	int NumeroCidades;
	int *Cidades;
	// recebe a quantidade de cidade
	scanf(" %d", &NumeroCidades);
	//calcula o numero de soluluções
	calculaSolucao(NumeroCidades);
	// cria um vetor com as cidades.
	Cidades = criaCidade(NumeroCidades);
	//Preenche os dados das cidades
	PreencheCidades(NumeroCidades , Cidades);
	//libera memória de alocação dinâmica
	free(Cidades);
	return 0;
}
