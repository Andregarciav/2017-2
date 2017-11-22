#include<stdio.h>
#include"lista_encadeada.h"

int main()
{
	TipoLista lista;

	FLVazia(&lista);

	if(Vazia(lista) == 1)
		printf("Lista vazia\n");

	TipoItem x = CriaItem(10);
	TipoItem y = CriaItem(20);

	Insere(x, &lista, retornaUltimoElemento(lista));
	Insere(y, &lista, retornaUltimoElemento(lista));
	imprimeLista(lista);

	return 0;
}