#include<stdio.h>
#include<stdlib.h>
#include "conta_bancaria.h"

int main (void) 
{
	ContaBancaria conta1;

    conta1 = Inicializa(918556, 300.00);
    printf("\nAntes da movimentacao:\n ");
    Imprime(conta1);

    Deposito(&conta1, 50.00);
    Saque(&conta1, 70.00);
    printf("\nDepois da movimentacao:\n ");
    Imprime(conta1);
    
    return(0);
}