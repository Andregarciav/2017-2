#define MAX 4096

//struct dicionario
typedef struct dicionario{
	int chave;
	char *palavra;
	char *def;
}dici;

//função que lê o arquivo de entrada.
void Ler_entrada(char*);
//Função para imprimir os erros.
void Imprime_erros(int);

