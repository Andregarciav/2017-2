#include <stdio.h>

//exemplo de posicionamento de leitura em um arquivo
/*
int main() 
{
	FILE *f;
	char arquivo[] = "printf.c";
	long int pos;
	char str[512];

    f = fopen(arquivo,"r");

    //pega a posicao atual do arquivo
    pos = ftell(f);
    //le no maximo 512 caracteres ou ate encontrar \n ou final de arquivo
    fgets(str, 512, f);
    printf("[posicao: %ld] %s\n", pos, str);

    //"pula" para uma nova posicao de leitura no arquivo
    fseek(f, 10, SEEK_SET);
    pos = ftell(f);
    fgets(str, 512, f);
    printf("[posicao: %ld] %s\n", pos, str);

    fseek(f, -15, SEEK_END);
    pos = ftell(f);
    fgets(str, 512, f);
    printf("[posicao: %ld] %s\n", pos, str);

    fclose(f);

    return 0;
}
*/

//exemplo numerando linhas

int main() 
{
	FILE *f;
	char ch;
	int nlinha = 1;
    f = fopen("printf.c","r");

    printf("%d: ", nlinha++);
	while (!feof(f)) 
	{
        ch = fgetc(f);
        printf("%c", ch);
        if (ch == '\n')
            printf("%d: ", nlinha++);    
    }    
    fclose(f);

    return 0;
}

