#include <stdio.h>
#include <stdlib.h>
#include "analises.h"

int main()
{
	num_in numeros;
	scanf("%d %d", &numeros.rep , &numeros.seq);
	testaNumeros(&numeros.rep , &numeros.seq);
	permutaNumeros(&numeros.rep , &numeros.seq);
	return 0;
}
