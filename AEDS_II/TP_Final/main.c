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

    // copia as strings argv para suas respectivas variáveis
    entrada = argv[1];
    saida = argv[2];
    dicionario = argv[3];

    //chama a função no TAD que tratará o dicionário
    Ler_entrada (entrada , saida, dicionario);

    return 0;
}