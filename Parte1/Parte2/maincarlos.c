#include <stdlib.h>
#include <stdio.h>
//#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "../header.h"

int main(int argc, char *argv[])
{
    system("cls");
    char input[1024];
    char a1[500];
    char a2[500];
    char a3[500];
    int count = -1;
    int result = -1;
    while (1)
    {
        printf("%% ");
        fgets(input, 1024, stdin);
        int count = sscanf(input, "%s %s %s", a1, a2, a3);

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
       /* else if (strcmp(a1, "informa") == 0)
        {
            result = informa(count, a2);
        }*/
        else if (strcmp(a1, "acrescenta") == 0)
        {
            result = acrescenta(count, a2, a3);
        }
        //TODO: Funcao "lista" tem de ser melhorada
        /*else if (strcmp(a1, "lista") == 0)
        {
            result = lista(count, a2);
        }*/
        else
        {
            continue;
        }
        printf("Terminou o comando %s com codigo %d\n", a1, result);
    }
    return 0;
}