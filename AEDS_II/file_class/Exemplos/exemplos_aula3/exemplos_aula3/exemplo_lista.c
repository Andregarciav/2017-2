#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;


//CRIA UMA LISTA "VAZIA" INDICA COMO PRIMEIRO ELEMENTO COM O VALOR 1
node_t * cria_lista_vazia()
{

	node_t * head = malloc(sizeof(node_t));
	if (head == NULL) {
		printf("Erro ao alocar posicao para a lista");
    	return head;
	}

	head->val = 1;
	head->next = NULL;
	return head;
}

//INSERE UM ELEMENTO NOVO NA LISTA
node_t * insere_lista(int x, node_t ** head)
{
	node_t * atual = *head;
	if(atual->next != NULL)
	{
		while(atual->next!=NULL)
		{	
			atual = atual->next;
		}
	}

	atual->next = malloc(sizeof(node_t));
	if (atual->next == NULL) 
	{
		printf("Erro ao alocar posicao para a lista");
    	return atual->next;
	}
	atual->next->val = x;
	atual->next->next = NULL;

	return atual->next;
}

//IMPRIME OS VALORES DA LISTA
void show_lista(node_t * head)
{
	int count = 1;
	node_t * next = head;
	if(next!=NULL)
	{
		printf("Elemento %d: %d\n",count, next->val );
		count++;
		while(next->next!=NULL)
		{	
			next = next->next;
			printf("Elemento %d: %d\n",count, next->val );
			count++;
			
		}

	}
	else
	{
		printf("lista vazia\n");
	}
}

int main()
{
	node_t * head = NULL;
	head = cria_lista_vazia();
	insere_lista(3, &head);
	show_lista(head);
	return 0;
}
