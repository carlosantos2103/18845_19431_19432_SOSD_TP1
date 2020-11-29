#include <stdlib.h>
#include <stdio.h>
//#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "header.h"

int main(int argc, char *argv[])
{
    system("cls");
    int contador = 0;
    printf("$./interpretador");
    puts("\n");
    while (1)
    {
        if (contador > 0)
        {
            printf("%% ");
            scanf("%s %s",argv[1],argv[2]);
            if (strcmp(argv[1],"exit") == 0)
            {
                exit(0);
            }
        }
        
        if (strcmp(argv[1], "contar") == 0){
            printf("%d", argc);
            conta(argc,argv[2]);
        }else if (strcmp(argv[1], "mostra") == 0)
        {
            mostra(argc,argv[2]);
        }else if (strcmp(argv[1], "apaga") == 0)
        {
            apaga(argc,argv[2]);
        }else if (strcmp(argv[1], "acrescenta") == 0){
            printf("ola entrou\n");
            printf("%s\n",argv[3]);
            acrescenta(argc,argv[2],argv[3]);
        }else
        {
            while (1)
            {
                printf("%% ");
                scanf("%s %s",argv[1],argv[2]);
                if (strcmp(argv[1], "mostra") == 0 || strcmp(argv[1], "contar") == 0
                ||strcmp(argv[1], "apaga") == 0 || strcmp(argv[1], "acrescenta") == 0)
                {
                   contador = -1;
                   break;
                }
            }
        }
        contador++;
    }
    return 0;
}