#include <stdlib.h>
#include <stdio.h>
//#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <locale.h>
#include "header.h"

int main(int argc, char *argv[])
{
    system("clear");
    char input[600];
    char a1[12] = "";
    char a2[250] = "";
    char a3[250] = "";
    int count = -1;
    int result = -1;
    
    int f=0;
    while (1)
    {
        printf("%% ");
        fgets(input, 600, stdin);
        int count = sscanf(input, "%s %s %s", a1, a2, a3);

    	//f=fork();
        //printf("%d\n", f);
        if (count <= 0)
        {
            continue;
        }

        if (strcmp(a1, "termina") == 0)
        {
            exit(0);
        }
        if (strcmp(a1, "mostra") == 0)
        {
            result = mostra(count, a2);
        }
        else if (strcmp(a1, "conta") == 0)
        {
            result = conta(count, a2);
        }
        else if (strcmp(a1, "apaga") == 0)
        {
            result = apaga(count, a2);
        }
        //TODO: Funcao "informa" tem de ser melhorada
        else if (strcmp(a1, "informa") == 0)
        {
            result = informa(count, a2);
        }
        else if (strcmp(a1, "acrescenta") == 0)
        {
            result = acrescenta(count, a2, a3);
        }
        //TODO: Funcao "lista" tem de ser melhorada
        else if (strcmp(a1, "lista") == 0)
        {
            result = lista(count, a2);
        }
        else
        {
            continue;
        }
        printf("\033[01;33m");
        printf("Terminou o comando %s com codigo %d\n", a1, result);
        printf("\033[0m");
    }
    return 0;
}
