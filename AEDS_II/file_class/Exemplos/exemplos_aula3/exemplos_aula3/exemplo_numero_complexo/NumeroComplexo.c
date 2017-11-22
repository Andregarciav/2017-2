#include <stdio.h>
#include "NumeroComplexo.h"

NumeroComplexo Inicializa(int real, int img) 
{
	NumeroComplexo num;
	num.real = real;
	num.img = img;
	return num;
}

void Imprime(NumeroComplexo num) 
{
	printf("%d + %di\n", num.real, num.img);
}

NumeroComplexo Soma(NumeroComplexo a, NumeroComplexo b) 
{
	NumeroComplexo temp; 
	temp.real = a.real + b.real;
	temp.img = a.img + b.img;
	return temp;
}

int EhReal(NumeroComplexo num) 
{
	return num.img == 0;
}

void Copia(NumeroComplexo *dest, NumeroComplexo src)
{
     dest->real = src.real;
     dest->img = src.img;     
}