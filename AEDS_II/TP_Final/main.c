#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//biblioteca criada para o TP
#include "dicionario.h"


int main(int argc, char **argv)
{
    //Variáveis dos argumentos!
    char *entrada = NULL;
    char *saida = NULL;
    char *dicionario = NULL;
    //Verifica o numero de argumentos de entrada.
    if(argc != 4)
    {
        Imprime_erros(-1);
    }

    entrada = argv[1];
    saida = argv[2];
    dicionario = argv[3];

    printf("%s , %s , %s\n", entrada , saida, dicionario);
    Ler_entrada (entrada , saida);

    return 0;
}