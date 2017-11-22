#include<stdio.h>
#include<stdlib.h>

int main (void) 
{
	char v[10] = "ola";
	char x[20] = "oi tudo bem";
	x = v;
	printf("%s\n",v);
}