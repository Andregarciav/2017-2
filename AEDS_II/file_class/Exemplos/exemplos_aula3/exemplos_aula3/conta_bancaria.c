#include<stdio.h>
#include"conta_bancaria.h"

ContaBancaria Inicializa(int numero, double saldo) 
{
	ContaBancaria conta;
	conta.numero = numero;
	conta.saldo = saldo;
	return conta;
}

void Deposito (ContaBancaria *conta, double valor) {
     conta->saldo += valor;
}

void Saque (ContaBancaria *conta, double valor) {
     conta->saldo -= valor;
}

void Imprime (ContaBancaria conta) {
  printf("Numero: %d – saldo: %f\n", conta.numero, conta.saldo);
}