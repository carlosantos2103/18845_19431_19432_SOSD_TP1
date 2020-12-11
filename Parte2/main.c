#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
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
        count = sscanf(input, "%s %s %s", a1, a2, a3);

    	//f=fork();
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
        	f=fork();
        	if (f == 0) {
        		execl("../Parte1/mostra", "mostra", a2, (char *) NULL );
        		perror("ERRO ao executar ");
        	}
            //result = mostra(count, a2);
        }
        else if (strcmp(a1, "conta") == 0)
        {
            f=fork();
        	if (f == 0) {
        		execl("../Parte1/conta", "conta", a2, (char *) NULL );
        		perror("ERRO ao executar ");
        	}
            //result = conta(count, a2);
        }
        else if (strcmp(a1, "apaga") == 0)
        {
            f=fork();
        	if (f == 0) {
        		execl("../Parte1/apaga", "apaga", a2, (char *) NULL );
        		perror("ERRO ao executar ");
        	}
            //result = apaga(count, a2);
        }
        //TODO: Funcao "informa" tem de ser melhorada
        else if (strcmp(a1, "informa") == 0)
        {
            f=fork();
        	if (f == 0) {
        		execl("../Parte1/informa", "informa", a2, (char *) NULL );
        		perror("ERRO ao executar ");
        	}
            //result = informa(count, a2);
        }
        else if (strcmp(a1, "acrescenta") == 0)
        {
            f=fork();
        	if (f == 0) {
        		execl("../Parte1/acrescenta", "acrescenta", a2, a3, (char *) NULL );
        		perror("ERRO ao executar ");
        	}
            //result = acrescenta(count, a2, a3);
        }
        //TODO: Funcao "lista" tem de ser melhorada
        else if (strcmp(a1, "lista") == 0)
        {            
        	f=fork();
        	if (f == 0) {
        		execl("../Parte1/lista", "lista", a2, (char *) NULL );
        		perror("ERRO ao executar ");
        	}
            //result = lista(count, a2);
        }
        else
        {
            continue;
        }
        wait(NULL);
        //printf("\033[01;33m");
        //TODO: Fix no result que nao esta a returnar
        //printf("\nTerminou o comando %s com codigo %d\n\n", a1, result);
        //printf("\033[0m");
    }
    return 0;
}
