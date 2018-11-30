#include <stdio.h>
#include <stdlib.h>
#include "analises.h"

int main()
{
	// declara a struct desenvolvida para o trabalho
	num_in numeros; //struct numeros repetição e sequência
	//Obetendo os  numeros e armazenando na estrutura de dados
	scanf("%d %d", &numeros.rep , &numeros.seq);
	//Testa se os valores inseridos estão dentro dos parametros do problema
	testaNumeros(&numeros.rep , &numeros.seq);
	//Faz a permutação 
	permutaNumeros(&numeros.rep , &numeros.seq);
	return 0;
}
