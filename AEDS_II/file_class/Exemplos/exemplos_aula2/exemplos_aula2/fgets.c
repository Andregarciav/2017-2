#include <stdio.h>

//apresenta um simples exemplo da utilizacao das funcoes gets e fgets

/*
int main() 
{
	char str[10];
	char str2[10];
	char str3[10];

    gets(str);
    gets(str2);
    fgets(str3, 10, stdin);

    printf("str: %s\nstr2: %s\nstr3: %s", str, str2,str3);

    return 0;
}
*/

//exemplo de getchar
int main()
{

	char ret = getchar();
	printf("entrada: %c %d\n", ret, ret);

}