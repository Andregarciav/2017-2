#include <stdio.h>
#include <stdlib.h>
#include "NumeroComplexo.h"

int main() 
{
	NumeroComplexo a,b,c,d;

	a = Inicializa(2,5);
	Imprime(a);
	b = Inicializa(1,2);
	Imprime(b);
	c = Soma(a,b);
	Imprime(c);
	d = Inicializa(5,0);
	Imprime(d);
	if (EhReal(d)) 
		Copia(&d,a);

	Imprime(d);
	return 0;
}